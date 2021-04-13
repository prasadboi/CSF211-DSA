#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ll long long int
#define BOOL int
#define TRUE 1
#define FALSE 0




// queue -----------------------------------------------------------------------------------------------------------------

struct node 
{
    ll val;
    struct node *next;
};

void enqueue(struct node** head, struct node** tail, ll key)
{
    struct node* newNode = (struct node*)malloc(sizeof(struct node*));
    newNode->val = key;
    newNode->next = NULL;
    // newNode->prev = (*tail);

    if((*head) == NULL){
        *head = newNode;
        *tail = newNode;
        //printf("new head : %lld, new tail : %lld\n",(*head)->val,(*tail)->val);
        return;
    }

    (*tail)->next= newNode;
    (*tail) = newNode;
    //printf("new head : %lld, new tail : %lld\n",(*head)->val,(*tail)->val);
    return;
}

ll dequeue(struct node** head, struct node** tail)
{
    if(*head == NULL)
    {
        //printf("queue is empty!!!\n");
        return INT_MIN;
    }
    struct node* temp = (*head);
    (*head) = (*head)->next;
    return temp->val;
}

void printLL(struct node** head)
{
    //printf("printing : ");
    struct node* iter = (*head);
    while(iter != NULL)
    {
        printf("%lld ", iter->val);
        iter = iter->next;
    }
    printf("\n");
}
//----------------------------------------------------------------------------------------------------------




// SWAP------------------------------------------------------------------------------------------------------------------
void swap(struct node** a, struct node** b)
{
    struct node* temp = *a;
    *a = *b;
    *b = temp;
}
//------------------------------------------------------------------------------------------------------------------------




// STACK------------------------------------------------------------------------------------------------------
void push(struct node** q1_head, struct node** q1_tail, struct node** q2_head, struct node** q2_tail, ll key)
{
    enqueue(q1_head, q1_tail, key);
}

ll pop(struct node** q1_head, struct node** q1_tail, struct node** q2_head, struct node** q2_tail)
{
    // transfer all except last element from q1 to q2
    struct node* iter = *q1_head;
    while (iter->next != NULL)
    {
        enqueue(q2_head, q2_tail, dequeue(q1_head, q1_tail));
        iter = iter->next;
    }
    //printf("q1 : ");
    //printLL(q1_head);
    //printf("q2 : ");
    //printLL(q2_head);
    ll top = dequeue(q1_head, q1_tail);

    // swap the 2 queues
    swap(q1_head, q2_head);
    swap(q1_tail, q2_tail);

    return top;
}

ll print_top(struct node** q1_head, struct node** q1_tail, struct node** q2_head, struct node** q2_tail)
{
    struct node* top = (*q1_tail);
    return top->val;
}

int main(int argc, char const *argv[])
{
    /*
    // just testing out queue
    struct node* head = NULL;
    struct node* tail = head;
    for (ll i = 0; i < 5; i++)
    {
        enqueue(&head, &tail, i+1);
    }
    printLL(&head);
    dequeue(&head, &tail);
    dequeue(&head, &tail);
    printLL(&head);
    */

    struct node* q1_head = NULL;
    struct node* q1_tail = q1_head;

    struct node* q2_head = NULL;
    struct node* q2_tail = q2_head;

    
    // Checking STACK
    /*for (ll i = 0; i < 5; i++)
    {
        push(&q1_head, &q1_tail, &q2_head, &q2_tail, i+1);
    }
    
    printf("%lld\n", pop(&q1_head, &q1_tail, &q2_head, &q2_tail));
    printf("%lld\n", pop(&q1_head, &q1_tail, &q2_head, &q2_tail));
    printf("%lld\n", pop(&q1_head, &q1_tail, &q2_head, &q2_tail));
    printf("%lld\n", pop(&q1_head, &q1_tail, &q2_head, &q2_tail));
    printf("%lld\n", pop(&q1_head, &q1_tail, &q2_head, &q2_tail));*/
    

    ll num_query = 0; 
    scanf("%lld", &num_query);
    for (ll i = 0; i < num_query; i++)
    {
        char str[50];
        scanf("%s", str);
        ll x;
        if(strcmp(str, "PUSH") == 0)
        {
            scanf("%lld", &x);
            push(&q1_head, &q1_tail, &q2_head, &q2_tail, x);
        }
        else if(strcmp(str, "POP") == 0)
        {
            x = pop(&q1_head, &q1_tail, &q2_head, &q2_tail);
        }
        else if(strcmp(str, "PRINT") == 0)
        {
            printf("%lld\n", print_top(&q1_head, &q1_tail, &q2_head, &q2_tail));
        }
    }
    
    return 0;
}
