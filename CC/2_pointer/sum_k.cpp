#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

// check if there exists a subarray of sum k
bool sum_k_exists(vector<int> &A, int k)
{
    // creating prefix sum array
    for(int i = 1; i < A.size(); i++)
    {
        A[i] = A[i] + A[i-1];
    }
    A.insert(A.begin(), 0);

    // now it is just the same as the diff k problem
    int j = 1, i = 0;
    while(i < j && j < A.size() && i < A.size())
    {
        int diff = A[j] - A[i];
        if(diff == k)   
            return true;

        else if(diff < k)
            j++;
        else 
            i++;

        // what if we come to a window of size 0 (not allowed) and we still havent taken all cases into consideration?
        // simply go back to a base case type relationship starting at index i
        if(i == j && j < A.size())
            j++;
    }
    return false;
}

int main(int argc, char const *argv[])
{
    vector<int> A = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int k = 7;
    cout<<(int)(sum_k_exists(A, k));
    return 0;
}
