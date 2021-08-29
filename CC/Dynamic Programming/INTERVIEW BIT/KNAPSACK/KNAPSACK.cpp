#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

int KNAPSACK(vector<int> &vals, vector<int> &wts, int W)
{
    int N = vals.size();
    vector<vector<int>> dp;
    // for each weight val, each col val indicates the highest score possible upto the nth element
    // base cases : if no of elements considered is 0 then val is 0
    //              if wt restriction is 0 then val is 0
    // since we initialize all elements to 0 ,this is taken care of automatically
    for(int i = 0; i < W + 1; i++)
    {
        vector<int> temp(N+1, 0);
        dp.push_back(temp);
    }

    for(int i = 1; i <= N; i++)
    {
        for(int w = 0; w <= W; w++)
        {
            int curr_item_val = vals[i-1];
            int curr_item_wt = wts[i-1];

            // in case we have the option of choosing the element
            if(w >= curr_item_wt) dp[w][i] = max(dp[w - curr_item_wt][i-1] + curr_item_val , dp[w][i-1]);
            // otherwise ans = solution obtained from all prvs elements
            else dp[w][i] = dp[w][i-1];
        }
    }
    return dp[W][N];
}

int main(int argc, char const *argv[])
{
    vector<int> vals = {60, 100, 120};
    vector<int> wts = {10, 20, 30};
    cout<<KNAPSACK(vals, wts, 50);
    return 0;
}
