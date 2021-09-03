#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

bool subset_with_given_sum(vector<int> &A, int wt)
{
    int N = A.size();
    bool dp[N+1][wt+1];

    // if wt is 0 then simply solution is empty subset;
    for(int i = 0; i <= N; i++) dp[i][0] = true;
    // if arr size is 0 and wt  > 0 then solution does not exist;
    for(int j = 1; j <= wt; j++) dp[0][j] = false;

    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= wt; j++)
        {
            if(A[i-1] <= j) dp[i][j] = dp[i-1][j - A[i-1]] || dp[i-1][j];
            else dp[i][j] = dp[i-1][j]; 
        }
    }
    return dp[N][wt];
}

int count_subset_with_given_sum(vector<int> &A, int wt)
{
    int N = A.size();
    vector<vector<int>> dp(N+1, vector<int>(wt+1, 0));

    for(int i = 0; i <= N; i++) dp[i][0] = 1; // number of subsets with given weight = 0 are 1, for any i element set
    for(int i = 1; i <= wt; i++) dp[0][i] = 0; // numberof subsets with given weight > 0 and number of elements in set = 0, are 0

    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= wt; j++)
        {
            // if current element can be taken in subset
            if(A[i-1] <= j) dp[i][j] = dp[i-1][j-A[i-1]] + dp[i-1][j];
            // if current element is not taken in subset
            else dp[i][j] = dp[i-1][j];
        }
    }
    return dp[N][wt];
}

int main(int argc, char const *argv[])
{
    vector<int> A = {1,2, 3, 3};
    cout<<subset_with_given_sum(A, 6)<<endl;
    cout<<count_subset_with_given_sum(A, 6)<<endl;
    return 0;
}
