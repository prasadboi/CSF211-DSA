#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define ll long long int
#define BOOL int
#define TRUE 1
#define FALSE -1
ll num_nodes;
ll *A;// for preorder
ll a =0;

ll *B;// for postorder
ll b =0;

ll *C;// for inorder
ll c = 0;

ll ABS(ll x)
{
    if(x < 0)
        return -x;
    else
        return x;
}

void print_array(ll *arr, ll length)
{
    for (ll i = 0; i < length; i++)
    {
        printf("%lld ", *(arr + i));
    }
    printf("\n");
}

// tree
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

void inorder_traversal(struct node* root)
{
    if(root == NULL)
        return;
    else
    {
        inorder_traversal(root->left);
        //printf("%lld ", root->value);
        *(C + c) = root->value;
        c++;
        inorder_traversal(root->right);
    }
}

void preorder_traversal(struct node* root)
{
    if(root == NULL)
    {
        return;
    }
    else
    {
        //printf("%lld ", root->value);
        *(A+a) = root->value;
        a++;
        preorder_traversal(root->left);
        preorder_traversal(root->right);
    }
}

void postorder_traversal(struct node* root)
{
    if(root == NULL)
        return;
    else
    {
        postorder_traversal(root->left);
        postorder_traversal(root->right);
        //printf("%lld ", root->value);
        *(B + b) = root->value;
        b++;
    }
}

void calc(ll n)
{
    ll sum = 0;
    for(ll i = 0; i < n; i++)
    {
        ll x = *(A + i);
        ll y = *(B + i);
        ll z = *(C + i);
        sum = sum + abs(x-y) * z;
        printf("sum : %lld", sum);
    }
    printf("%lld", sum);
}

int main()
{
    ll num_nodes = 0;
    scanf("%lld", &num_nodes);
    A = malloc(sizeof(int)*(num_nodes));
    B = malloc(sizeof(int)*(num_nodes));
    C = malloc(sizeof(int)*(num_nodes));
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

    // driver program
    preorder_traversal(tree[0]);
    print_array(A, num_nodes);
    postorder_traversal(tree[0]);
    print_array(B, num_nodes);
    inorder_traversal(tree[0]);
    print_array(C, num_nodes);

    ll sum = 0;
    for(ll i =0; i < num_nodes; i++)
    {
        ll x = *(A + i);
        ll y = *(B + i);
        ll z = *(C + i);
        //sum = sum + ABS(x-y) * z;
        printf("x : %lld, y : %lld, z : %lld, sum : %lld\n", x, y, z, sum);
    }

    return 0;
}

/*
5
1 3 5 79 8
0 1 L
0 2 R
2 3 L
3 4 R
*/