#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> a = {6, 6, 5, 5, 5, 6, 6};
    int n = a.size();

    int max_len = 0;
    vector<int> LIS_R(n, 1); // longest increasing sub string on the right of the index, including itself
    vector<int> LIS_L(n, 1); // longest increasing sub string on the left of the index, including itself

    for(int i = n-2; i >= 0; i--){
        if(a[i] <= a[i+1]){
            LIS_R[i] = LIS_R[i+1] + 1;
        }
        else LIS_R[i] = 1;
    }

    for(int i = 1; i < n; i++){ 
        if(a[i-1] >= a[i]){
            LIS_L[i] = LIS_L[i-1] + 1;
        }
        else LIS_L[i] = 1;
    }

    for(auto i : LIS_R) cout<<i<<" ";
    cout<<endl;
    for(auto i : LIS_L) cout<<i<<" ";
    cout<<endl;
    for(int i = 0; i < n; i++)
        max_len = max(max_len, LIS_R[i] + LIS_L[i] - 1);

    cout<<max_len<<endl;
    return 0;
}
