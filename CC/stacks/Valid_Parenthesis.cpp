// https://leetcode.com/problems/valid-parentheses/

#include <iostream>
#include <string>
#include <bits/stdc++.h>


using namespace std;

bool parentheses_valid(string str)
{
    stack<char> s;
    int flag = 0;
    for(int i = 0; i < str.length(); i++)
    {
        //cout<<"str[i] : "<<str[i]<<endl;
        s.push(str[i]);
        if(s.top() == ')' || s.top() == '}' || s.top() == ']')
        {
            char x = s.top();
            s.pop();
            switch (x)
            {
            case '}':
                if(!s.empty() && s.top() != '{') return false;
                else if(!s.empty()) s.pop();
                else return false;
                break;
            
            case ']': 
                if(!s.empty() && s.top() != '[') return false;
                else if(!s.empty()) s.pop();
                else return false;
                break;

            case ')':
                if(!s.empty() && s.top() != '(') return false;
                else if(!s.empty()) s.pop();
                else return false;
                break;
            default:
                break;
            }
        }
    }
    if(s.empty())
        return true;
    else return false;
}

int main(int argc, char const *argv[])
{
    string s = "]";
    cout<< parentheses_valid(s)<<endl;
    return 0;
}
