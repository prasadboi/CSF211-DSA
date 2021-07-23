// Given an sorted array A of size N. Find number of elements which are less than or equal to B.
// https://www.interviewbit.com/problems/smaller-or-equal-elements/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int num_less_eq(vector<int> &A, int n)
{
    int low = 0;
    int high = A.size() - 1;
    //cout<<"low : "<<low<<" high : "<<high<<endl;
    int mid;
    while(low <= high)
    {
        mid = high + low;
        mid = ceil(mid/2);
        //cout<<"low : "<<low<<" high : "<<high<<" mid : "<<mid<<endl;
        if(A[mid] <= n && A[mid + 1] >= n)
        {
            mid++;
            break;
        }
        else if(A[mid] <= n)
        {
            low = mid + 1;
        }
        else if(A[mid] > n)
        {
            high = mid - 1;
        }
    }
    return mid;
}

int main(int argc, char const *argv[])
{
    vector<int> A = {5};
    cout<<num_less_eq(A, 1);
    return 0;
}
