#include <iostream>
#include <bits/stdc++.h>
using namespace std;

string solve(string &A, int B) 
{
    int ctr = 1;
    for(int i = 0; i < A.size(); i++)
    {
        if(A[i] == A[i-1]) ctr++;
        else ctr = 1;
        if(ctr == B) {A.erase(A.begin() + i - B + 1, A.begin() + i + 1); i -= B;}
    }
    return A;
}


int main(int argc, char const *argv[])
{
    string A = "aabcabbcabcc";
    solve(A, 2);
    cout << A << endl;
    return 0;
}
