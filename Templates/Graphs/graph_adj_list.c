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
    struct node* newNode = (struct node* )malloc(sizeof(struct node*));
    newNode->value = val;
    newNode->next = NULL;
}

void add_edge(struct node* graph[], ll start, ll end){
    struct node* temp1 = create_node(start);
    struct node* temp2 = create_node(end);

    temp2->next = graph[start]->next;
    graph[start]->next = temp2;

    /*temp1->next = graph[end]->next;
    graph[end]->next = temp1;*/

    printf("added edge %lld->%lld\n", graph[start]->value, graph[start]->next->value); 
    /*printf("added edge %lld->%lld\n", graph[end]->value, graph[end]->next->value);*/ 
}

void print_adj_list(struct node* graph[], ll vert)
{
    for(ll i = 0; i < vert; i++)
    {
        printf("%lld : ", i);
        struct node* iter = graph[i]->next;
        while(iter != NULL)
        {   
            printf("%lld ", iter->value);
            iter = iter->next;
        }
        printf("\n");
    }
}

int main()
{
    ll num_vert, num_edge;
    scanf("%lld%lld", &num_vert, &num_edge);
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
    print_adj_list(graph, num_vert);
    return 0;
}