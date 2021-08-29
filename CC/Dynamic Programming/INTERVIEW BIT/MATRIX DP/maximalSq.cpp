#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

//https://leetcode.com/problems/maximal-square/
// given mxn matrix of 1s and 0s find maximum square consisting of only 1s and return its area

int maximalSquare(vector<vector<char>>& matrix) {
        int h = matrix.size();
    int b = matrix[0].size();
    int sq_max = min(h, b);
    vector<vector<int>> dp(h, vector<int> (b, 0));

// base cases---------------------------------------------------------------------------------

    if(h == 1 || b == 1)
    {
        for(int i = 0; i < h; i++)
            if(matrix[i][0] == '1') return 1;
        for(int j = 0; j < b; j++)
            if(matrix[0][j] == '1') return 1;
        return 0;
    }

    for(int i = 0; i < h; i++)
        if(matrix[i][0] == '1') dp[i][0] = 1;
    for(int j = 0; j < b; j++)
        if(matrix[0][j] == '1') dp[0][j] = 1;
//----------------------------------------------------------------------------------------------------

// main prog---------------------------------------------------------------------------------------------
    for(int i = 1; i < h; i++)
    {
        for(int j = 1; j < b; j++)
        {
            int side = sqrt(max(max(dp[i-1][j-1], dp[i][j-1]), dp[i-1][j]));
            if(matrix[i][j])
            {
                dp[i][j] = 1;
                bool flag = true;
                if(side > i || side > j) flag = false;
                else{
                    for(int x = 0; x < side + 1; x++)
                    {
                        for(int y = 0; y < side + 1; y++)
                        {
                            if(matrix[i-x][j-y] == '0') flag = false;
                        }
                    }
                }
                if(flag)
                    dp[i][j] = (side+1)*(side +1);
                else
                    dp[i][j] = side*side;
            }
            else
                dp[i][j] = side*side;
        }
    }
    return dp[h-1][b-1];
//----------------------------------------------------------------------------------------------------
}

int main(int argc, char const *argv[])
{
    vector<vector<char>> mat = {{'1','0','1','0','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'}};
    cout<<maximalSquare(mat)<<endl;
    return 0;
}
