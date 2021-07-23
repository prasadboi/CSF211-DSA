#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

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

TreeNode* makeTree(vector<int> &inorder, vector<int> &postorder, int start, int end, int& postorder_idx)
{
    if(start > end) return NULL;
    
    TreeNode* newNode = new TreeNode(postorder[postorder_idx--]);
    if(start == end) return newNode; // we are a t a leaf

    int inorder_idx = search(inorder, start, end, newNode->val);
    newNode->right = makeTree(inorder, postorder, inorder_idx+1, end, postorder_idx);
    newNode->left = makeTree(inorder, postorder, start, inorder_idx-1, postorder_idx);
    return newNode;
}

TreeNode* buildTree(vector<int> &inorder, vector<int> &postorder)
{
    if(inorder.empty() || postorder.empty()) return NULL;
    int postorder_idx = postorder.size() - 1;
    return makeTree(inorder, postorder, 0, inorder.size()-1, postorder_idx);
}


int main(int argc, char const *argv[])
{
    
    return 0;
}
