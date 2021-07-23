// https://www.interviewbit.com/problems/rain-water-trapped/

#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

int water_trapped(const vector<int> &A)
{
    stack<int> s;
    int netvol = 0;
    s.push(A[0]);
    for(int i = 1; i < A.size(); i++)
    {
        while(!s.empty() && A[s.top()] < A[i])
        {
            // A[i] is the nearest element to the right that is >= A[s.top()]
        }
    }
    return netvol;
}

int main(int argc, char const *argv[])
{
    vector<int> A = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout<<water_trapped(A);
    return 0;
}
