/*
Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.
A subarray is a contiguous part of an array.

Constraints:

1 <= nums.length <= 3 * 104
-105 <= nums[i] <= 105
 

Follow up: If you have figured out the O(n) solution,
try coding another solution using the divide and conquer approach, which is more subtle.
*/


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> nums = {1, -2,3,-4,5,6,7,-8,9, -10};
    int sum = INT_MIN;
    vector<int> dp(nums.size() + 1, 0);
    for(int i = 1;  i <= nums.size(); i++){
        // at every stage we can either decide to extend the previous subarray or start a subarray at index i
        dp[i] = max(dp[i-1] + nums[i-1], nums[i-1]);
        sum = max(sum, dp[i]);
    }
    cout << sum << endl;
    return 0;
}
