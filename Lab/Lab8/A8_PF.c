#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ll long long int
#define BOOL int 
#define TRUE 1
#define FALSE 0

// BINARY SEARCH TREE----------------------------------------------------------------------------------------------------------------


struct node 
{
    ll value;
    struct node* left;
    struct node* right;
};

// search function-------------------------------------------------------------------------------------------------------------------------
struct node* search(struct node** root, ll key)
{
    if((*root)->value == key)
        return (*root);
    else if((*root)->value < key)
        return search(&((*root)->right), key);
    else if((*root)->value > key)   
        return search(&((*root)->left), key); 
}
//-------------------------------------------------------------------------------------------------------------------------

// minimum of a BST---------------------------------------------------------------------------------------------------------
struct node* find_minimum(struct node** root)
{
    if(root == NULL)
    {
        printf("BST is empty\n");
        return NULL;
    }

    struct node* iter = (*root);
    while(iter->left != NULL)
    {
        iter = iter->left;
    }
    return iter;
}
//--------------------------------------------------------------------------------------------------------------------------

// create a node in the BST-------------------------------------------------------------------------------------------------
struct node* create_node(ll val)
{
    struct node* newNode = (struct node*)malloc(sizeof(struct node*));
    newNode->value = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode; 
}
//-----------------------------------------------------------------------------------------------------------------------------

// inserting in a BST------------------------------------------------------------------------------------------------------------
struct node* insert_node(struct node** root, ll val)
{

    struct node* newNode = create_node(val);

    struct node* x = (*root);
    struct node* y = NULL;

    while(x != NULL)
    {
        // y is trailing pointer of x
        y = x;

        if(val < x->value)
        {
            x = x->left;
        }
        else 
        {
            x = x->right;
        }
    }

    if(y == NULL)
    {
        // the tree was empty!!!
        (*root)->value = val;
    }
    else if(val < y->value)
    {
        y->left = newNode;
    }
    else{
        y->right = newNode;
    }
    return y;
    
    /*
    // adopting a recursive approach (haven't handled empty tree add karle)
    if(val > (*root)->value)
    {
        // if the val is greater than the root then it must be inserted somewhere in the right half of the BST
        (*root)->right = insert_node(&((*root)->right), val);
    }
    else if(val < (*root)->value)
    {
        // if the val is lesser than the root then it must be inserted somewhere in the left half of the BST
        (*root)->left = insert_node(&((*root)->left), val);
    }
    // returns the topmost point (i.e. the root) of the subsection of the BST
    return (*root);
    */
}
//--------------------------------------------------------------------------------------------------------------------------

// least common ancestor-----------------------------------------------------------------------------------------------------
struct node* LCA(struct node** root, ll key_1, ll key_2)
{
    //printf("called LCA : \n");
    struct node* iter_1 = *root;

    while((iter_1 != NULL))
    {
        //printf("iter val is : %lld || ", iter_1->value);
        if(iter_1->value > key_1 && iter_1->value > key_2)
        {
            iter_1 = iter_1->left;
        }
        else if(iter_1->value < key_1 && iter_1->value < key_2)
        {
            iter_1 = iter_1->right;
        }
        else if(iter_1->value >= key_1 && iter_1->value <= key_2)
        {
            //printf("breaking point val is : %lld\n", iter_1->value);
            break;
        }
        else if(iter_1->value <= key_1 && iter_1->value >= key_2)
        {
            //printf("breaking point val is : %lld\n", iter_1->value);
            break;
        }
    }
    return iter_1;
}

int main(int argc, char const *argv[])
{
    ll nodes, queries = 0;
    scanf("%lld%lld",&nodes, &queries);
    struct node* wts[nodes];
    for (ll i = 0; i < nodes; i++)
    {
        ll x;
        scanf("%lld", &x);
        wts[i] = create_node(x);
    }
    //printf("completed wts input successfully\n");

    for (size_t i = 0; i < nodes-1; i++)
    {
        char buf;
        ll int_buf1, int_buf2;
        //printf("give input : ");
        scanf("%lld %lld %c", &int_buf1, &int_buf2, &buf);
        if(buf == 'L')
        {
            wts[int_buf1]->left = wts[int_buf2];
        }
        else if(buf == 'R')
        {
            wts[int_buf1]->right = wts[int_buf2];
        }
        //printf("inputted succesfully\n");
    }

    for (ll i = 0; i < queries; i++)
    {
        ll int_buf1, int_buf2;
        scanf("%lld%lld", &int_buf1, &int_buf2);
        struct node* key = LCA(&(wts[0]), wts[int_buf1]->value, wts[int_buf2]->value);
        for (ll i = 0; i < nodes; i++)
        {
            if(wts[i]->value == key->value)
            {
                printf("%lld ", i);
                break;
            }
        }
    }
    
    
    
    return 0;
}
