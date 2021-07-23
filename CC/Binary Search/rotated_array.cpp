#include <iostream>
#include <bits/stdc++.h>

using namespace std;
// given a rotated sorted array find its minimum
int get_min(const vector<int> &A)
{
    int low = 0, high = A.size() - 1, mid;
    while(low < high)
    {
        mid = low + (high - low)/2;
        //cout<<"mid: "<<mid<<endl;
        if(A[mid] > A[high])
        {
            // the middle element is to the left of the pivot
            low = mid + 1;
        }
        else
        {
            high = mid;
        }
    }
    return A[low];
}

int main(int argc, char const *argv[])
{
    vector<int> A = {4, 5, 6, 7, 0, 1, 2, 3};
    cout<<get_min(A);
    return 0;
}
