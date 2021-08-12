#include <bits/stdc++.h>
using namespace std;

int countNumInsertionReq(string s) {
    int n = s.size();
    for(int i = n - 1, j = 0; i >= 0 && i >= j;) {
        if(s[i] != s[j]) {i--;}
        else {
            //cout<<"i = "<<i<<", j = "<<j<<endl;
            int t = i;
            while(t >= j && s[t] == s[j]) {t--;j++;}
            if(t < j){// palindrome achieved
                if(i == n-1) return 0; else return n - i - 1;
            }
            else {i--;j = 0;}
        }
    }
    return n;
}

int main(int argc, char const *argv[])
{
    string A = "AAAAAAA";
    cout<<countNumInsertionReq(A)<<endl;
    return 0;
}
