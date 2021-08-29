#include <iostream>
#include <string>
#include <bits/stdc++.h>


using namespace std;

//https://leetcode.com/problems/triangle/
int triangle_min_path_sum(vector<vector<int>> &triangle)
{
    int h = triangle.size();
    
    vector<vector<int>> dp(h, vector<int>(h, INT_MAX));
        
    dp[0][0] = triangle[0][0];
    for(int i = 0; i < h; i++)
    {
        for(int j = 0; j <= i; j++)
        {
            if(i == 0)
                continue;
            else if(j == 0)
                dp[i][j] = min(dp[i-1][j], INT_MAX) + triangle[i][j];
            else if(j >= i)
                dp[i][j] = min(dp[i-1][j-1], INT_MAX) + triangle[i][j];
            else
                dp[i][j] = min(dp[i-1][j], dp[i-1][j-1]) + triangle[i][j];
            //cout<<"dp["<<i<<"]["<<j<<"] : "<<dp[i][j]<<endl;
        }
    }
    int res = INT_MAX;
    for(int i = 0; i < h; i++)
    {
        res = min(res, dp[h-1][i]);
    }
    return res;
}


int main(int argc, char const *argv[])
{
    
    return 0;
}
