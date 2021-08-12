#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// checks palindromic property of string for only alpha numeric characters and ignores the rest 
bool isPalindrome(string s) {
    int i = 0;
    int j = s.size() - 1;
    while (i < j) {
        if(!isalnum(s[i]) || !isalnum(s[j])) {
        if(i < j && !isalnum(s[i])) i++;
        if(i < j && !isalnum(s[j])) j--;
        }
        else if(tolower(s[i]) != tolower(s[j])) {cout<<s[i]<<" != "<<s[j]<<endl;return false;}
        else{i++; j--;}
    }   
    return true;
}

int main(int argc, char const *argv[])
{
    string A = "A man, a plan, a canal: Panama";
    cout<< isPalindrome(A);
    return 0;
}
