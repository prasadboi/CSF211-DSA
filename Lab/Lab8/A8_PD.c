#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ll long long int
#define BOOL int
#define TRUE 1
#define FALSE 0



// BINARY TREE

struct node {
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

// brute force searching through the binary tree using preorder traversal
struct node* search(struct node** root, ll key)
{
    struct node* x = NULL;

    //printf("searching : \n");
    if((*root)->value == key)
    {
        printf("found !!!\n");
        x = *root;
    }
    
    if((*root) == NULL) 
        return NULL;
    
    if((x == NULL) && ((*root)->left != NULL))
        x = search(&((*root)->left), key);
    if((x == NULL) && ((*root)->right != NULL))
        x = search(&((*root)->right), key);
    return x;
}

// function to delete a node and all its children
void delete(struct node** root, ll key){
    struct node* x = search(root, key);
    // if the node to be deleted is a leaf
    if((x->left == NULL) && (x->right == NULL))
    {
        printf("deleting : %lld\n", x->value);
        free(x);
    }
    else
    {
        if(x->right != NULL)
            delete(&(x->right), x->right->value);
        if(x->left != NULL)
            delete(&(x->left), x->left->value);
        printf("deleting : %lld\n", x->value);
        free(x);
    }
    //printf("deleted!!!\n");
}

void swap_nodes(struct node** node_1, struct node** node_2)
{
    printf("swapping : \n");
    struct node* temp = (*node_1); // random ini
    ll int_temp;

    int_temp = (*node_1)->value;
    (*node_1)->value = (*node_2)->value;
    (*node_2)->value = int_temp;

    temp = (*node_1)->left;
    (*node_1)->left = (*node_2)->left;
    (*node_2)->left = temp;

    temp = (*node_1)->right;
    (*node_1)->right = (*node_2)->right;
    (*node_2)->right = temp;
    
    printf("swapped successfully : \n, node 1 is now : %lld, node 2 is now : %lld\n", (*node_1)->value, (*node_2)->value);
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

    for (ll i = 0; i < nodes-1; i++)
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

    /*printf("testing search function: %lld\n", search(&wts[0], 99)->value);
    delete(&wts[0], 99);
    swap_nodes(&wts[3], &wts[4]);*/

    for (ll i = 0; i < queries; i++)
    {
        char str[50];
        scanf("%s", str);
        ll buff_1, buff_2;
        if(strcmp(str, "DELETE") == 0)
        {
            scanf("%lld", &buff_1);
            delete(&wts[0], buff_1);
        }
        else if(strcmp(str, "SWAP") == 0)
        {
            scanf("%lld%lld", &buff_1, &buff_2);
            ll j, k;
            for (ll j = 0; j < nodes; j++)
            {
                if(wts[j]->value == buff_1)
                {
                    break;
                }
            }
            for (ll k = 0; k < nodes; k++)
            {
                if(wts[k]->value == buff_2)
                {
                    break;
                }
            }
            swap_nodes(&wts[j], &wts[k]);
        }
    }
    
    return 0;
}
