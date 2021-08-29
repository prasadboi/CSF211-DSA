// Given an array arr[] of N integers arranged in a circular fashion.
// Your task is to find the maximum contiguous subarray sum.
// Input:
// 7
// 8 -8 9 -9 10 -11 12
#include <bits/stdc++.h>
using namespace std;

int KADANE(int arr[], int n)
{
    vector<int> dp(n, 0);
    dp[0] = arr[0];
    int res = INT_MIN;
    res = max(res, dp[0]);
    for(int i = 1; i < n; i++)
    {
        dp[i] = max(dp[i - 1] + arr[i], arr[i]);
        res = max(res, dp[i]);
    }
    return res;
}

int circularSubarraySum(int arr[], int n)
{
    int max_sum = KADANE(arr, n);
    if(max_sum  < 0) return max_sum;

    int wrap_sum = 0;
    for(int i = 0; i < n; i++){
        wrap_sum += arr[i];
        arr[i] *= -1;
    }

    // if corner lies inside the max subarray
    // maxSubarraySum = arrSum - (-KADANE(-arr, n));
    wrap_sum = wrap_sum + KADANE(arr, n);
    return max(max_sum, wrap_sum);
}
int main(int argc, char const *argv[])
{
    int n = 0;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << circularSubarraySum(arr, n) << endl;
    return 0;
}
