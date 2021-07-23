#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<int> plus_one(vector<int>& digits)
{
    int i = 1;
    while(i <= digits.size())
    {
        digits[digits.end() - i - digits.begin()]++;
        if(digits[digits.end() - i - digits.begin()]/10 == 0)
        {
            break;
        }
        else
        {
            digits[digits.end() - i - digits.begin()] = 0;
        }
        i++;
    }
    if(i > digits.size())
    {
        digits.insert(digits.begin(), 1);
    }
    return digits;
}

int main(int argc, char const *argv[])
{
    vector<int> v;
    int n;
    cin>>n;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        v.push_back(x);
    }

    v = plus_one(v);
    for(vector<int>::iterator iter = v.begin(); iter != v.end(); iter++)
    {
        cout<<*iter;
    }
    return 0;
}
