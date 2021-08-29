#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

int min_cost_1p(vector<int> cost, vector<int> fill_cap, int eat_cap)
{
    int num_dish = cost.size();
    vector<vector<int>> dp;
    for(int i = 0; i < eat_cap + 1; i++)
    {
        vector<int> v(num_dish+1, INT_MAX);
        dp.push_back(v);
    }
    cout<<"check1"<<endl;
    for(int i = 0; i <= eat_cap; i++)
    {
        cout<<"i : " << i <<" "<< dp[i].size()<<" : ";
        for(int j = 1; j <= num_dish; j++)
        {
            if(i == 0) dp[i][j] = 0;
            else{
                int curr_fill = fill_cap[j-1];
                int curr_cost = cost[j-1];

                if(i%curr_fill == 0)
                {
                    dp[i][j] = min(dp[i - curr_fill][j] + curr_cost, dp[i][j-1]);
                }
                else
                    dp[i][j] = dp[i][j-1];
            }
            cout<<dp[i][j]<<" ";
        } 
        cout<<endl;
    }
    return dp[eat_cap][num_dish];
}

int min_bday_cost(const vector<int> &eat_cap, const vector<int> &fill_cap, const vector<int> &cost)
{
    vector<vector<int>> dp;

    int num_peeps = eat_cap.size();
    int num_dish = fill_cap.size();

    int sum = 0;
    for(int i = 0; i < num_peeps; i++)
    {
        cout<<"eat_cap[i] : "<<eat_cap[i]<<endl;
        sum += min_cost_1p(cost, fill_cap, eat_cap[i]);
        cout<<"sum : "<<sum<<" \n";
    }
    return sum;
}

int main(int argc, char const *argv[])
{
    vector<int> A = {2, 3, 1, 5, 4};
    vector<int> B = {3, 2, 4, 1};
    vector<int> C = {1, 2, 5, 10};
    cout<<min_bday_cost(A, B, C);
    return 0;
}
