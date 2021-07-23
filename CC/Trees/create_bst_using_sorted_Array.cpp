#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct TreeNode
{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode(int val) : val(val), left(NULL), right(NULL) {}
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

void inorder(struct TreeNode* root)
{
    if(root == NULL)
        return ;
    inorder(root->left);
    cout<<root->val<<endl;
    inorder(root->right);
}

int main(int argc, char const *argv[])
{
    vector<int> A = {1, 2, 3, 4, 5, 6, 7, 9, 10, 11};
    struct TreeNode* root = ans(A, 0, 9);
    cout<<"checkpoint"<<endl;
    inorder(root);
    return 0;
}
