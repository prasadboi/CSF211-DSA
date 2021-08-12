#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int W, L, M, X, Y;
    int num_of_cases = 0;
    cin>>num_of_cases;
    for(int i = 0; i < num_of_cases; i++)
    {
        cin>>W>>L>>M>>X>>Y;
        int strength =  min(M - X, M - Y);
        if(W <= strength) cout<<"JUMP\n";
        else cout<<"FALL\n"   ;
    }
    return 0;
}
