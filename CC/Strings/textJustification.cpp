#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<string> TextJustify(vector<string> words, int L) {
    vector<string> res;
    for(int i = 0, k, l; i < words.size(); i += k) 
    {
        for(k = l = 0; i + k < words.size() && l + words[i+k].size() <= L - k; k++) {
            l += words[i+k].size();
        }
    
        string tmp = words[i];
        
        for(int j = 0; j < k - 1; j++) {
            if(i + k >= words.size()) tmp += " ";
            else tmp += string((L - l) / (k - 1) + (j < (L - l) % (k - 1)), ' ');
            tmp += words[i+j+1];
        }
        
        tmp += string(L - tmp.size(), ' ');
        res.push_back(tmp);
    }
    
    return res;
}

int main(int argc, char const *argv[])
{
    vector<string> v = {"THIS", "is", "an", "example", "of", "text", "justification"};
    vector<string> ans = TextJustify(v, 16);
    for(auto i : ans){cout<<i<<endl;}
    return 0;
}
