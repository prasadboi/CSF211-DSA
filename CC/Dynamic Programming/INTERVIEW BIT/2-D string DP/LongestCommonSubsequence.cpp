#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int LCS(string A, string B) {
    int len_A = A.length();
    int len_B = B.length();
    int dp[len_A + 1][len_B + 1];
    for(int i = 0; i <= len_A; i++)
    {
        for(int j = 0; j <= len_B; j++)
        {
            if(i == 0 || j == 0)
            {
                // base case
                // in case either string is of length 0 then LCS = 0;
                dp[i][j] = 0;
                continue;
            }

            // general case
            // if the end of the 2 strings of length i and j match then LCS(A[:i], B[:j]) = LCS(A[:i-1], B[:j-1]) + 1
            if(A[i-1] == B[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else// LCS(A[:i], B[:j]) = max(LCS(A[:i-1], B[:j]), LCS(A[:i], B[:j-1]))
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[len_A][len_B];
}

int main(int argc, char const *argv[])
{
    cout<<LCS("arjun", "a1r2j3u4n5def");
    return 0;
}
