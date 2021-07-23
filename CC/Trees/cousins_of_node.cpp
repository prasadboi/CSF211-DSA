#include <iostream>
#include <string>
#include<bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

TreeNode* search_daddy(TreeNode* A, int key)
{
    if(A == NULL) return NULL;
    if(A->val == key) return NULL;
    cout<<A->val<<endl;

    if((A->left&& A->left->val == key) || (A->right&& A->right->val == key))
    {
        cout<<"found !!!"<<endl;
        return A;
    }
    TreeNode* x = NULL;
    x = search_daddy(A->left, key);
    if (x == NULL) 
        x = search_daddy(A->right,key);
    return x;
}
int tree_height(struct TreeNode* root)
{
    if(root == NULL)
        return 0;
    else return 1 + max(tree_height(root->left), tree_height(root->right));
}

void find_cousin(TreeNode* A, int key, vector<int> &ans, int k)
{
    if(A == NULL) return;
    if(tree_height(A) == k) 
    {
        if((A->left && A->left->val == key) || (A->right && A->right->val == key))
        {}
        else 
        {
            if(A->left)
                ans.push_back(A->left->val);
            if(A->right)
                ans.push_back(A->right->val);
        }
    }
    else
    find_cousin(A->left, key, ans, k);
    find_cousin(A->right, key, ans, k);
}



int main(int argc, char const *argv[])
{
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(3);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);
    vector<int> ans;
    find_cousin(root, 6, ans, 7);
    if(ans.size() == 0) cout<<"\nempty";
    for(auto i : ans)
    {
        cout<<i<<" ";
    }  
    return 0;
    //cout<<(search_daddy(root, 6))->val;
}

