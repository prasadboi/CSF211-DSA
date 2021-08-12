#include <iostream>
#include <bits/stdc++.h>

using namespace std;

string addBinary(string A, string B) {
    if(A.size() < B.size()) return addBinary(B, A);
    reverse(A.begin(), A.end());
    reverse(B.begin(), B.end());
    string ans;
    char carry = '0';
    int i;
    for(i = 0; i < B.size(); i++)
    {
        int sum = (A[i] - '0') + (B[i] - '0') + (carry - '0');
        if(sum > 1){
            carry = '1';
            sum = sum - 2;
            ans.push_back(sum + '0');
        }
        else {
            carry = '0';
            ans.push_back(sum + '0');
        }
    }
    while(i < A.size())
    {
        int sum = (carry - '0') + (A[i] - '0');
        if(sum > 1){
            carry = '1';
            sum = sum - 2;
            ans.push_back(sum + '0');
        }
        else {
            carry = '0';
            ans.push_back(sum + '0');
        }
        i++;
    }
    if(carry == '1')
    {
        ans.push_back('1');
    }
    reverse(ans.begin(), ans.end());
    return ans;
    
}


int main()
{
    cout<<addBinary("1000011011000000111100110", "1010110111001101101000")<<endl;
    return 0;
}