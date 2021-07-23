#include <bits/stdc++.h>
#include <iostream>

using namespace std;

// Given an array of integers, A of length N, 
// find out the maximum sum sub-array of non negative numbers from A

void print_array(vector<int> A)
{
    cout<<"------------------------------------"<<endl;
    for(int i = 0; i < A.size(); i++){
        cout<<A[i]<<" ";
    }
    cout<<endl<<"--------------------------------------"<<endl;
}

vector<int> max_sum_subarray(vector<int> A) 
{
    vector<int> res;
    int max_sum = 0;
    int sum = 0;
    int start_index = 0;
    int end_index = 0;
    for(int i = 0; i < A.size(); i++)
    {
        if(A[i] >= 0){
            sum += A[i];
        }
        if(A[i] < 0){
            if(max_sum < sum){
                max_sum = sum;
                end_index = i-1;
            }
            sum = 0;
        }
    }
    int i = end_index;
    while(A[i] >= 0 && i >-1)
    {
        i--;
    }
    start_index = i+1;

    for(int j = start_index; j <= end_index; j++)
    {
        res.push_back(A[j]);
    }
    cout<<start_index<<endl<<end_index<<endl;
    return res;
}

int main(int argc, char const *argv[])
{
    vector<int> A = {1, 2, 5, -7, 2, 3};
    vector<int> res = max_sum_subarray(A);
    print_array(res);
    return 0;
}
