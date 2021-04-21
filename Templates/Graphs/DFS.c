#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ll long long int
#define BOOL int
#define TRUE 1
#define FALSE 0

struct node
{
    ll value;
    struct node* next;
};

struct node* create_node(ll val)
{
    struct node* newNode =  (struct node*)malloc(sizeof(struct node*));
    newNode->value = val;
    newNode->next = NULL;
    return newNode;
}

void add_edge(struct node* graph[], ll start, ll end)
{
    struct node* newNode = create_node(end);
    newNode->next = graph[start]->next;
    graph[start]->next = newNode;
}

void DFS(struct node* graph[], ll root, ll num_vert, BOOL visited[])
{
    visited[root] = TRUE;
    printf("%lld ",root);
    struct node* iter = graph[root]->next;
    while(iter != NULL)
    {
        if(visited[iter->value] == FALSE)
        {
            visited[iter->value] = TRUE;
            //printf("%lld ", iter->value);
            DFS(graph, iter->value, num_vert, visited);
        }
        iter = iter->next;
    }
}

int main(int argc, char const *argv[])
{
    ll num_vert, num_edge;
    scanf("%lld%lld", &num_vert, &num_edge);
    BOOL visited[num_vert];
    for (ll i = 0; i < num_vert; i++)
    {
        visited[i] = FALSE;
    }

    struct node* graph[num_vert];
    for (ll i = 0; i < num_vert; i++)
    {
        graph[i] = create_node(i);
    }
    for (ll i = 0; i < num_edge; i++)
    {
        ll start, end;
        scanf("%lld%lld", &start, &end);
        add_edge(graph, start, end);
        add_edge(graph, end, start);
    }
    DFS(graph, 0, num_vert, visited);
    return 0;
}
