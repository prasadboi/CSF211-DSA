#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

bool subset_with_given_sum(vector<int> &A, int wt)
{
    int N = A.size();
    bool dp[N+1][wt+1];

    for(int i = 0; i <= N; i++) dp[i][0] = true;
    for(int j = 1; j <= wt; j++) dp[0][j] = false;

    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= wt; j++)
        {
            if(A[i-1] <= j) dp[i][j] = dp[i-1][j - A[i-1]] || dp[i-1][j];
            else dp[i][j] = dp[i-1][j]; 
        }
    }
    return dp[N][wt];
}



int minDiffSubsets(vector<int> &A) {
    int sumA = 0;
    for(auto iter : A) sumA += iter;
    vector<int> sumPossible(sumA+1);
    int x = INT_MAX;
    // diff = S2 - S1 , S1 + S2 = sumA, => S1 = (diff + sumA)/2, simply iterate over all diff possible values from 0 to sumA
    for(int k = 0; k <= sumA; k++)
    {
        int temp = k + sumA;
        if(temp%2 == 0) temp = temp/2;
        else continue;
        if(subset_with_given_sum(A, temp)) return k;
    }
    return sumA;
}



int main(int argc, char const *argv[])
{
    vector<int> A = {1, 2, 3, 4, 5, 6, 5, 686, 2342,123, 123};
    cout<<minDiffSubsets(A);
    return 0;
}
