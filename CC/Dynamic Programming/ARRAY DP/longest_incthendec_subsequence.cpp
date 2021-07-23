#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

int longestSubsequenceLength(const vector<int> &A) {
    int n = A.size();
    if(n == 0) return 0;
    vector<int> dp_inc(n, 1), dp_dec(n, 1);

    for(int i=1; i<n; ++i) {
        for(int j=0; j<i; ++j) {
            if(A[j] < A[i]) {
                dp_inc[i] = max(dp_inc[i], dp_inc[j]+1);
            }
        }
    }

    for(int i=n-2; i>=0; --i) {
        for(int j=i+1; j<n; ++j) {
            if(A[i] > A[j]) {
                dp_dec[i] = max(dp_dec[i], dp_dec[j]+1);
            }
        }
    }
    int ans = -1;
    for(int i=0; i<n; ++i) {
        ans = max(ans, dp_dec[i]+dp_inc[i] - 1);
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    vector<int> A = {69, 54, 19, 51, 16, 54, 64, 89, 72, 40, 31, 43, 1, 11, 82, 65, 75, 67, 25, 98, 31, 77, 55, 88, 85, 76, 35, 101, 44, 74, 29, 94, 72, 39, 20, 24, 23, 66, 16, 95, 5, 17, 54, 89, 93, 10, 7, 88, 68, 10, 11, 22, 25, 50, 18, 59, 79, 87, 7, 49, 26, 96, 27, 19, 67, 35, 50, 10, 6, 48, 38, 28, 66, 94, 60, 27, 76, 4, 43, 66, 14, 8, 78, 72, 21, 56, 34, 90, 89};
    cout<<longestSubsequenceLength(A)<<endl;
    return 0;
}
