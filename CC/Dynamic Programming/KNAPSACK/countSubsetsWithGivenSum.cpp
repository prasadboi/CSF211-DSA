#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

int count_subset_with_given_sum(vector<int> &A, int wt)
{
    int N = A.size();
    int dp[N+1][wt+1];

    // if wt is 0 then simply solution is empty subset;
    for(int i = 0; i <= N; i++) dp[i][0] = 1;
    // if arr size is 0 and wt  > 0 then solution does not exist
    for(int j = 1; j <= wt; j++) dp[0][j] = 0;

    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= wt; j++)
        {
            if(A[i-1] <= j) dp[i][j] = dp[i-1][j - A[i-1]] + dp[i-1][j];
            else dp[i][j] = dp[i-1][j]; 
        }
    }
    return dp[N][wt];
}

int main(int argc, char const *argv[])
{
    vector<int> A = {1,2, 3, 4, 5, 6};
    cout<<count_subset_with_given_sum(A, 6);
    return 0;
}
