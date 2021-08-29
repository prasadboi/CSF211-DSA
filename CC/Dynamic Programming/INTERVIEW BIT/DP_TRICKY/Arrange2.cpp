#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

int helper(int countW[], int countB[], int n)
{
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        ans += countW[i]*countB[i];
    }
    return ans;
}

int arrange(string A, int B)
{
    int N = A.size();
    vector<vector<int>> dp(N + 1, vector<int> (B + 1, INT_MAX/2));
    int countB[B] = {0};
    int countW[B] = {0};
    // if number of horses considered is 0 then no matter how many stables product will be 0
    for(int i = 0; i <= N; i++) dp[0][i] = 0;

    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= B; j++)
        {
            for
        }
    }
    return dp[N][B];
}

int main(int argc, char const *argv[])
{
    string A = "WBWB";
    cout<<arrange(A, 2);
    return 0;
}
