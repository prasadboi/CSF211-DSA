#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    vector<int> v(n+1);
    v[0] = 1;
    v[1] = 1;
    for(int i = 2; i < n+1; i++)
    {
        v[i] = v[i-1]  +v[i-2];
    }
    cout<<v[n];
    return 0;
}
