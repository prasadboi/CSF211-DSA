#include <iostream>
#include <String>
#include <bits/stdc++.h>


using namespace std;

long long powmod(int x, int n, int d)
{
    if(x == 0)  return 0;
    if(n == 0) return 1%d; 

    long long temp;
    if(n%2 == 0) 
        temp = (powmod(x, n/2, d)*powmod(x, n/2, d))%d;
    else
        temp = ((x%d)*powmod(x, n-1, d))%d;
    
    return (int)(temp + d)%d;
}

int main(int argc, char const *argv[])
{
    cout<<powmod(71045970, 41535484, 64735492);
    return 0;
}
