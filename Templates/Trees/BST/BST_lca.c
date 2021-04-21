#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ll long long int
#define BOOL int
#define TRUE 1
#define FALSE -1
#define MAX INT_MAX

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
    newNode->right = NULL;
    newNode->left = NULL;
    return newNode;
}

ll min(struct node* root)
{
    struct node* iter = root;
    while(iter->left != NULL)
    {
        iter = iter->left;
    }
    return iter->value;
}

ll max(struct node* root)
{
    struct node* iter = root;
    while(iter->right != NULL)
    {
        iter = iter->right;
    }
    return iter->value;
}

void inorder_traversal(struct node* root)
{
    if(root == NULL)
        return;
    else
    {
        inorder_traversal(root->left);
        printf("%lld ", root->value);
        //*(C + c) = root->value;
        //c++;
        inorder_traversal(root->right);
    }
}

struct node* LCA(struct node** root, ll key_1, ll key_2)
{
    printf("called LCA : \n");
    struct node* iter_1 = *root;

    while((iter_1 != NULL))
    {
        printf("iter val is : %lld || ", iter_1->value);
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
            printf("breaking point val is : %lld\n", iter_1->value);
            break;
        }
        else if(iter_1->value <= key_1 && iter_1->value >= key_2)
        {
            printf("breaking point val is : %lld\n", iter_1->value);
            break;
        }
    }
    return iter_1;
}


int main()
{
    ll num_node = 0;
    scanf("%lld", &num_node);

    // creating the bst
    struct node* bst[num_node];
    for (ll i = 0; i < num_node; i++)
    {
        ll x;
        scanf("%lld", &x);
        bst[i] = create_node(x);
    }
    for(ll i = 0; i < num_node-1; i++)
    {
        ll p, c;
        char ch;
        scanf("%lld %lld %c", &p,&c,&ch);
        if(ch == 'R')
            bst[p]->right = bst[c];
        else if(ch == 'L')
            bst[p]->left = bst[c];
    }

    // driver program
    inorder_traversal(bst[0]);
    printf("\n");
    ll q1, q2;
    scanf("%lld%lld", &q1, &q2);
    struct node* lca = LCA(&bst[0], bst[q1]->value, bst[q2]->value);
    printf("%lld", lca->value);
    return 0;
}

/*
7
20 8 22 4 12 10 14
0 1 L
0 2 R
1 3 L
1 4 R
4 5 L
4 6 R
*/