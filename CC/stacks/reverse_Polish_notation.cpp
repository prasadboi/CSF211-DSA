#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

int eval(char opn, int a, int b)
{
    switch(opn)
    {
        case '+':
            return a + b;
            break;
        case '-':
            return a - b;
            break;
        case '/':
            return a/b;
            break;
        case '*':
            return a*b;
            break;
    }
    return INT_MIN;
}

int evalRPN(vector<string> &A) {
    
    int res;
    int flag = 0;
    stack<int> num;
    for(int i = 0; i < A.size(); i++)
    {
        //cout<<"i: "<<i<<endl;
        if((A[i][0] == '*'||A[i][0] == '/' ||A[i][0] == '+' || A[i][0] == '-') && A[i].length() == 1)
        {
            cout<<"A[i][0]: "<<A[i][0]<<endl;
            int opr1 = num.top();
            num.pop();
            int opr2 = num.top();
            num.pop();
            res = eval(A[i][0], opr2, opr1);
            num.push(res);
        }
        else
        {
            num.push(stoi(A[i]));
        }
    }
    return num.top();

}


int main(int argc, char const *argv[])
{
    vector<string> A = {"-1"};
    cout<< evalRPN(A);
    return 0;
}
