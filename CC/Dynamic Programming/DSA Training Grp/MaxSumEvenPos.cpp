// https://codeforces.com/contest/1373/problem/D

/*
You are given an array a consisting of n integers. 
Indices of the array start from zero 
(i. e. the first element is a0, the second one is a1, and so on).
You can reverse at most one subarray (continuous subsegment) of this array. 
Recall that the subarray of a with borders l and r is a[l:r]=al,al+1,…,ar.
Your task is to reverse such a subarray that the sum of elements on even positions of the resulting array is maximized 
(i.e. the sum of elements a0,a2,…,a2k for integer k=⌊n−12⌋ should be maximum possible).
You have to answer t independent test cases.

INPUT : 

The first line of the input contains one integer t (1≤t≤2⋅104) — the number of test cases. 
Then t test cases follow.
The first line of the test case contains one integer n (1≤n≤2⋅105) — the length of a. 
The second line of the test case contains n integers a0,a1,…,an−1 (1≤ai≤109), 
where ai is the i-th element of a.
It is guaranteed that the sum of n does not exceed 2⋅105 (∑n≤2⋅105).

OUTPUT : 
For each test case, print the answer on the separate line — 
the maximum possible sum of elements on even positions after reversing at most one subarray (continuous subsegment) of a.
*/


#include <bits/stdc++.h>
using namespace std;

int maxSumEvenPos(vector<int> &a, int n) {
    // if array length is odd then flipping array changes the sum of even positions
    // if array length is even then flipping array changes the sum of odd positions

    int maxEvenSum = INT_MIN;
    vector<int> odd_prefix(n, 0);
    vector<int> even_prefix(n, 0);
    vector<vector<long long>> dp(n + 1, vector<long long>(3));
		for (int i = 0; i < n; ++i) {
			dp[i + 1][0] = max(dp[i + 1][0], dp[i][0] + (i & 1 ? 0 : a[i]));
			if (i + 2 <= n) dp[i + 2][1] = max(dp[i + 2][1], max(dp[i][0], dp[i][1]) + (i & 1 ? a[i] : a[i + 1]));
			dp[i + 1][2] = max(dp[i + 1][2], max({dp[i][0], dp[i][1], dp[i][2]}) + (i & 1 ? 0 : a[i]));
		}
		return max({dp[n][0], dp[n][1], dp[n][2]});

}

int main(int argc, char const *argv[])
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }

        int ans = maxSumEvenPos(a, n);
        cout<<ans<<endl;
    }
    return 0;
}
