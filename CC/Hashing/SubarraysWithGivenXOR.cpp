/*
Problem Description:-
Given an array of integers A and an integer B.
Find the total number of subarrays having bitwise XOR of all elements equals to B.

Problem Constraints
1 <= length of the array <= 105
1 <= A[i], B <= 109


Input Format
The first argument given is the integer array A.
The second argument given is integer B.


Output Format
Return the total number of subarrays having bitwise XOR equals to B.
*/


#include <bits/stdc++.h>

using namespace std;

int countSubarraysWithXOR(vector<int> &A, int B)
{
    int n = A.size();
    int count = 0;

    // first lets create a prefix XOR array
    vector<int> XOR_array(n, 0);
    XOR_array[0] = A[0];
    for(int i = 0; i < n - 1; i++){
        XOR_array[i+1] = XOR_array[i] ^ A[i + 1];
    }

    // A = B^C, then B = A^C
    // store frequency of all the XOR values in a hash map
    unordered_map<int, int> XOR_map;
    for(int i = 0; i < n; i++){
        if(XOR_map.find(B^XOR_array[i]) != XOR_map.end()){
            count += XOR_map[B^XOR_array[i]];
        }
        if(XOR_array[i] == B) count++;
        XOR_map[XOR_array[i]]++;
    }
    return count;
}
 
int main(int argc, char const *argv[])
{
    vector<int> A = {4, 2, 2, 6, 4};
    int B = 6;
    cout<<countSubarraysWithXOR(A, B)<<endl;
    return 0;
}
