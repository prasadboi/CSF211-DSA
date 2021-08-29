#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

int longest_inc_subsequence(vector<int> &A)
{
    int n = A.size();
    vector<int> dp(n+1, 1);
    dp[0] = 0;
    int res = 1;
    for(int i = 1; i < n+1; i++)
    {
        for(int j = 1; j < i; j++)
        {
            if(A[i-1] > A[j-1]) dp[i] = max(dp[i], dp[j] + 1);
            res = max(res, dp[i]);
        }
    }
    return res;
}

int main(int argc, char const *argv[])
{
    vector<int> A = {69, 54, 19, 51, 16, 54, 64, 89, 72, 40, 31, 43, 1, 11, 82, 65, 75, 67, 25, 98, 31, 77, 55, 88, 85, 76, 35, 101, 44, 74, 29, 94, 72, 39, 20, 24, 23, 66, 16, 95, 5, 17, 54, 89, 93, 10, 7, 88, 68, 10, 11, 22, 25, 50, 18, 59, 79, 87, 7, 49, 26, 96, 27, 19, 67, 35, 50, 10, 6, 48, 38, 28, 66, 94, 60, 27, 76, 4, 43, 66, 14, 8, 78, 72, 21, 56, 34, 90, 89};
    cout<<longest_inc_subsequence(A)<<endl;
    return 0;
}
