#include <bits/stdc++.h>
using namespace std;

string minWindow(string s, string t) {
        // frequency counter
        unordered_map<char, int> m;
        unordered_map<char, int> M;
        
        for(int i = 0; i < t.size(); i++){
            m[t[i]]++;
        }
        
        // expanding window
        int ctr = 0;
        int start = 0;
        int win_size = 0;
        int s_idx = -1;
        int min_window_size = INT_MAX;

        
        for(int i = 0; i < s.length(); i++){
            M[s[i]]++;
            if(m[s[i]] != 0 and M[s[i]] <= m[s[i]]){
                ctr++;
            }
            
            if(ctr == t.length()){
                // all characters have been covered. now contract window
                while(m[s[start]] == 0 or M[s[start]] > m[s[start]]){
                    M[s[start]]--;
                    start++;
                }
                win_size = i - start + 1;
            
                if(win_size < min_window_size){
                    s_idx = start;
                    min_window_size = win_size;
                }
            }

        }
        
        if(s_idx == -1) return "";
        else {
            return s.substr(s_idx, min_window_size);
        }
    }

int main(){
    string A = "ab";
    string B = "b";
    cout<<minWindow(A, B)<<endl;
    return 0;
}