#include <bits/stdc++.h>
using namespace std;

int maxSubArray_KADANE(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, 0);
    dp[0] = nums[0];
    int ans = nums[0];
    for(int i = 1; i < n; i++)
    {
        // either we extend the subarray having supposed max sum
        int ext_val = dp[i-1] + nums[i];
        // or we start a new array that contains only 1 element at index i
        int new_sub_val = nums[i];
        dp[i] = max(ext_val, new_sub_val);
        // now dp[i] stores the subarray value that is formed by either extending till or starting at index i
        ans = max(dp[i], ans);
        //cout<<"dp[i] = "<<dp[i]<<endl;
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    vector<int> a = {1, 2, 3, 4, 5, -34, -23, 12, -3, -4 , 2, 0};
    cout<<maxSubArray_KADANE(a);
    return 0;
}
