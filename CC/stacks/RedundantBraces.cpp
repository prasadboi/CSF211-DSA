#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

int redundant_braces(string A)
{
    for(int i = 0; i < A.length()-1; i++)
    {
        if(A[i] == '(' && A[i+1] == '(')
        {
            while((i < A.length() - 1) && A[i] != ')')
            {
                i++;
            }
            if(A[i] == ')' && A[i+1] == ')')
            {
                return 1;
            }
        }
        else if(A[i-1] == '(' && (A[i] == ')' || (A[i+1] == ')')))
        {
            return 1;
        }
    }
    return 0;
}

int main(int argc, char const *argv[])
{
    string A = "(a + (a + b))";
    cout<<redundant_braces(A);
    return 0;
}
