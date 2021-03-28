#include <stdio.h>
#include <stdlib.h>


#define TRUE 1
#define FALSE 0
#define bool int

// STACK

struct node
{
    int val;
    int pos;
    struct node* next;
    //struct node* prev;
};

bool isEmpty(struct node* top)
{
    if(top != NULL)
        return FALSE;
    else 
        return TRUE;
}

struct node* createNode(int data, int index)
{
    struct node* newNode = (struct node*)malloc(sizeof(struct node*));
    newNode->val = data;
    newNode->pos = index;
    newNode->next = NULL;
    //newNode->prev = NULL;
    return newNode;
}

void push(struct node** top, int data, int index)
{
    struct node* newNode = createNode(data, index);
    newNode->next = (*top);
    (*top) = newNode;
    //printf("pushed value : %d to the stack at location : %d\n", (*top)->val, (*top)->pos);
    // (*head)->prev = NULL;
    //newNode->prev = (*head);
}

int pop(struct node** top)
{
    if(isEmpty(*top))
    {
        printf("illegal\n");
        return FALSE;
    }
    else    
    {
        struct node* temp = *top;
        (*top) = (*top)->next;
        int data = temp->val;
        free(temp);
        return data;
    }
}

int peek(struct node* top)
{
    if(isEmpty(top))
    {
        printf("no elements in stack!\n");
        return FALSE;
    }
    else
    {
        return top->val;
    }
}

void printStack(struct node** top)
{
    struct node* iter = *top;
    while(iter!= NULL)
    {
        printf("val  = %d, pos = %d || ", iter->val, iter->pos);
        iter = iter->next;
    }
    printf("\n");
}

void getNearestSmallerElement(int arr[], int size)
{
    int result[size];
    struct node* top = NULL;
    int buff;
    for(int i=0; i < size; i++)
    {
        /*printf("i = %d \n", i);
        if((top) != NULL)
            printf("top : %d\n", (top)->val);
        else
            printf("top is null!!!\n");*/
        while(!(isEmpty(top)) && (top)->val >= arr[i])
        {
            buff = pop(&top);
        }

        if(isEmpty(top))
        {
            result[i] = -1;
        }
        else
        {
            result[i] = top->pos;
        }
        push(&top, arr[i], i);
        //printStack(&top);
    }

    for(int i = 0;  i < size-1; i++)
    {
        if(result[i] != -1)
            printf("%d ", result[i] + 1);
        else
        {
            printf("%d ", result[i]);
        }
    }
    printf("%d", result[size-1] + 1);
}

int main(int argc, char const *argv[])
{
    int n, x;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        arr[i] = x;
        // push(&top, x);
    }
    getNearestSmallerElement(arr, n);
    return 0;
}
