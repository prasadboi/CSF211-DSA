#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// function to check if a number is power of 2
// number is string

int divideBy2(string &num){
    int rem = 0;
    cout<<"num = "<<num<<endl;
    for(int i = 0; i < num.size(); i++){
        cout<<rem * 10 + num[i] - '0'<<" ";
        int x = num[i] - '0';
        num[i] = (rem * 10 + (num[i] - '0'))/2 + '0';
        rem = (rem * 10 + x)%2;
        cout<<num[i]<<rem<<endl;
    }
    for(int i = 0; i < num.size(); i++){
        if(num[i] != '0'){
            break;
        }
        num.erase(num.begin() + i);
        i--;
    }
    cout<<"new num = "<<num<<endl;
    return rem;
}

bool isPowerOf2(string A) {
    if((A[A.size() - 1] - '0')%2 == 1) return 0;
    while(A.size() > 1)
    {
        int x = divideBy2(A);
        if(x == 1) return 0;
    }
    cout<<"A : "<<A<<endl;
    if(A[0]== '8' || A[0] == '4' || A[0] == '2' || A[0] == '1') return 1;
    else return 0;
}

int main(int argc, char const *argv[])
{
    string A = "00000128";
    cout<<divideBy2(A)<<endl;
    cout<<isPowerOf2(A)<<endl;
    return 0;
}
