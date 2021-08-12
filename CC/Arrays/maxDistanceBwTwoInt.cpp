// find the maximum value of j - i between 2 integers of an array such that A[j] >= A[i]
#include <bits/stdc++.h>
using namespace std;

int maxDist_sol1(vector<int> A){
    int n = A.size();
    int max_dist = 0;
    vector<pair<int, int>> sorted_A(n, {0, -1});
    for (int i = 0; i < n; i++) sorted_A[i] = {A[i], i};
    sort(sorted_A.begin(), sorted_A.end());

    // store the largest index  for a given i such that A[max_idx] >= A[i].
    // ans = max(ans, max_idx - the true index of element i in the sorted arr)
    int ans = 0;
    int max_idx = sorted_A[n-1].second;
    for(int i = n-2; i >= 0; i--)
    {
        ans = max(ans, max_idx - sorted_A[i].second);
        max_idx = max(max_idx, sorted_A[i].second);
    }
    return ans;
}

int maxDist_sol2(vector<int> A){

    int n = A.size();
    
    // create a suffix array such that suffix[i] = maxVal of suffix array of i ie [i+1, n-1]
    vector<int> suffix(n);
    suffix[n-1] = A[n-1];
    for(int i = n-2; i >= 0; i--) suffix[i] = max(suffix[i + 1], A[i]);

    // the given suffix array is in descending order.
    // hence we can use binary search to find the index of the element furthest away from i and greater than A[i]
    int ans = 0;
    for(int i = 0; i < n-1; i++)
    {
        int l = i+1, r = n-1;
        int max_dist = 0;
        while(l <= r){
            int mid = l + (r-l)/2;
            if(suffix[mid] >= A[i]){
                l = mid + 1;
                max_dist = max(max_dist, mid - i);
            }
            else{
                r = mid - 1;
            }
        }
        ans=  max(ans, max_dist);
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    vector<int> A = {3, 5, 4, 2};
    cout << maxDist_sol1(A) << endl;
    cout << maxDist_sol2(A) << endl;
    return 0;
}
