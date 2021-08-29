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

int minPathSum(vector<vector<int> > &A) {

    int M = A.size();
    int N = A[M-1].size();
    vector<vector<int>> dp;
    
    for(int i = 0; i < M; i++)
    {
        vector<int> temp(N);
        dp.push_back(temp);
    }

    dp[0][0] = A[0][0];
    for(int i = 0; i < M; i++)
    {
        for(int j = 0; j < N; j++)
        {
            if(i == 0 && j) dp[i][j] = dp[i][j-1] + A[i][j];
            else if(i && j == 0) dp[i][j] = dp[i-1][j] + A[i][j];
            else if(i && j)
                dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + A[i][j];
        }
    }
    return dp[M-1][N-1];
}

int main(int argc, char const *argv[])
{
    vector<vector<int>> A = {{1, 3, 2}, {4, 3, 1},{5, 6, 1}};
    cout<< minPathSum(A);
    return 0;
}
