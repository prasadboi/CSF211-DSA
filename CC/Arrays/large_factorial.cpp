#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

void print_array(vector<int> A)
{
    cout<<"------------------------------------"<<endl;
    for(int i = 0; i < A.size(); i++){
        cout<<A[i]<<" ";
    }
    cout<<endl<<"--------------------------------------"<<endl;
}

void multiply(int A, vector<int> &B)
{
    int carry = 0;

    for(int i = B.size() - 1; i >= 0; i--)
    {
        int x = B[i]*A + carry;
        B[i] = x%10;
        carry = x/10;
    }
    if(carry != 0)
    {
        B.insert(B.begin(), carry);
    }
    return ;
}

string factorial(int A)
{
    if(A <= 1)
    {
        return "1";
    }
    vector<int> fact = {A};
    int i = A-1;
    while(i >= 1){
        multiply(i, fact);
        i--;
    }
    ostringstream ss;
    if(!fact.empty())
    {
        copy(fact.begin(), fact.end()-1, ostream_iterator<int>(ss, ""));
        ss<<fact.back();
    }
    return ss.str();
}

int main(int argc, char const *argv[])
{
    cout<<factorial(5);
    return 0;
}
