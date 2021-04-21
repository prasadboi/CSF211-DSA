#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ll long long int
#define BOOL int
#define TRUE 1
#define FALSE -1

struct node
{
    ll value;
    struct node* left;
    struct node* right;
};

struct node* create_node(ll val)
{
    struct node* newNode = (struct node*)malloc(sizeof(struct node*));
    newNode->value = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// getting height of the node so that its level can be determined
ll height(struct node* NODE)
{
    if(NODE == NULL)
        return 0;
    ll left_height = height(NODE->left);
    ll right_height = height(NODE->right);

    if(left_height > right_height)
        return left_height+1;
    else
        return right_height+1;
}

void print_level_LR(struct node* NODE, ll level)
{
    if(NODE == NULL)
    {
        return;
    }
    if(level == 1)
    {
        printf("%lld ", NODE->value);
    }
    if(level > 1)
    {
        print_level_LR(NODE->left, level-1);
        print_level_LR(NODE->right, level-1);
    }
}

void print_level_RL(struct node* NODE, ll level)
{
    if(NODE == NULL)
    {
        return;
    }
    if(level == 1)
    {
        printf("%lld ", NODE->value);
    }
    if(level > 1)
    {
        print_level_RL(NODE->right, level-1);
        print_level_RL(NODE->left, level-1);
    }
}

void print_zig_zag_order(struct node* root)
{
    ll max_level = height(root);
    for(ll i = 1; i <= max_level; i++)
    {
        if(i%2 == 0)
        {
            print_level_RL(root, i);
        }
        else
        {
            print_level_LR(root, i);
        }
    }
}

int main(int argc, char const *argv[])
{
    ll num_nodes = 0;
    scanf("%lld", &num_nodes);

    // building the tree
    struct node* tree[num_nodes];
    for(ll i = 0; i < num_nodes; i++)
    {
        ll x;
        scanf("%lld",&x);
        tree[i] = create_node(x);
        //printf("added node with value : %lld\n", tree[i]->value);
    }    

    for(ll i = 0; i < num_nodes-1; i++)
    {
        ll p, c;
        char ch;

        scanf("%lld %lld %c", &p, &c, &ch);
        if(ch == 'R')
            tree[p]->right = tree[c];
        else if(ch == 'L')
            tree[p]->left = tree[c];
    }


    // calling function
    printf("max height : %lld\n", height(tree[0]));
    print_zig_zag_order(tree[0]);


    return 0;
}

/*
7
1 5 4 3 8 10 2
0 1 L
0 2 R
2 3 R
1 4 R
1 5 L
5 6 L
*/
