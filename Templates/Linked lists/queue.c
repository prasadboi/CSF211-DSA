#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ll long long int
#define BOOL int
#define TRUE 1
#define FALSE 0
#define LL_MAX 1000000007

// queue
struct node {
    ll value;
    struct node *next;
};

struct node* create_node(ll val)
{
    struct node* newNode = (struct node*)malloc(sizeof(struct node*));
    newNode->value = val;
    newNode->next = NULL;
    return newNode;
}

// enqueue
void enqueue(struct node** head, struct node** last, ll val)
{
    struct node* newNode = create_node(val);
    if((*last) == NULL)
    {
        *head = newNode;
        *last = newNode;
        return;
    }
    (*last)->next = newNode;
    (*last) = newNode;
    printf("pushed succesfully the value %lld\n", (*last)->value);
    return;
}


// get rear val of the queue
ll rear(struct node** head, struct node** last)
{
    return (*last)->value;
}

// dequeue from the queue
ll dequeue(struct node** head, struct node** last)
{
    if((*last) == NULL)
    {
        printf("the queue is empty !!!\n");
        return -10000007;
    }
    else if((*last) == (*head))
    {
        ll front = (*head)->value;
        (*head) = NULL;
        (*last) = NULL;
        return front;
    }
    ll front = (*head)->value;
    struct node* temp = (*head);
    (*head) = (*head)->next;
    free(temp);
    return front;
}

// print the queue
void print_queue(struct node** head, struct node** last)
{
    struct node* iter = (*head);
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
    struct node* last = NULL;
    for (ll i = 0; i < num; i++)
    {
        ll temp;
        scanf("%lld", &temp);
        enqueue(&head, &last, temp);
    }

    print_queue(&head, &last);
    printf("popped value:  %lld\n", dequeue(&head, &last));
    print_queue(&head, &last);
    return 0;
}
