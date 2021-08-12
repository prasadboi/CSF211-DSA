#include <bits/stdc++.h>
using namespace std;

string rev_word_order_in_str(string A) {
    string ans;
    int space_ctr = 0;
    int n = A.size();

    // first remove all leading and trailing spaces
    for(int i = 0; i < n; i++){if(A[i] != ' ') break; else{A.erase(A.begin()); i--;}}
    for(int j = n-1; j >= 0; j--){if(A[j] != ' ') break; else{A.erase(A.begin() + j); j++;}}

    // remove extra whitespaces in b/w words
    for(int i = 0; i < n; i++){
        if(A[i] == ' ' && space_ctr > 0){A.erase(A.begin() + i); i--; space_ctr++;}
        else if(A[i] == ' ' && space_ctr == 0){space_ctr++;}
        else space_ctr = 0;
    }
    // at every stage simply insert the word at the begininning
    int w_start = 0; int w_end = 0;
    for(int i = 0; i < n; i++)
    {
        if(A[i] == ' '){
            w_end = i - 1;
            int len = w_end - w_start + 1;
            ans = A.substr(w_start, len) + " " + ans;
            w_start = i + 1;
        }
    }
    int len = n - w_start + 1;
    ans = A.substr(w_start, len) + " " + ans;
    return ans;
}

int main(int argc, char const *argv[])
{
    string A = "   Hello    WorLd          i";
    cout<<A<<endl<<rev_word_order_in_str(A)<<endl;
    return 0;
}
