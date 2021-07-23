#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int cover_points(vector<int> &A, vector<int> &B)
{
    int steps = 0;
    for(int i = 0; i < A.size()-1; i++)
    {
        if(abs(A[i+1] - A[i]) >= abs(B[i+1] - B[i]))
            steps += abs(A[i+1] - A[i]);
        else
            steps += abs(B[i+1] - B[i]);
    }
    return steps; 
}

int main(int argc, char const *argv[])
{
    vector<int> A = {0, 1, 1};
    vector<int> B = {0, 1, 2};
    cout<<cover_points(A, B);
    return 0;
}
