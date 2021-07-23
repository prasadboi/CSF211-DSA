// https://www.interviewbit.com/problems/diffk/

#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

// check if there are 2 numbers with difference k in the array
bool diff_k_exists(vector<int> &A, int k)
{
    int n = A.size();
    int i = 0, j = 1;
    while(i < j && i<n && j < n)
    {
        int diff = A[j] - A[i];
        if(diff == k)
            return true;
        
        else if(diff < k)   
            j++;
        else 
            i++;

        if(i == j && j < n)
            j++;
    }
    return 0;
}

int main(int argc, char const *argv[])
{
    vector<int> A = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int k = 7;
    cout<<(int)(diff_k_exists(A, k));
    return 0;
}
