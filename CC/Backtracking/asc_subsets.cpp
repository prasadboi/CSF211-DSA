#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

// given sorted array return all its subsets in asc internal sorted order
void subset(vector<int> &A, vector<vector<int>> &ans, int idx, vector<int> &temp)
{
    ans.push_back(temp);
    
    for(int i=idx;i<A.size();i++)
    {
        temp.push_back(A[i]);
        subset(A,ans,i+1, temp);
        temp.pop_back();
    }
    return;
}

int main(int argc, char const *argv[])
{
    vector<int> test = {1, 2, 3};
    vector<vector<int>> mat;
    vector<int> temp;

    // enter driver call
    subset(test, mat, 0, temp);

    cout<<mat.size()<<endl;
    for(int i = 0; i < mat.size(); i++)
    {
        for(auto j : mat[i])
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}
