#include <iostream>
#include <String>
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

int longestIncPathLength(const vector<vector<int>> &A)
{
    int N = A.size();
    int M = A[N-1].size();

    vector<vector<int>> dp;
    for(int i = 0; i < N; i++)
    {
        vector<int> v(M, 0);
        dp.push_back(v);
    }

    dp[0][0] = 1;
    dp[0][0] = 1;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            if(i == 0 && j == 0) continue;
            if(i)
            {
                if(A[i - 1][j] < A[i][j]) dp[i][j] = (dp[i][j])||(1&&dp[i-1][j]); 
            }
            if(j)
            {
                if(A[i][j - 1] < A[i][j]) dp[i][j] =  dp[i][j]||(1&&dp[i][j-1]);
            }
        }
    }
    print_mat(dp);
    if(dp[N-1][M-1])
        return N+M-1;
    else
        return -1;
}

int main(int argc, char const *argv[])
{
    vector<vector<int>> A = {
    {92, 5, 3, 54, 93, 83, 22, 17, 19, 96, 48, 27, 72, 39, 70, 13, 68},
    {100, 36, 95, 4, 12, 23, 34, 74, 65, 42, 12, 54, 69, 48, 45, 63, 58},
    {38, 60, 24, 42, 30, 79, 17, 36, 91, 43, 89, 7, 41, 43, 65, 49, 47},
    {6, 91, 30, 71, 51, 7, 2, 94, 49, 30, 24, 85, 55, 57, 41, 67, 77},
    {32, 9, 45, 40, 27, 24, 38, 39, 19, 83, 30, 42, 34, 16, 40, 59, 5},
    {31, 78, 7, 74, 87, 22, 46, 25, 73, 71, 30, 78, 74, 98, 13, 87, 91},
    {62, 37, 56, 68, 56, 75, 32, 53, 51, 51, 42, 25, 67, 31, 8, 92, 8},
    {38, 58, 88, 54, 84, 46, 10, 10, 59, 22, 89, 23, 47, 7, 31, 14, 69}
    };
    cout<<longestIncPathLength(A);
    return 0;
}
