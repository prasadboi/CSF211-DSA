#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int LPS(string A)
{
    // this is the same problem as LCS b/w A and reverse(A);
    int len = A.length();
    string B = A;
    reverse(B.begin(), B.end());

    // now this is like LCS problem with A and its flipped version
    int dp[len+1][len+1];
    for(int i = 0; i <= len; i++)
    {
        for(int j = 0; j <= len; j++)
        {
            if(i == 0 || j == 0)
            {
                dp[i][j] = 0;
                continue;
            }

            if(A[i-1] == B[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[len][len];
}

int main(int argc, char const *argv[])
{
    cout<<LPS("prasap");
    return 0;
}
