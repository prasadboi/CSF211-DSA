#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// representing N1, N2, M as three queues

struct node
{
    int val;
    struct node* next;
    // struct node* prev;
};

//void create_node()

// function to append to a linked list
void append(struct node** head, int num)
{
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->val = num;
    newNode->next = NULL;

    if((*head) == NULL)
    {
        // newNode->prev = NULL;
        (*head) = newNode;
    }
    else
    {
        struct node* last = *head;
        while (last->next != NULL)
        {
            last = last->next;
        }
        last->next = newNode;
        // newNode->prev = last;
    }
}

// function to print a linked list
void printLL(struct node** head)
{
    struct node* iter = *head;
    while (iter != NULL)
    {
        printf("%d", iter->val);
        iter = iter->next;
    }
    printf("\n");
}

// function to pop out the head of the queue
int queue_Pop(struct node** head)
{
    struct node* temp = *head;
    (*head) = (*head)->next;
    return temp->val;
}

// function to generate joint number (as per question)

void join_queue(struct node** N_1, struct node** N_2, struct node** M)
{
    while((*N_1) != NULL && (*N_2) != NULL)
    {
        if((*N_1)->val > (*N_2)->val)
        {
            append(M, queue_Pop(N_1));
        }
        else
        {
            append(M, queue_Pop(N_2));
        }
    }

    if((*N_1) == NULL)
    {
        while((*N_2)!= NULL)
        {
            append(M, queue_Pop(N_2));
        }
    }
    else if((*N_2) == NULL)
    {
        while((*N_1) != NULL)
        {
            append(M, queue_Pop(N_1));
        }
    }

    printLL(M);

}

//main

int main(int argc, char const *argv[])
{
    struct node* N_1 = NULL;
    struct node* N_2 = NULL;
    struct node* M = NULL;

    // scanning the 2 queues
    // i/p list 1
    char c;
    scanf("%c", &c);
    while(c != '\n')
    {
        append(&N_1, (int)(c - '0'));
        scanf("%c", &c);
    }
    //printLL(&N_1);
    
    // i/p list 2
    scanf("%c", &c);
    while(c != '\n')
    {
        append(&N_2, (int)(c - '0'));
        scanf("%c", &c);
    }
    //printLL(&N_2);
    join_queue(&N_1, &N_2, &M);
    
    return 0;
}
