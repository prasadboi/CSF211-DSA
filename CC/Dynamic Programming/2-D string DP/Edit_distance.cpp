#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int editDistance(string A, string B)
{
    int len_A = A.length();
    int len_B = B.length();

    int dp[len_A+1][len_B+1];
    for(int i = 0; i <= len_A; i++)
    {
        for(int j = 0; j <= len_B; j++)
        {
            if(i == 0) dp[i][j] = j;
            else if(j == 0) dp[i][j] = i;

            else if(A[i-1] == B[j-1]) dp[i][j] = dp[i-1][j-1];
            else dp[i][j] = min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]) + 1;
        }
    }
    return dp[len_A][len_B];
}

int main(int argc, char const *argv[])
{
    cout<<editDistance("arjun", "prasad");
    return 0;
}
