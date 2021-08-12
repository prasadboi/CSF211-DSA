#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int numSubarraysStartVowel(string s) 
{
    int count = 0;
    for(int i = 0; i < s.size(); i++) 
    {
        s[i] = tolower(s[i]);
        if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
            count += s.size() - i;
        count = (count%10003);
    }
    return count;
}

int main(int argc, char const *argv[])
{
    string A = "abec";
    cout<<numSubarraysStartVowel(A);
    return 0;
}
