// https://leetcode.com/problems/implement-stack-using-queues/

#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

class MyStack {
public:
    /** Initialize your data structure here. */\
        queue<int> q1;
    queue<int> q2;

    MyStack() {
        while(q1.size()){
            q1.pop();
        }
        while(q2.size()){
            q2.pop();
        }
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        q1.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        if(q1.empty()) return -1;
        while(q1.size() - 1)
        {
            q2.push(q1.front());
            q1.pop();
        }
        int x = q1.front();
        q1.pop();
        queue<int> temp = q1;
        q1 = q2;
        q2 = temp;
        return x;
    }
    
    /** Get the top element. */
    int top() {
        if(q1.empty()) return -1;
        int x;
        while(q1.size() - 1){
            q2.push(q1.front());
            q1.pop();
        }
        x = q1.front();
        q2.push(q1.front());
        q1.pop();
        queue<int> temp = q1;
        q1 = q2;
        q2 = temp;
        return x;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        if(q1.empty()) return true;
        else return false;
    }
};


int main(int argc, char const *argv[])
{
    
    return 0;
}
