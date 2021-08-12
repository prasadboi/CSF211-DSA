#include <bits/stdc++.h>
using namespace std;

int compareVersion(string A, string B) {
    int i, j;
    for(j = 0, i = 0; i < A.size() && j < B.size();)
    {
        //cout<<"i = "<<i<<" j = "<<j<<endl;
        // getting level val of A 
        long long int a = 0;
        int alen = 0;
        int flag = 0;
        while(A[i] != '.' && i < A.size()){
            a = a*10 + (A[i] - '0');
            if(A[i] != '0') flag = 1;
            if(flag == 1) alen++;
            i++;
        }

        // getting level value of B
        long long int b = 0;
        int blen = 0;
        int flag2 = 0;
        while(B[j] != '.' && j < B.size()){
            b = b*10 + (B[j] - '0');
            if(B[j] != '0') flag2 = 1;
            if(flag2 == 1) blen++;
            j++;
        }
        //cout<<"i = "<<i<<" j = "<<j<<endl;
        //cout<<"a = "<<a<<" b = "<<b<<endl;
        if(alen > blen) return 1;
        else if(alen < blen) return -1;
        else if(a > b) return 1;
        else if(a < b) return -1;
        else{i++; j++;}
    }
    
    //cout<<"i = "<<i<<" j = "<<j<<endl;
    if(i < A.size())
    {
        while(i < A.size()){
            int a = 0;
            while(A[i] != '.' && i < A.size())
            {
                a = a*10 + (A[i] - '0');
                i++;
            }
            //cout<<"a = "<<a<<endl;
            if(a != 0) return 1;
        }
    }
    else if(j < B.size())
    {
        while(j < B.size()){
            int b = 0;
            while(B[j] != '.' && j < B.size())
            {
                b = b*10 + (B[j] - '0');
                j++;
            }
            //cout<<"b = "<<b<<endl;
            if(b != 0) return -1;
        }
    }
    return 0;
}


int main(int argc, char const *argv[])
{
    cout<<compareVersion("66682716900046085", "57914818832142");
    return 0;
}
