// https://www.interviewbit.com/courses/programming/topics/backtracking/

#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

void PERMUTE(vector<int> &A, vector<vector<int>> &ans, int i)
{
    if(i == A.size() - 1)
    {
        ans.push_back(A);
        return;
    }
    for(int j = i; j < A.size(); j++)
    {
        swap(A[i], A[j]);
        PERMUTE(A, ans, i+1);
        swap(A[j], A[i]);
    }
}

int main(int argc, char const *argv[])
{
    vector<int> test = {1, 2, 3};
    vector<vector<int>> mat;

    PERMUTE(test, mat, 0);
    cout<<mat.size()<<endl;
    for(int i = 0; i < mat.size(); i++)
    {
        for(auto j : mat[i])
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }
    string str;
    for(auto itr:mat[4])
        str.push_back(itr + '0');
    cout<<str;
    return 0;
}
