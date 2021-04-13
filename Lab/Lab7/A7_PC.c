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
    printf("pushed value : %d to the stack at location : %d\n", (*top)->val, (*top)->pos);
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

void getNearestSmallerElement(int arr[], int size, int result[])
{
    struct node* top = NULL;
    int buff;
    for(int i=0; i < size; i++)
    {
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
    }

    for(int i = 0;  i < size; i++)
    {
        result[i] = result[i] + 1;
        //printf("%d ", result[i]);
    }
    //printf("\n");
}

int find_max_rectangle(int arr[], int reverse_arr[], int n)
{
    int left_arr[n];
    int right_arr[n];
    int max_vol = -1;
    int vol;
    getNearestSmallerElement(arr, n, left_arr);
    getNearestSmallerElement(reverse_arr, n, right_arr);
    for(int i = 0; i <n; i++)
    {
        vol = 1*((n-right_arr[n-i-1]) - left_arr[i])*arr[i];
        //printf("vol : %d\n", vol);
        if (max_vol < vol)
        {
            max_vol = vol;
        }
    }
    //printf("max vol is : %d\n", max_vol);
    return max_vol;
}

void print_arr(int arr[], int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(int argc, char const *argv[])
{
    int n, x, m;
    int max_rectangle = -1;
    scanf("%d%d", &n, &m);
    int arr[m], reverse_arr[m];
    for (int i = 0; i < m; i++)
    {
        arr[i] = 0;
        reverse_arr[i] = 0;
    }
    
    for (int j = 0; j < n; j++)
    {
        //printf("row : %d\n", j);
        for (int i = 0; i < m; i++)
        {
            scanf("%d", &x);
            if(x == 0)
            {
                arr[i] = 0;
            }
            else if(x > 0)
            {
                arr[i] += x;
            }
            for (int k = 0; k < m; k++)
            {
                reverse_arr[m-k-1] = arr[k];
            }
        }
        printf("printing forwards : \n");
        print_arr(arr, m);
        printf("printing backwards : \n");
        print_arr(reverse_arr, m);
        int max = find_max_rectangle(arr, reverse_arr, m);
        if(max_rectangle < max)
            max_rectangle = max;
    }
    printf("%d\n", max_rectangle);
    return 0;
}
