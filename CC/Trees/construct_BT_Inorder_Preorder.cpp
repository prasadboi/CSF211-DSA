#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

// NOTE: 
// first element of subarrya in preorder is root of subtree
// all elements to the left of the root in inorer traversal belong to the left subtree of the root.

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void inorder_traversal(TreeNode* root)
{
    if(root == NULL) return ;
    inorder_traversal(root->left);
    cout<<root->val<<" ";
    inorder_traversal(root->right);
}

int search(vector<int> &arr, int st, int end ,int key)
{
    for(auto i = st; i  <= end; i++){
        if(arr[i] == key) 
            return i;
    }
    return -1;
}

TreeNode* makeTree(vector<int> &preorder, vector<int> &inorder, int start, int end, int& preorder_idx)
{
    if(start > end) return NULL;

    TreeNode* newNode = new TreeNode(preorder[preorder_idx++]);
    if(start == end) return newNode;

    int inorder_idx = search(inorder, start, end, newNode->val);
    newNode->left = makeTree(preorder, inorder, start, inorder_idx - 1, preorder_idx);
    newNode->right = makeTree(preorder, inorder, inorder_idx + 1, end, preorder_idx);
    return newNode;
}

TreeNode* buildTree(vector<int> &preorder, vector<int> &inorder)
{
    if(preorder.empty() || inorder.empty()) return NULL;
    int preorder_idx = 0;
    return makeTree(preorder, inorder, 0, inorder.size()-1, preorder_idx);
}

TreeNode* search_daddy(TreeNode* A, int key)
{
    if(A == NULL) return NULL;
    if(A->left->val == key || A->right->val == key)
    {
        return A;
    }
    TreeNode* val = NULL;
    val = search_daddy(A->left, key);
    if(!val) val = search_daddy(A->right,key);
    return val;
}


int main(int argc, char const *argv[])
{
    vector<int> preorder = {2, 1, 6, 5, 3, 4 };
    vector<int> inorder = {5, 6, 1, 2, 3, 4};
    TreeNode* root = buildTree(preorder, inorder);
    inorder_traversal(root);
    //cout<<endl<<(search_daddy(root, 6))->val;

    return 0;
}
