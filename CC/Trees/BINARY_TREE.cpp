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

// tree height-------------------------------------------------------------------------------------------------------
int tree_height(struct TreeNode* root)
{
    if(root == NULL)
        return 0;
    else return 1 + max(tree_height(root->left), tree_height(root->right));
}

// traversals---------------------------------------------------------------------------------------------

// inorder
void inorder(struct TreeNode* root, vector<int> &A)
{
    if(root == NULL)
        return ;
    inorder(root->left, A);
    A.push_back(root->val);
    inorder(root->right, A);
}

// preorder
void preorder(struct TreeNode* root, vector<int> &A)
{
    if(root == NULL)
        return;
    A.push_back(root->val);
    preorder(root->left, A);
    preorder(root->right, A);
}

// postorder
void postorder(struct TreeNode* root, vector<int> &A)
{
    if(root == NULL)
        return;
    postorder(root->left, A);
    postorder(root->right, A);
    A.push_back(root->val);
}

// level order
// in O(1) space, O(n^2) time
void print_kth_lvl(struct TreeNode* root, int k, vector<int> &A)
{
    if(root == NULL)
        return;
    else if(k == 1)
    {
        A.push_back(root->val);
        return;
    }
    else
    {
        print_kth_lvl(root->left, k-1, A);
        print_kth_lvl(root->right, k-1, A);
    }
}



vector<int> level_order(struct TreeNode* root)
{
    vector<int> A;
    int height = tree_height(root);
    for(int i = 0; i < height; i++)
    {
        print_kth_lvl(root, i, A);
    }
    return A;
}


// BFS : O(n) time complexity, O(n) space.
// if you want layer by layer output then simply output new Line whenever temp is null;
vector<int> BFS(struct TreeNode* root)
{
    queue<struct TreeNode*> q;
    vector<int> A;
    q.push(root);
    //q.push(NULL);
    while(!q.empty())
    {
        //bool is_null = false;
        struct TreeNode* temp = q.front();
        /*if(temp == NULL)
        {
            q.pop();
            temp = q.front();
            q.pop();
        }*/
        A.push_back(temp->val);
        q.pop();
        if(temp->left)
            q.push(temp->left);
        if(temp->right)
            q.push(temp->right);
        /*if(is_null)
        {
            q.push(NULL);
        }*/
    }
    return A;
}

// inorder traversal using a stack
vector<int> inorder_iterative_using_stack(struct TreeNode* root)
{
    stack<TreeNode*> s;
    vector<int> v;
    struct TreeNode* iter = root;
    bool flag = true;
    while(flag)
    {
        if(iter)
        {
            s.push(iter);
            iter = iter->left;
        }
        else
        {
            if(!s.empty())
            {
                iter = s.top();
                s.pop();
                v.push_back(iter->val);
                iter = iter->right;
            }
            else
                flag = false;
        }
    }
}

int diameter(struct TreeNode* root)
{
    // this solution runs in T(n) = O(n^2). 
    // Explanation : tree_height takes O(n) time and diameter() calls itself on all of its nodes which in the worst case = n heights. therefore T(n) = O(n^2)
    if(root == NULL) return 0;
    return max(max(tree_height(root->left) + tree_height(root->right), diameter(root->left)),diameter(root->right));
}

// we shall try to optimize above solution using dynamic programming
// use a structure to store all the heights already computed. Therefore the calls to tree_height now only take O(1) time.
// Thus overall time complexity is O(n)
pair<int, int> diameter_optimized(struct TreeNode* root)
{
    pair<int, int> p;
    if(root == NULL)
        p.first = p.second = 0;
    pair<int, int> left_child, right_child;
    left_child = diameter_optimized(root->left);
    right_child = diameter_optimized(root->right);

    p.first = max(left_child.first, right_child.first) + 1;
    p.second = max(max(left_child.second,right_child.second), 1  + left_child.first + right_child.first);
    return p;
}

//sum of all paths from root to leaves 
int root_leaf_path(struct TreeNode* root, int pathsum)
{
    // probelm statement: https://leetcode.com/problems/sum-root-to-leaf-numbers/
    if(root == NULL)
        return 0;
        
    pathsum = pathsum*10 + root->val;
    if(root->right == NULL && root->left == NULL)
        return pathsum;
    else
    {
        return root_leaf_path(root->left, pathsum) + root_leaf_path(root->right, pathsum);
    }
    // call with params root, 0
}

// least common ancesetor assuming botht the nodes exist in the tree
struct TreeNode* LCA(TreeNode* A, int B, int C)
{
    // https://www.interviewbit.com/problems/least-common-ancestor/
    if(A == NULL) return NULL;
    if(A->val == B || A->val == C)
        return A;
    
    struct TreeNode* lc = LCA(A->left, B, C);
    struct TreeNode* rc = LCA(A->right, B, C);

    if(lc && rc)
        return A;
    
    if(lc)
        return lc;
    else return rc;
}


// SUM TREE
// https://practice.geeksforgeeks.org/problems/sum-tree/1
int sum_tree(struct TreeNode* root)
{
    if(root == NULL) return 0;

    if(root->right == NULL && root->left == NULL)
        return root->val;

    int sumr = sum_tree(root->right);
    int suml = sum_tree(root->left);
    int sum = 0;
    if(root->right != NULL && sumr == 0)
        return 0;
    if(root->left != NULL && suml == 0)
        return 0;

    if(root->right != NULL || root->left != NULL)
        {
            sum = sum_tree(root->left) + sum_tree(root->right);
            if(root->val == sum)
                return root->val;
            else
                return 0;
        }
}


int main(int argc, char const *argv[])
{
    // creating BST
    vector<int> A = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    struct TreeNode* root = ans(A, 0, 10);

    // driver program
    cout<<"driver program: \n";
    vector<int> o_p = BFS(root);
    for(auto i : A)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    //


    return 0;
}

