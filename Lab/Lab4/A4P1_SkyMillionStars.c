#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define TRUE (int)1
#define FALSE (int)0

#define N 26

int ans[26] = {0};
int rear = 0;
int parent[26] = {0};

// GRAPH operations -----------------------------------------------------------------------------------------------------
struct Node 
{
    int val;
    struct Node* next;
};

struct Graph 
{
    int numVertices;
    struct Node** adjList;
};
struct Node* createNode(int v) 
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->val = v;
    node->next = NULL;
    return node;
}

struct Graph* createGraph(int vertices) 
{
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));

    graph->numVertices = vertices;
    graph->adjList = malloc(vertices * sizeof(struct Node*));
    for (int i = 0; i < vertices; ++i) {
        graph->adjList[i] = NULL;
    }
    return graph;
}

void addEdge(struct Graph* graph, int s, int d) {
    struct Node* node = createNode(d);
    node->next = graph->adjList[s];
    graph->adjList[s] = node;
}

void printGraph(struct Graph* graph) {
    int iter;
    for (iter = 0; iter < graph->numVertices; iter++) 
    {
        struct Node* temp = graph->adjList[iter];
        printf("\n Vertex %d: ", iter);
        while (temp) {
            printf("%d -> ", temp->val);
            temp = temp->next;
        }
        printf("\n");
    }
}
//-----------------------------------------------------------------------------------------------------------------------
// Depth first search----------------------------------------------------------------------------------------------------
int DFS(struct Graph* graph, int beg, int visited[N]) 
{
    visited[beg] = 1;

    for (struct Node* iter = graph->adjList[beg]; iter != NULL; iter = iter->next) 
    {
        if (visited[iter->val] == 0) 
        {
            parent[iter->val] = beg;
            if (DFS(graph, iter->val, visited)) 
            {
                return TRUE;
            }
        } 
        else if (visited[iter->val] == 1) 
        {
            return TRUE;
        }
    }
    visited[beg] = 2;
    ans[rear++] = beg;
    return FALSE;
}
//---------------------------------------------------------------------------------------------------------------------------

//topological sort----------------------------------------------------------------------------------------------------------
void topologicalSort(struct Graph* graph, int charset[N]) {
    int visited[N] = {0};

    for (int i = 0; i < N; ++i) 
    {
        if (charset[i] && !visited[i]) 
        {
            if (DFS(graph, i, visited)) 
            {
                printf("ALIENS BE CRAZY");
                
                return;
            }
        }
    }

    for (int i = rear - 1; i >= 0; i--) 
    {
        printf("%c", (char)(ans[i] + 'A'));
    }
}
// -----------------------------------------------------------------------------------------------------------------------------


int main() 
{
    int n = N, m;
    char u, v;
    scanf("%d%*c", &m);

    struct Graph* AlienLang = createGraph(n);

    int charac[N] = {0};

    for (int i = 0; i < m; ++i) {
        scanf("%c %c%*c", &u, &v);
        addEdge(AlienLang, (int)u - 'A', (int)v - 'A');
        charac[(int)u - 'A'] = 1;
        charac[(int)v - 'A'] = 1;
    }
    topologicalSort(AlienLang, charac);

    return 0;
}