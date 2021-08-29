// longest common subarray

#include <bits/stdc++.h>
using namespace std;
int findLength(vector<int> &nums1, vector<int> &nums2)
{
    int m = nums1.size();
    int n = nums2.size();
    int dp[1 + m][1 + n];
    int res = 0;
    for (int i = 0; i < m + 1; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else
            {
                if (nums1[i - 1] == nums2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    res = max(res, dp[i][j]);
                }
                else
                {
                    dp[i][j] = 0;
                }
            }
        }
    }
    return res;
}


int main(int argc, char const *argv[])
{
    vector<int> nums1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int> nums2 = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    int res = findLength(nums1, nums2);
    cout << res << endl;
    return 0;
}
