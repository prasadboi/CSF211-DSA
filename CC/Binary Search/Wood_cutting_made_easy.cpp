// https://www.interviewbit.com/problems/woodcutting-made-easy/

#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;


// function to calculate the amount of wood harvested
int amount(vector<int> &A, int h)
{
    int sum = 0;
    for(int i = 0; i < A.size(); i++)
    {
        if(A[i] > h)
        {
            sum += A[i] - h;
        }
    }
    return sum;
}

int solve(vector<int> &A, int B)
{
    sort(A.begin(), A.end());
    int low = 0;
    int high = A[A.size() - 1];
    while(low <= high)
    {
        int mid = low + (high - low)/2;
        cout<<"low : "<<low <<"high : "<<high<<endl;
        cout<<"mid : "<<mid<<"amount : "<< amount(A, mid)<<endl;
        if(mid == low)
            break;
        if(amount(A, mid) == B)
            return mid;
        else if(amount(A, mid) > B)
        {
            low = mid ;
        }
        else 
        {
            high = mid;
        }
    }
    return low;
}

int main(int argc, char const *argv[])
{
    vector<int> A = {62, 117, 149, 85, 144, 53, 61, 72, 83, 123, 114, 91, 61, 103};
    int n = 4;
    int b = 68;
    cout<<solve(A, b);
    return 0;
}
