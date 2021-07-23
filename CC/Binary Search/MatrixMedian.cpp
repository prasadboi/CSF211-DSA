#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;


/*
Given a matrix of integers A of size N x M in which each row is sorted.
Find an return the overall median of the matrix A.
*/

int max_mat(vector<vector<int>> &A)
{
    int max = INT_MIN;
    for(int i = 0; i < A.size(); i++)
    {
        if(max < A[i][A[i].size() - 1])
            max = A[i][A[i].size() - 1];
    }
    return max;
}

int min_mat(vector<vector<int>> &A)
{
    int min = INT_MAX;
    for(int i = 0; i < A.size(); i++)
    {
        if(min > A[i][0])
            min = A[i][0];
    }
    return min;
}

// function to count number of elements less than the given key
int count_less_than(vector<vector<int>> &A, int key)
{
    int ctr = 0;
    for(int i = 0; i < A.size(); i++)
    {
        ctr += (upper_bound(A[i].begin(), A[i].end(), key) - A[i].begin());
    }
    return ctr;
}

int median_of_mat(vector<vector<int>> &A)
{
    if(A.size() == 0) return INT_MIN;

    int low = min_mat(A);
    int high = max_mat(A);
    int N = A.size();
    int M = A[0].size();
    while(low < high)
    {
        int mid = low + (high - low)/2;
        int num = count_less_than(A, mid);
        if(num <= (N*M)/2)
            low = mid+1;
        else
            high = mid;
    }
    return low;
}


int main(int argc, char const *argv[])
{
    vector<vector<int>> A = {{1, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3}};
    cout<<median_of_mat(A);
    return 0;
}
