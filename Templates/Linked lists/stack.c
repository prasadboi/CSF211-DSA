#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ll long long int
#define BOOl int
#define TRUE 1
#define FALSE 0
#define LL_MAX 1000000007

// print an array
void print_array(ll arr[], ll length){
    for(ll i = 0; i < length; i++){
        printf("%lld ", arr[i]);
    }
    printf("\n");
}

// stack 

struct node
{
    ll value;
    struct node* next;
};

struct node* create_node(ll val)
{
    struct node* temp = (struct node*) malloc(sizeof(struct node*));
    temp->value = val;
    temp->next = NULL;
    return temp;
}

ll peek(struct node** head)
{
    return (*head)->value;
}

ll pop(struct node** head)
{
    ll top;
    struct node* temp = *head;
    top = (temp)->value;
    (*head) = (*head)->next;
    free(temp);
    return top;
}

void push(struct node** head, ll val)
{
    struct node* newNode = create_node(val);
    if((*head) == NULL)
    {
        //printf("the head is NULL!!!\nputting in value : %lld\n", val);
        (*head) = newNode;
        return;
    }
    //printf("putting in value : %lld\n", val);
    newNode->next = (*head);
    (*head) = newNode;
}

void print_stack(struct node** head)
{
    struct node* iter = *head;
    while(iter != NULL)
    {
        printf("%lld ", iter->value);
        iter = iter->next;
    }
    printf("\n");
}

int main(int argc, char const *argv[])
{
    ll num;
    scanf("%lld", &num);
    struct node* head = NULL;
    for (ll i = 0; i < num; i++)
    {
        ll temp;
        scanf("%lld", &temp);
        push(&head, temp);
    }

    print_stack(&head);
    printf("popped value:  %lld\n", pop(&head));
    print_stack(&head);
    return 0;
}

