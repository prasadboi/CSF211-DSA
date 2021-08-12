#include<iostream>
#include <bits/stdc++.h>
using namespace std;

void printMat(vector<vector<int> > &A) {
    
    cout<<"---------------------------------------------\n";
    for(int i = 0; i < A.size(); i++) {
        for(int j = 0; j < A[i].size(); j++) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
    cout<<"-----------------------------------------------\n";
}

int maxSumSubMatrix_sizeB(vector<vector<int> > &A, int B) {
    int n = A.size();
    
    //printMat(A);
    vector<vector<int> > Sum(n, vector<int>(n, 0));
    Sum[0][0] = A[0][0];
    for(int i = 1; i < n; i++)
    {
        Sum[0][i] = A[0][i] + Sum[0][i-1];
        Sum[i][0] = A[i][0] + Sum[i-1][0];
    }

    for(int i = 1; i < n; i++)
    {
        for(int j = 1; j < n; j++)
        {
            Sum[i][j] = ((Sum[i-1][j] + Sum[i][j-1]) - Sum[i-1][j-1]) + A[i][j];
        }
    }
    //printMat(Sum);

    int max_sum = INT_MIN;
    for(int i = B-1; i < n; i++)
    {
        for(int j = B-1; j < n; j++)
        {
            int a = 0, b = 0, c = 0;
            if(i >= B){
                a = Sum[i-B][j];
            }
            if(j >= B){
                b = Sum[i][j-B];
            }
            if(i >= B && j >= B){
                c = Sum[i-B][j-B];
            }
            max_sum = max(max_sum, Sum[i][j] - (a+b-c));
        }
    }
    return max_sum;
}

int main(int argc, char const *argv[])
{
    vector<vector<int>> A = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    cout<<maxSumSubMatrix_sizeB(A, 2)<<endl;
    return 0;
}
