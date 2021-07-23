#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<int> slidingMaximum(const vector<int> &A, int B)
{
    vector<int> res;
    deque<int> q_idx;
    q_idx.push_back(0);
    for(int i = 1; i < B && i < A.size(); i++)
    {
        if(A[i] < A[q_idx.back()])
        {
            q_idx.push_back(i);
        }
        else
        {
            while(q_idx.size() && A[q_idx.back()] <= A[i])
            {
                q_idx.pop_back();
            }
            q_idx.push_back(i);
        }
    }

    for(int i = B; i < A.size(); i++)
    {
        res.push_back(A[q_idx.front()]);
        while(q_idx.size() && q_idx.front() < i - B + 1)
        {
            q_idx.pop_front();
        }
        while(q_idx.size() && A[i] >= A[q_idx.back()])
        {
            q_idx.pop_back();
        }
        q_idx.push_back(i);
    }
    res.push_back(A[q_idx.front()]);
    return res;
}

int main(int argc, char const *argv[])
{
    
    return 0;
}
