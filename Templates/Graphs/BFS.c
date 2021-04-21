#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ll long long int
#define BOOL int
#define TRUE 1
#define FALSE 0
#define LL_MAX 1000000007

struct node
{
    ll value;
    struct node* next;
};

struct node* create_node(ll val)
{
    struct node* temp = (struct node*) malloc(sizeof(struct node));
    temp->value = val;
    temp->next = NULL;
    return temp;
}

// making graph
void add_edge(struct node* graph[], ll start, ll end)
{
    struct node* newNode = create_node(end);
    newNode->next = graph[start]->next;
    graph[start]->next = newNode;
    printf("added edge %lld->%lld\n", graph[start]->value, newNode->value);
}

void print_graph(struct node* graph[], ll vert)
{
    for(ll i = 0; i < vert; i++)
    {
        struct node* iter = graph[i]->next;
        printf("%lld : ", graph[i]->value);
        while(iter != NULL)
        {
            printf("%lld ", iter->value);
            iter = iter->next;
        }
        printf("\n");
    }
}

// queue
void enqueue(struct node** head, struct node** last, ll val)
{
    struct node* newNode = create_node(val);
    if((*last) == NULL)
    {
        (*head) = newNode;
        (*last) = newNode;
        //printf("enqueued element %lld successfully\n", (*last)->value);
        return;
    }
    (*last)->next = newNode;
    (*last) = newNode;
    //printf("enqueued element %lld successfully\n", (*last)->value);
}

BOOL isEmpty(struct node** head, struct node** last)
{
    if((*last) == NULL)
        return TRUE;
    else return FALSE;
}

ll dequeue(struct node** head, struct node** last)
{
    if((*last) == NULL)
    {
        printf("the queue is empty !!!\n");
        return -LL_MAX; 
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

void print_queue(struct node** head, struct node** last)
{ 
    printf("queue : ");
    struct node* iter = (*head);
    while(iter != NULL)
    {
        printf("%lld ", iter->value);
        iter = iter->next;
    }
    printf("\n");
}


void BFS(struct node** qhead, struct node** qtail, struct node* graph[], ll root, ll vert)
{
    printf("doing BFS :\n");

    BOOL visited[vert];
    for(ll i = 0; i < vert; i++)
        visited[i] = FALSE;
    //printf("intialized visited array \n");
    // push the first element into the queue
    enqueue(qhead, qtail, root);
    //print_queue(qhead, qtail);
    visited[root] = TRUE;
    printf("%lld ", root);
    while((*qtail)!=NULL)
    {
        ll front = dequeue(qhead, qtail);
        
        struct node* iter = graph[front]->next;
        while(iter != NULL)
        {
            if(visited[iter->value] == FALSE)
            {
                enqueue(qhead, qtail, iter->value);
                //print_queue(qhead, qtail);
                visited[iter->value] = TRUE;
                printf("%lld ", iter->value);
            }
            iter = iter->next;
        }
        //printf("iter is NULL\n");
    }
    printf("\n");
}

// main

int main()
{
    struct node* graph[6];
    struct node* qhead = NULL;
    struct node* qtail = NULL;

    for(ll i = 0; i  <6; i++)
    {
        graph[i] = create_node(i);
    }

    add_edge(graph, 0, 1);
    add_edge(graph, 1, 0);
    add_edge(graph, 0, 2);
    add_edge(graph, 2, 0);
    add_edge(graph, 0, 3);
    add_edge(graph, 3, 0);
    add_edge(graph, 1, 4);
    add_edge(graph, 4, 1);
    add_edge(graph, 1, 5);
    add_edge(graph, 5, 1);

    print_graph(graph, 6);

    BFS(&qhead, &qtail, graph, 2, 6);
    return 0;
}