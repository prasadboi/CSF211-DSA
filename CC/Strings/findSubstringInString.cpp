#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int findSubstringInString(string s, string key) {
    int n = s.size();
    int m = key.size();

    if(m == 0) return -1;
    if(n == 0) return -1;
    
    int result = -1;
    for (int i = 0; i <= n - m;) {
        if(s[i] == key[0]) {
            result = i;
            int j = 0;
            while(j < m && i < n){
                if(s[i] != key[j]){
                    result = -1;
                    i = i - j + 1; // imp
                    break;
                } 
                i++;j++;
            }
            if(result != -1) return result;
        }
        else i++;
    }

    return result;
}


// KMP ALGORITHM
// Language: cpp
vector<int> prefix_function(string s)
{
    int n = s.size();
    vector<int> prefix(n);
    for(int i = 1; i < n; i++)
    {
        int j = prefix[i - 1];
        while(j > 0 && s[j] != s[i])
            j = prefix[j - 1];
        if(s[j] == s[i])
            j++;
        prefix[i] = j;
    }
    return prefix;
}

int KMP(string s, string key)
{
    vector<int> prefix = prefix_function(key + "#" + s);
    for(int i = 0; i < prefix.size(); i++){
        if(prefix[i] == key.size()) return (i - (key.size() + 1) - key.size()) + 1;
    }
    return -1;
}

int main(int argc, char const *argv[])
{
    string str1, str2;
    cin >> str1 >> str2;
    cout<<findSubstringInString(str1, str2)<<endl;
    cout<<KMP(str1, str2)<<endl;
    return 0;
}
