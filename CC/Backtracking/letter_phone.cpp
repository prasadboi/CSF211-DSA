#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

void get_combo(vector<string> &m,vector<string> &ans, string &A, string &temp, int i)
{
    //cout<<"check, i is : "<<i <<endl;
    if(i >= A.size())
    {
        //cout<<"if called\n";
        if(temp.size() > 0)
            ans.push_back(temp);
        return;
    }

    for(auto j :  m[A[i] - '0'])
    {
        // if we do choose the character
        //cout<<"check, pushed value : "<<m[A[i] - '0'][j]<<endl;
        temp.push_back(j);
        get_combo(m, ans, A, temp, i+1);
        // in case we don't choose the character
        temp.pop_back();
    }
}

vector<string> letterCombinations(string A) {
    vector<string> m;
    m.push_back("0");
    m.push_back("1");
    m.push_back("abc");
    m.push_back("def");
    m.push_back("ghi");
    m.push_back("jkl");
    m.push_back("mno");
    m.push_back("pqrs");
    m.push_back("tuv");
    m.push_back("wxyz");

    vector<string> ans;
    string temp;
    get_combo(m, ans, A, temp, 0);
    return ans;
}

int main(int argc, char const *argv[])
{
    string A = "10";
    //cout<<A.size()<<endl;
    vector<string> res = letterCombinations(A);
    for(auto itr : res)
        cout<<itr<<endl;
    return 0;
}
