#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

int maxProduct(const vector<int> &A) {
    int n = A.size();

    // dp or BRUTE force solution  = O(n^2)
    /*
    vector<int> dp(n, INT_MIN);
    for(int i = 0; i < n;  i++)
    {
        int x = 1;
        for(int j = i; j >= 0; j--)
        {
            x = x*A[j];
            dp[i] = max(dp[i], x);
        }
        //cout<<"dp["<<i<<"] = "<<dp[i]<<endl;
    }

    int ans = INT_MIN;
    for(int i = 0; i < n; i++) ans = max(dp[i], ans);
    return ans;*/

    // O(n) solution
    int ans = INT_MIN;
    int min_i = A[0];
    int max_i = A[0];
    for(int i = 1; i < n;  i++)
    {
        int temp = max_i;
        max_i = max(A[i], max(max_i*A[i], min_i*A[i]));
        min_i = min(A[i], min(min_i*A[i], temp*A[i]));
        ans = max(max_i, ans);
    }
    return max(ans, max_i);
}


int main(int argc, char const *argv[])
{
    vector<int> A = {-10, 10, -10, 10};
    cout<<maxProduct(A);
    return 0;
}
