#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ll long long int
#define BOOL int

struct node
{
    char value[5];
    struct node* right;
    struct node* left;
};

struct node* create_node(char val[])
{
    struct node* newNode = (struct node*)malloc(sizeof(struct node*));
    strcpy(newNode->value, val);
    newNode->right = NULL;
    newNode->left = NULL;
    return newNode;
}

void in_order(struct node* root)
{
    struct node* iter = root;
    if(iter == NULL)
        return;

    in_order(iter->left);
    if(strcmp(iter->value, "-1") != 0 && strcmp(iter->value, "1-"))
        printf("%s ", iter->value);
    in_order(iter->right);
}

void invert_num(char num[5])
{
    char temp[5];
    int i = 0;
    int len = 0;
    while(num[i] != '\0')
    {
        temp[i] = num[i];
        i++;
    }
    len = i;
    i--;
    //printf("len is = %d\n", len);
    while(i >= 0)
    {
        num[len - i-1] = temp[i];
        i--;
    }
}

void invert_tree(struct node** root)
{
    if((*root) == NULL)
        return;
    invert_num((*root)->value);

    // swapping subtrees
    struct node* temp = (*root)->right;
    (*root)->right = (*root)->left;
    (*root)->left = temp;

    // calling recursively
    invert_tree(&((*root)->left));
    invert_tree(&((*root)->right));
}

int main()
{
    ll num_node = 0;
    scanf("%lld", &num_node);
    struct node* tree[num_node];
    for(ll i = 0; i < num_node; i++)
    {
        char x[5];
        scanf("%s", &x);
        tree[i] = create_node(x);
    }
    ll i = 0;
    ll left_child = 2*i + 1;
    ll right_child = 2*i + 2;

    while(left_child < num_node && right_child < num_node)
    {
        tree[i]->left = tree[left_child];
        tree[i]->right = tree[right_child];
        //printf("node i : %lld, has left_child(%lld), and right child(%lld)\n", i, left_child, right_child);
        i++;
        left_child = 2*i + 1;
        right_child = 2*i + 2;
    }
    in_order(tree[0]);
    printf("\n");
    invert_tree(&tree[0]);
    in_order(tree[0]);
    /*char x[5] = "123";
    invert_num(x);
    printf("%s", x);*/


    return 0;
}