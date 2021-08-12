#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

// Problem statement : https://atcoder.jp/contests/dp/tasks/dp_b


int main(int argc, char const *argv[])
{
    int n, k;
    cin>>n>>k;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    
    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;
    dp[1] = 0;
    for(int i=2; i<=n; i++){
        for(int j = 1; j <= k; j++){
            if(j < i){
                //cout<<"dp["<<i<<"] = "<<"min(dp[i], "<<dp[i-j] + abs(arr[i-1] - arr[i-j - 1])<<") = ";
                dp[i] = min(dp[i], dp[i-j] + abs(arr[i-1] - arr[i-j - 1]));
                //cout<<dp[i]<<endl;
            }
        }
    }
    cout<<dp[n];
    return 0;
}
