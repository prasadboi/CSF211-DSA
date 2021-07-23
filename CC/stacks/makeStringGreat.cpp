// https://leetcode.com/problems/make-the-string-great/

#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>


using namespace std;

string makeStringGood(string str)
{
    stack<char> s;
    for(int i = 0; i < str.length(); i++)
    {
        if(s.empty())
            s.push(str[i]);
        
        else if(abs((int)(s.top() - str[i])) == (97 - 65))
            s.pop();
            else
                s.push(str[i]);
    }

    str.clear();
    while(s.size())
    {
        str.push_back(s.top());
        s.pop();
    }
    reverse(str.begin(), str.end());
    return str;
}

int main(int argc, char const *argv[])
{
    cout<<makeStringGood("leEeetcode");
    return 0;
}
