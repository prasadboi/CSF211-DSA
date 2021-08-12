#include <bits/stdc++.h>
using namespace std;

bool isVowel(char A)
{
    return A == 'a' || A == 'e' || A == 'i' || A == 'o' || A == 'u';
}

int solve(string A) {
    long long int ctr = 0;
    vector<pair<int, int>> S; // keep track of number of vowels and consonants before and including index i
    if(isVowel(A[0])) S.push_back({1, 0}); else S.push_back({0, 1});
    for(int i = 1; i < A.size(); i++)
    {
        pair<int, int> temp;
        if(isVowel(A[i])) {temp.first = S[i-1].first + 1; temp.second = S[i-1].second; ctr += S[i-1].second;}
        else {temp.first = S[i-1].first; temp.second = S[i-1].second + 1; ctr += S[i-1].first;}
        S.push_back(temp);
        ctr = ctr%1000000007;
    }
    return (int)(ctr%1000000007);
}


int main(int argc, char const *argv[])
{
    string A = "a";
    cout<<solve(A)<<endl;
    return 0;
}
