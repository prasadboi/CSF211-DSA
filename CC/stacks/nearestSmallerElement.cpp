// https://www.interviewbit.com/problems/nearest-smaller-element/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<int> prevSmaller(vector<int> &A)
{
    vector<int> smol;
    stack<int> s;

    for(int i = 0; i < A.size(); i++)
    {
        
        int x = -1;
        while(!s.empty())
        {
            if(s.top() >= A[i])
            {
                s.pop();
            }
            else{
                x = s.top();
                break;
            }
        }
        s.push(A[i]);
        smol.push_back(x);
    }
    return smol;
}

int main(int argc, char const *argv[])
{
    vector<int> A = {39, 27, 11, 4, 24, 32, 32, 1};
    vector<int> B = prevSmaller(A);
    for(auto i : B)
    {
        cout<<i<<" ";
    }

    return 0;
}
