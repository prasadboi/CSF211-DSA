// https://leetcode.com/problems/min-stack/

#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

class MinStack
{
    // use 2 stacks one which stores the latest min and the other is the normie stack
    stack<int> s1; // normie stack
    stack<int> s2; // stores minimums

    public:
    void push(int x)
    {
        s1.push(x);
        if(s2.empty())
            s2.push(x);
        else if(s2.top() > x)
            s2.push(x);
    }

    void pop()
    {
        if(s1.top() == s2.top())
        {
            s2.pop();
        }
        s1.pop();
    }

    int top()
    {
        if(s1.empty()) return -1;
        s1.top();
    }

    int getMin()
    {
        if(s2.empty()) return -1;
        return s2.top();
    }

};

int main(int argc, char const *argv[])
{
    
    return 0;
}
