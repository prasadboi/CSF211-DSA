// find first missing POSITIVE integer in an unsorted array
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int findFirstMissingInteger(vector<int> &A) {
    vector<int> dp(A.size() + 1, 0);
    for(int i = 0;  i < A.size(); i++)
    {
        if(A[i] >= 0 && A[i] <= A.size())
        {
            dp[A[i]] = 1;
        }
    }
    for(int i = 1; i < dp.size(); i++)
    {
        if(dp[i] == 0) return i;
    }
    return A.size() + 1;
}

int main(int argc, char const *argv[])
{
    vector<int> A = {-11, -3, 1, 2, 4, 5, 6, 7, 8, 9};
    cout<<findFirstMissingInteger(A)<<endl;
    return 0;
}
