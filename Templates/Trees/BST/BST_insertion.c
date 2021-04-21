#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ll long long int
#define BOOL int

struct node
{
    ll value;
    struct node* right;
    struct node* left;
};

struct node* create_node(ll val)
{
    struct node* newNode = (struct node*)malloc(sizeof(struct node*));
    newNode->value = val;
    newNode->right = NULL;
    newNode->left = NULL;
    return newNode;
}

void post_order(struct node* root)
{
    struct node* iter = root;
    if(iter == NULL)
    {
        return;
    }
    
    post_order(iter->left);
    post_order(iter->right);
    printf("%lld ", iter->value);
}

void insert(struct node** root, ll key)
{
    struct node* x = (*root);
    struct node* y = NULL;

    while(x != NULL)
    {
        y = x;
        if(x->value > key)
        {
            x = x->left;
        }
        else if(x->value < key)
        {
            x = x->right;
        }
        else if(x->value == key)
        {
            return;
        }
    }

    if(y == NULL)
    {
        // the tree was empty !!
        (*root) = create_node(key);
    }
    else 
    {
        if(key > y->value)
        {
            y->right = create_node(key);
        }
        else
        {
            y->left = create_node(key);
        }
    }
}

int main()
{
    ll num_node = 0;
    scanf("%lld", &num_node);
    struct node* root = NULL;
    for (ll i = 0; i < num_node; i++)
    {
        ll x;
        scanf("%lld", &x);
        insert(&root, x);
    }
    post_order(root);
    printf("\n");
    
    return 0;
}