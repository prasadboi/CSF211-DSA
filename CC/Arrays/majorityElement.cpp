#include <bits/stdc++.h>
using namespace std;

// Given an array of size n, find the majority element. 
// The majority element is the element that appears more than floor(n/2) times.
// You may assume that the array is non-empty and 
// the majority element always exist in the array.

// Example :

// Input : [2, 1, 2]
// Return  : 2 which occurs 2 times which is greater than 3/2

int main(int argc, char const *argv[])
{
    // using unordered_map to store the frequency of each element
    vector<int> A = {2, 1, 1};
    unordered_map<int, int> m;
    int n = A.size();
    for(int i = 0; i < n; i++){
        if(m.find(A[i]) != m.end()) m[A[i]]++;
        else m[A[i]] = 1;
        if(m[A[i]] > (int)n/2) cout<< A[i];
    }


    // using constant space
    int ctr = 1;
    int curr = A[0];
    int n = A.size();
    
    // given the fact that majority element has freq > n/2, 
    // therefore if we subtract 1 for every non occurence of maj, 
    // the value should still be > 0, If the freq val is < 0 then
    // the element must not be the maj element
    for(int i = 0; i < n; i++){
        if(curr == A[i]) ctr++;
        else ctr--;
        if(ctr == 0){
            curr = A[i];
            ctr = 1;
        }
    }
    return 0;
}
