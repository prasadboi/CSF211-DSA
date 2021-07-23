// https://www.interviewbit.com/problems/sort-by-color/

#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

// use the integers 0, 1, and 2 to represent the colors
// red, white, and blue respectively

// solution if i move all the 0s to the front and all the 2s to the back, then i have effectively sorted the arrays

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sort_by_color(vector<int> &A)
{
    int L = 0;// points to left most 1 or 2
    int R = A.size() - 1;// points to righmost 0 or 1
    int i = 0;

    for(; L < A.size(); L++)
    {
        if(A[L] != 0)
            break;
    }

    for(; R >= 0; R--)
    {
        if(A[R] != 2)
            break;
    }

    
    i = L;
    while(i >= L && i <= R)
    {
        //cout<<"L: "<<L<<" i: "<<i<<" R: " <<R <<endl;
        if(A[L] == 0)
        {
            L++;
        }
        if(A[R] == 2)
        {
            R--;
        }
        if(A[i] == 0)
        {
            swap(&A[i], &A[L]);
            //cout<<"swapped!\n";
        }
        else if(A[i] == 2)
        {
            swap(&A[R], &A[i]);
            //cout<<"swapped!\n";
        }
        else if(A[i] == 1)
            i++;
    }

}

int main(int argc, char const *argv[])
{
    vector<int> A = {0};
    sort_by_color(A);
    //cout<<"0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2\n";
    for(auto i : A)
    {
        cout<<i<<" ";
    }
    return 0;
}
