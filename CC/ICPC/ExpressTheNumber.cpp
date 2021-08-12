#include <bits/stdc++.h>
using namespace std;

void sol(uint32_t n, uint32_t x){
    int k = 0;
    while(n > x)
    {
        //cout<<"k = "<<k<<endl;
        int logN = (int)log2(n);
        if(logN%2 == 1)
        {
            n = n - (1<<(logN));
        }
        else if(logN == 0){cout<<"-1"<<endl; return;}
        else
        {
            n = n - (1<<((logN)-1));
        }
        k++;

    }
    if(n > 0)
        cout<<k+1<<endl;
    else cout<<k<<endl;
}

int main(int argc, char const *argv[])
{
    int t = 0;
    cin>>t;
    for(int i = 0; i < t; i++)
    {
        uint32_t n,x;
        cin>>n>>x;
        sol(n,x);
    }
    return 0;
}
