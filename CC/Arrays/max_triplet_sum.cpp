#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int solve_method1(vector<int> &A)
{
    int max_triplet_sum = 0;
    for(int i = 0; i < A.size(); i++)
    {
        int max_less = -1;
        for(int j = 0; j < i; j++)
        {
            if(A[j] < A[i] && (A[j] > max_less))
            {
                max_less = A[j];
            }
        }

        int max_more = -1;
        for(int j = i+1; j < A.size(); j++)
        {
            if((A[j] > A[i]) && (A[j] > max_more))
            {
                max_more = A[j];
            }
        }

        if(max_triplet_sum < (max_more + max_less+A[i]) && (max_less != -1) && (max_more!= -1))
        {
            max_triplet_sum = max_more + max_less + A[i];
        }
    }
    return max_triplet_sum;
}

int main(int argc, char const *argv[])
{
    vector<int> A = {30525, 12550, 17470, 331, 31924, 28351, 14334, 22926, 10911, 19738, 16337};
    cout<<solve_method1(A);
    return 0;
}
