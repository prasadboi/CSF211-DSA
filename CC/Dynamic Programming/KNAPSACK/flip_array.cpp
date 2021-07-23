#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

void print_mat(vector<vector<int>> &A)
{
    for(int i = 0; i  < A.size(); i++)
    {
        for(int j = 0; j < A[i].size(); j++)
        {
            cout<<A[i][j]<<" ";
        }
        cout<<endl;
    }
}

int num_flips(const vector<int> &A)
{
    int n = A.size();
    long long int S = 0;
    for (int i: A) S += i;
    S = S/2;
    long long int dp[n+1][S+1];

    // initializing base cases
    dp[0][0] = 0;
    for (int i=1; i<=n; i++) dp[i][0] = 0;
    for (int j=1; j<=S; j++) dp[0][j] = INT32_MAX;

    // main algo
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=S; j++) {
            if (A[i-1] <= j) {
                dp[i][j] = min(dp[i-1][j], 1 + dp[i-1][j-A[i-1]]);
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    // in case dp[n][S] is infinity
    if (dp[n][S] == INT32_MAX) {
        for (int j=0; j<=S; j++) {
            if (dp[n][j] < INT32_MAX) dp[n][S] = dp[n][j];
        }
    }
    
    return dp[n][S];
}

int main(int argc, char const *argv[])
{
    vector<int> A = {3, 3, 7, 10, 2, 1, 5, 3, 8, 5, 1, 4, 3, 9, 1, 4, 8, 1, 1, 4, 5, 10, 3, 8, 5, 3, 6, 3, 5, 5, 4, 9, 7, 1, 9, 10, 3, 3, 4, 2, 9, 4, 5, 3, 3, 5, 6, 2, 8, 6, 8, 2, 7, 10, 9, 2, 4, 4, 4, 8, 10, 9, 7, 8, 1, 5, 9, 5, 9, 2, 7, 9, 6, 3, 2, 10, 10, 7, 1, 7, 5, 10, 10, 1, 9, 10, 4, 2, 5, 9, 10};
    cout<<num_flips(A);
    return 0;
}
