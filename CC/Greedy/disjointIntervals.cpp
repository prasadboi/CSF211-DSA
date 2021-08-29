#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

/*
Given a set of N intervals denoted by 2D array A of size N x 2, the task is to find the length of maximal set of mutually disjoint intervals.
Two intervals [x, y] & [p, q] are said to be disjoint if they do not have any point in common.
Return a integer denoting the length of maximal set of mutually disjoint intervals.

Problem Constraints
1 <= N <= 105

1 <= A[i][0] <= A[i][1] <= 10^9
*/

bool compare(vector<int> a,vector<int> b)
{
    return a[1]<b[1];
}

int main(int argc, char const *argv[])
{
    vector<vector<int>> a = {
    {3, 13},
    {7, 7},
    {3, 10},
    {4, 8},
    {7, 8},
    {9, 12},
    {3, 6},
    {7, 12},
    {4, 10},
    {3, 8},
    {5, 11},
    {9, 10},
    {3, 7},
    {4, 4},
    {7, 15},
    {2, 9}
    };
    int n = a.size();
    sort(a.begin(),a.end(),compare);
    int count=1;
    int endpos=a[0][1];
    for(int i=1;i<a.size();i++)
    {
        if(endpos<a[i][0])
        {
            count++;
            endpos=a[i][1];
        }
    }
    cout<<count<<endl;
    
    return 0;
}
