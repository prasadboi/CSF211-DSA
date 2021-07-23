#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

void doit(string &A, int moves, string &ans) {
    if(moves == 0) {
        ans = max(ans, A);
        return;
    }
    int n = A.length();
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            swap(A[i], A[j]);
            doit(A, moves-1, ans);
            swap(A[i], A[j]);
        }
    }
}

string solve(string A, int B) {
    string ans = A;
    doit(A, B, ans);
    return ans;
}



int main(int argc, char const *argv[])
{
    string A = "254";
    cout<<solve(A, 1);
    return 0;
}
