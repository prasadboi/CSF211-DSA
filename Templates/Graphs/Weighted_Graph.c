#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define bool int
#define TRUE 1
#define FALSE 0

// creatng a weighted graph------------------------------------------------------------
struct Edge
{
    int src;
    int dest;
    int weight;
};

struct Node
{
    int vertex;
    int weight;
    struct Node* next;
};

struct Graph
{
    struct Node** head;
};

struct Graph* create_graph(int num_vert, int num_edge, struct Edge edges[])
{
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->head = (struct Node**)malloc(num_vert*sizeof(struct Node*));
    for (int i = 0; i < num_vert; i++)
    {
        graph->head[i] = NULL;
    }
    // adding edges to the graph
    for (int i = 0; i < num_edge; i++)
    {
        int src = edges[i].src;
        int dest = edges[i].dest;
        int weight = edges[i].weight;

        struct Node* temp = (struct Node*)malloc(sizeof(struct Node*));
        temp->vertex = dest;
        temp->weight = weight;
        temp->next = graph->head[src];
        graph->head[src] = temp;

        temp = (struct Node*)malloc(sizeof(struct Node*));
        temp->vertex = dest;
        temp->weight = weight;
        temp->next = graph->head[dest];
        graph->head[dest] = temp;
    }
    return graph;
}

void printGraph(struct Graph* graph, int num_vert)
{
    for (int i = 0; i < num_vert; i++)
    {
        struct Node* iter = graph->head[i];
        while(iter != NULL)
        {
            printf(" %d -> %d ", i, iter->vertex, iter->weight);
            iter = iter->next;
        }
        printf("\n");
    }
    
}
//------------------------------------------------------------
int main(int argc, char const *argv[])
{
    int num_vert = 0;
    int num_edge = 0;
    scanf("%d%d", &num_vert, &num_edge);

    // creating the graph using adjacency lists-------------------------------------
    struct Edge edges[num_edge];
    for (int i = 0; i < num_edge; i++)
    {
        int src, dst, weight;
        scanf("%d%d%d", &(edges[i].src), &(edges[i].dest), &(edges[i].weight));
    }
    
    struct Graph* graph = create_graph(num_vert, num_edge, edges);
    printGraph(graph, num_vert);
    //-----------------------------------------------------------------------------


    return 0;
}
