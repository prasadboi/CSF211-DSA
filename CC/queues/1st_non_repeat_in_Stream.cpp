#include <iostream>
#include <String>
#include <bits/stdc++.h>

using namespace std;

string solve(string A)
{
    string res = "";
    queue<char> q;

    unordered_map<int, int> m;

    for(int i = 0; i < A.length(); i++)
    {
        m[A[i] - 'a']++;
        cout<<"A[i]: "<<A[i]<<" ";
        if(m[A[i] - 'a'] > 1)
        {
            cout<<"already exists. "<<"q.front() is: " << q.front()<<endl;
            while((m[q.front() - 'a']>1) && !q.empty())
            {
                cout<<"deleting: "<<q.front()<<endl;
                q.pop();

            }
        }
        else
        {
            q.push(A[i]);
            cout<<"non reapeating char. "<<"q.front() is: " << q.front()<<endl;
        }
        if(!q.empty())
            res.push_back(q.front());
        else
            res.push_back('#');
    }
    return res;
}

int main(int argc, char const *argv[])
{
    string s1 = "abadbc";
    string s2 = "abcabc";
    cout<<solve(s2)<<endl;

    return 0;
}
