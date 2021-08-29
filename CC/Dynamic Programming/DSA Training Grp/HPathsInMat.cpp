#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int countPaths(int H, int W, vector<string> mat){
    vector<vector<int>> dp(H, vector<int>(W, 0));
    dp[0][0] = 1;
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            if(mat[i][j] == '#'){
                dp[i][j] = 0;
            }
            else{
                int t = dp[i][j];
                if(i > 0){
                    t += dp[i-1][j];
                }
                if(j > 0){
                    t += dp[i][j-1];
                }
                dp[i][j] = t%100000007;
                //cout<<dp[i][j]<<" ";
            }
        }
        //cout<<endl;
    }
    return dp[H-1][W-1];
}
int main(int argc, char const *argv[])
{
    int h, w;
    cin>>h>>w;
    vector<string> v(h);
    for(int i = 0; i < h; i++)
    {
        string s;cin>>s;
        v[i] = s;
    }

    cout<<countPaths(h, w, v)<<endl;
    return 0;
}
