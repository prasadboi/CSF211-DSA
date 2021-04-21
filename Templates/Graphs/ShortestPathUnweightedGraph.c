#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ll long long int
#define BOOL int
#define TRUE 1
#define FALSE 0
#define LL_MAX 1000000007

void print_array(ll arr[], ll length)
{
    for (ll i = 0; i < length; i++)
    {
        printf("%lld ", arr[i]);
    }
    printf("\n");    
}

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


void BFS(struct node** qhead, struct node** qtail, struct node* graph[], ll root, ll dest, ll vert, ll pred[], ll distance[])
{
    printf("doing BFS :\n");

    BOOL visited[vert];
    for(ll i = 0; i < vert; i++)
        visited[i] = FALSE;
    
    
    // first element
    enqueue(qhead, qtail, root);
    //print_queue(qhead, qtail);
    visited[root] = TRUE;
    printf("%lld ", root);
    distance[root] = 0;
    // no predecessors for root

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

                distance[iter->value] = distance[front] + 1;
                pred[iter->value] = front;

                if(iter->value == dest)
                {
                    printf("reached !!!\n");
                    return;
                }
            }
            iter = iter->next;
        }
        //printf("iter is NULL\n");
    }
    printf("\n");
}

void shortest_path(ll distance[], ll pred[], ll dest, ll vert)
{
    printf("length of the shortest path is : %lld\n", distance[dest]);

    ll path[vert];
    for(ll i = 0; i < vert; i++)
    {
        path[vert] = -1;
    }
    ll i = 0;
    ll x = dest;
    while(x != -1)
    {
        path[i] = x;
        i++;
        x = pred[x];
    }

    printf("printing path in reverse order :\n");
    print_array(path, distance[dest]+1);
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

    ll distance[6] = {INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX};
    ll pred[6] = {-1, -1, -1, -1, -1, -1};

    BFS(&qhead, &qtail, graph, 2, 5, 6, pred, distance);
    print_array(distance, 6);
    print_array(pred, 6);
    shortest_path(distance, pred, 5, 6);
    return 0;
}