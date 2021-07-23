// https://www.interviewbit.com/problems/largest-rectangle-in-histogram/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int largestRectangle(vector<int> &A)
{
    stack<int> small_left;
    A.push_back(0);
    int max_area = 0;
    for(int i = 0; i < A.size(); i++)
    {
        while(!small_left.empty() && A[small_left.top()] >= A[i])
        {
            // i will be the right nearest index that is smaller than height
            int height = A[small_left.top()];
            small_left.pop();
            // now the top will be smallest nearest index to the left
            int width = !small_left.empty() ? i-1-small_left.top() : i;
            int area = height*width;
            max_area = max(max_area,area);
        }
        small_left.push(i);
    }
    return max_area;
}

int main(int argc, char const *argv[])
{
    vector<int> A;
    for(int i = 0; i < 10000; i++)
    {A.push_back(1);}
    cout<<largestRectangle(A)<<endl;
    return 0;
}

/* NOTE:

In this question the largest rectangle of a particular height is width = (index of column >= curr height that is farthest away from col on right)
                                                                         -
                                                                         (index of column >= curr height that is farthest away from col on left) + 1

which is equivalent to                                                   = (index_nearest_smaller_col_on_right - 1) - (index_nearet_smaller_col_on_left + 1) + 1
area = height of nearest smallest element on left * width
     = s.top()*width
*/

