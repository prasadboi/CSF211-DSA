#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

// find index of least integer greater than key
int binarySearch_lessequal(vector<int> &A, int key) {
    int low = 0;
    int high = A.size() - 1;
    int mid;
    while(low < high)
    {
        mid = low + (high - low)/2;
        // At least (mid + 1) elements are there
            // whose values are less than
            // or equal to key
        if(A[mid] <= key)
            low = mid + 1;
            
        else if(A[mid] > key)
            high = mid;
    }
    return low;
}

int binarySearch_less(vector<int> &A, int key)
{
    int low = 0, high = A.size() - 1, mid;
    while(low < high)
    {
        mid = low + (high - low)/2;
        if(A[mid] < key)
            low = mid + 1 ;
        else
            high = mid;
    }
    return low;
}

int main(int argc, char const *argv[])
{
    int n, k;
    n = 6;
    k = 8;
    vector<int> v = {5, 7, 7, 8, 8, 10};
    v.push_back(INT_MAX);
    cout<<binarySearch_lessequal(v, 8) - binarySearch_less(v, 8);
    return 0;
}
