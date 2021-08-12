#include <bits/stdc++.h>
using namespace std;

// DP solution.
string longestPalindrome_DP(string s) {
if(s.size()==0) return "";
        int i = 0, j = 0;
        int n = s.size();

        //initialize P[n][n], we only need half of P, and initialize it like: (e.g. : s="abbc")
        bool P[n][n]={false};
        for(int x = 0;x<n;x++){
            P[x][x]=true;
            if(x==n-1) break;
            P[x][x+1] = (s[x]==s[x+1]);
        }
        //dp 
        for(int i = n-3; i>=0; --i){
            for(int j = i+2;j<n; ++j){
                P[i][j] = (P[i+1][j-1] && s[i]==s[j]);     
            }
        }


        //get maxstr result
        int max = 0;
        string maxstr = "";
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(P[i][j]==true and j-i+1>max){
                    max = j-i+1;
                    maxstr = s.substr(i,j-i+1);
                }
            }
        }

        return maxstr;
}

string longestPalindrome_expanding(string s){
    if (s.size() < 2)
        return s;
    int len = s.size(), max_left = 0, max_len = 1, left, right;

    for (int start = 0; start < len && len - start > max_len / 2;) {
        left = right = start;
        while (right < len - 1 && s[right + 1] == s[right]) // going through all duplicate characters
            ++right;
        start = right + 1;
        while (right < len - 1 && left > 0 && s[right + 1] == s[left - 1]) { // expanding around the center
            ++right;
            --left;
        }
        if (max_len < right - left + 1) {
            max_left = left;
            max_len = right - left + 1;
        }
    }
    return s.substr(max_left, max_len);
}

int main(int argc, char const *argv[])
{
    string s;
    cin>>s;
    return 0;
}
