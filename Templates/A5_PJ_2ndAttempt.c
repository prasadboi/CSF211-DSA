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

//------------------------------------------------------------------------------------
// implementing priority queue/ min heap-----------------------------------------------
struct PQ
{
    int vertex;
    int dist;
};

void COPY(struct PQ* temp, struct PQ* A )
{
    (*temp).dist = (*A).dist;
    (*temp).vertex = (*A).vertex;

}

void swap(struct PQ *a, struct PQ *b)
{
    struct PQ temp;
    COPY(&temp, a);
    COPY(a, b);
    COPY(b, &temp);
}

void min_Heapify(struct PQ arr[], int i, int heap_size)
{
    int left = 2*i+1;
    int right = 2*i + 2;
    int smallest = i;
    if(left < heap_size && arr[left].dist < arr[i].dist)
        smallest = left;
    if(right < heap_size && arr[right].dist < arr[smallest].dist)
        smallest = right;
    if(smallest != i)
    {
        struct PQ temp;
        COPY(&temp, &arr[i]);
        COPY(&arr[i], &arr[smallest]);
        COPY(&arr[smallest], &temp);
        min_Heapify(arr, smallest, heap_size);
    }
}


void build_Min_Heap(struct PQ arr[], int N)
{
    int heap_size = N;
    for (int i = 0; i < (int)(N/2); i++)
    {
        min_Heapify(arr, i, heap_size);
    }
}

void print_heap(struct PQ heap[], int heap_size)
{
    for (int i = 0; i < heap_size; i++)
    {
        printf("%d : %d", heap[i].vertex, heap[i].dist);
    }
    printf("\n");
    
}

int pop_root_heap(struct PQ heap[], int *heap_size, struct PQ *root)
{
    COPY(root, &heap[0]);
    swap(&heap[0], &heap[(*heap_size)-1]);
    (*heap_size)--;
    min_Heapify(heap, 0, *heap_size);
    return root;
}

void insert_into_heap(struct PQ* heap[], int *heap_size, int vert, int dist)
{
    heap[(*heap_size)]->vertex = vert;
    heap[()]
    (*heap_size)++;
    swap(&heap[0], &heap[(*heap_size) - 1]);
    min_Heapify(heap, 0, *heap_size);
}

//-----------------------------------------------------------------------------
// Dijkstra's algorithm-------------------------------------------------------------

void dijkstra(struct Graph* graph, int source, int num_vert, int num_edge)
{
    int distance[num_vert];
    struct PQ priority_queue[num_vert];
    build_Min_Heap(priority_queue, num_vert);
    int pq_size = 0;

    for (int i = 0; i < num_vert; i++)
    {
        distance[i] = INFINITY;
        //insert_into_heap(priority_queue, pq_size, )
    }
    
}


//----------------------------------------------------------------------------------
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
    
    // calling Dijkstra-----------------------------------------------------------------


    return 0;
}
