#include <iostream>
#include <bits/stdc++.h>


using namespace std;


struct TreeNode {
    int val;
    struct TreeNode *right, *left;
    TreeNode(int x) : val(x), right(NULL), left(NULL){}
};

struct TreeNode* ans(const vector<int> &A, int start, int end)
{
    int mid = start + (end - start)/2;
    struct TreeNode* newNode = new TreeNode(A[mid]);
    if(start == end)
        return newNode;
    else if(start > end)
        return NULL;
    newNode->left = ans(A, start, mid-1);
    newNode->right = ans(A, mid + 1, end);
    return newNode;
}


int main(int argc, char const *argv[])
{
    
    // creating BST
    vector<int> A = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    struct TreeNode* root = ans(A, 0, 10);

    // driver program
    cout<<"driver program: \n";
    for(auto i : A)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}
