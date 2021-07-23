#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// Given a matrix of m * n elements (m rows, n columns), 
// return all elements of the matrix in spiral order(clockwise).

vector<int> spiralOrder(vector<vector<int>> A)
{
    vector<int> spiral;

    int top_row = 0;
    int bottom_row = A.size()-1;

    int left_col = 0;
    int right_col = A[0].size() - 1;

    int direction = 0; // 0 is ->, 1 is down, 2 is <-, 3 is up

    // loop while the top row is above the bottom row and
    // the right col is to the right of the left col
    while(top_row <= bottom_row && right_col >= left_col)
    {
        switch(direction)
        {
            case 0: 
            for(int j = left_col; j <= right_col; j++)
                    {
                        
                        spiral.push_back(A[top_row][j]);
                    }
                    top_row++;
                    direction = 1;
                    break;
            case 1: 
            for(int i = top_row; i <= bottom_row; i++)
                    {
                        spiral.push_back(A[i][right_col]);
                    }
                    right_col--;
                    direction = 2;
                    break;
            case 2: 
            for(int j = right_col; j >= left_col; j--)
                    {
                        spiral.push_back(A[bottom_row][j]);
                    }
                    bottom_row--;
                    direction = 3;
                    break;
            case 3: 
            for(int i = bottom_row; i >= top_row; i--)
                    {
                        spiral.push_back(A[i][left_col]);
                    }
                    left_col++;
                    direction = 0;
                    break;
        }
    }

    return spiral;
} 

void print_matrix(vector<vector<int>> A)
{
    cout<<"------------------------------------"<<endl;
    for (int i = 0; i < A.size(); i++)
    {
        for(int j = 0; j < A[i].size(); j++){
            cout<<A[i][j]<<" ";
        }
        cout<<endl;
    }    
    cout<<"------------------------------------"<<endl;
} 

void print_array(vector<int> A)
{
    cout<<"------------------------------------"<<endl;
    for(int i = 0; i < A.size(); i++){
        cout<<A[i]<<" ";
    }
    cout<<endl<<"--------------------------------------"<<endl;
}

int main(int argc, char const *argv[])
{
    int m, n;
    cin>>m>>n;
    vector<vector<int>> A;
    A.resize(m);
    for (int i = 0; i < m; i++)
    {
        A[i].resize(n);
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin>>A[i][j];
        }
    }
    print_matrix(A);
    vector<int> spiral = spiralOrder(A);
    print_array(spiral);
    
    return 0;
}
