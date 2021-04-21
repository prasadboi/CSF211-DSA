#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ll long long int


// node of bintree
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

//----------------------------------------------------------------------------------------------------------------------------------------
struct s_node 
{
    struct node* value;
    struct s_node* next;
};

struct s_node* create_s_node(struct node* val)
{
    struct s_node* newNode = (struct s_node*)malloc(sizeof(struct s_node*));
    newNode->value = val;
    newNode->next = NULL;
    return newNode;
}

void push(struct s_node** head, struct node* val)
{
    struct s_node* newNode = create_s_node(val);
    if((*head) == NULL)
    {
        (*head) = newNode;
        printf("appended node with value : %lld\n", newNode->value->value);
        return; 
    }
    newNode->next = *head;
    (*head) = newNode;
    printf("appended node with value : %lld\n", newNode->value->value);
}

struct node* pop(struct s_node** head)
{
    if((*head) == NULL)
    {
        printf("nope\n");
        return NULL;
    }
    struct s_node* temp = (*head);
    (*head) = (*head)->next;
    struct node* x = temp->value;
    //free(temp);
    return x;
}
//----------------------------------------------------------------------------------------------------------------------------------------

// inorder--------------------------------------------------------------------------------------------------------------------------------
void inorder_traversal(struct s_node** head, struct node* root)
{
    struct node* iter = root;
    int flag = 0;
    while(flag == 0)
    {
        if(iter != NULL)
        {
            push(head, iter);
            iter = iter->left;
        }
        else
        {
            if(head != NULL)
            {
                iter = pop(head);
                if(iter == NULL)
                    break;
                printf("inorder : %lld \n", iter->value);
                iter = iter->right;
            }
            else
                flag == 1;
        }
    }
}

int main(int argc, char const *argv[])
{
    ll num_nodes = 0;
    scanf("%lld", &num_nodes);

    struct s_node* head = NULL;

    // building the tree
    struct node* tree[num_nodes];
    for(ll i = 0; i < num_nodes; i++)
    {
        ll x;
        scanf("%lld",&x);
        tree[i] = create_node(x);
        printf("added node with value : %lld\n", tree[i]->value);
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

    inorder_traversal(&head, tree[0]);
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