#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

void combo_sum_sets1(vector<int> &A, vector<vector<int>> &ans, vector<int> &temp, int sum)
{
    if(sum == 0)
    {
        ans.push_back(temp);
        return;
    }
    for(int i = 0; i < A.size(); i++)
    {
        //cout<<"A[i] : "<<A[i]<<endl;
        if(A[i] <= sum )
        {
            if(!temp.empty())
            {
                if(temp.back() <= A[i])
                {
                    temp.push_back(A[i]);
                    combo_sum_sets1(A, ans, temp, sum - A[i]);
                    temp.pop_back();
                }
            }
            else
            {
                temp.push_back(A[i]);
                combo_sum_sets1(A, ans, temp, sum - A[i]);
                temp.pop_back();
            }
        }
        else break;
    }
}

void combo_sum_sets2(vector<int> &A, vector<vector<int>> &ans, vector<int> &temp, int i, int sum)
{
    if(sum == 0)
    {
        ans.push_back(temp);
    }

    for(int j = i; j < A.size(); j++)
    {
        //cout<<"A[j] : "<<A[j]<<endl;
        if(A[j] <= sum)
        {
            temp.push_back(A[j]);
            combo_sum_sets2(A, ans, temp, i+1, sum - A[j]);
            temp.pop_back();
        }
    }
}

int main(int argc, char const *argv[])
{
    vector<int> test = {1, 2, 4, 5, 6};
    vector<vector<int>> mat;
    vector<int> temp;


    combo_sum_sets2(test, mat, temp, 0, 9);
    

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
