#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int wt;
    cin>>wt;
    if(wt <= 2)
    {
        cout<<"NO";
    }
    else
    {
        if(wt%2 == 0)
        {
            cout<<"YES";
        }
        else if(wt%2 == 1)
        {
            cout<<"NO";
        }
    }
    
    return 0;
}
