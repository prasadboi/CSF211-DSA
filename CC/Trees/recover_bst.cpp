// https://www.interviewbit.com/problems/recover-binary-search-tree/

#include <iostream>
#include <string>
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

vector<int> recoverTree(TreeNode* root)
{
    vector<int> real;
    inorder(root, real);
    vector<int> sorted = real;
    sort(sorted.begin(), sorted.end());
    for(int i = 0; i < sorted.size(); i++)
    {
        if(sorted[i] == real[i])
        {
            sorted.erase(sorted.begin());
            real.erase(real.begin());
        }
    }
    return real;
}

void inorder(struct TreeNode* root, vector<int> &A)
{
    if(root == NULL)
        return ;
    inorder(root->left, A);
    A.push_back(root->val);
    inorder(root->right, A);
}

int main(int argc, char const *argv[])
{
    vector<int> A = {1, 9, 3, 4, 5, 6, 7, 8, 2, 10, 11};
    struct TreeNode* root = ans(A, 0, 10);
    return 0;
}
