#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

int binarySearch(vector<int> &A, int key)
{
    //cout<<"calling binary search"<<endl;
    A.push_back(INT_MAX);
    int n = A.size();
    int low = 0, high = n-1;
    int mid;
    while(low < high)
    {
        mid = low + (high - low)/2;
        //cout<<"low: "<<low<<" high: "<<high<<" mid: "<<mid<<endl;
        if(A[mid] <= key)
            low = mid + 1;
        else
            high = mid;
    }
    return low;
}

int median_merged_arr(vector<int> &A, vector<int> &B)
{
    int i = 0, j = 0;
    
}


int main(int argc, char const *argv[])
{
    vector<int> array1 = {1, 4, 5}, array2 = {2, 3};

    return 0;
}
