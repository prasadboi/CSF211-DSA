#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> diagonalTraversal(TreeNode* A)
{
    queue<TreeNode*> q;
    vector<int> ans;
    q.push(A);
    while(!q.empty())
    {
        TreeNode* iter = q.front();
        q.pop();

        while(iter)
        {
            if(iter->left) q.push(iter->left);
            ans.push_back(iter->val);
            iter = iter->right;
        }
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    
    return 0;
}
