#include <stdio.h>
#include <math.h>
#include <stdlib.h>

struct queue {
  int items[5000];
  int front;
  int rear;
};

struct node 
{
    int node_name;
    struct node* next;
};

struct GRAPH
{
    int graph_num;
    struct node** adjList; // behaves as head pointer of each adj list dropping down from each node
    int* visited;
};

struct node* makeNode(int data)
{
    struct node* newNode = malloc(sizeof(struct node));
    newNode->node_name = data;
    newNode->next = NULL;
    return newNode;
}

struct GRAPH* makeGraph(int numVert)
{
    struct GRAPH* newGRAPH = malloc(sizeof(struct GRAPH));
    newGRAPH->graph_num = numVert;
    newGRAPH->adjList = malloc(numVert*(sizeof(struct node)));
    newGRAPH->visited = malloc(numVert * sizeof(int));

    // now initialize graph
    for (int i = 0; i < numVert; i++)
    {
        newGRAPH->adjList[i] = NULL;
        newGRAPH->visited[i] = 0;
    }
    return newGRAPH;
}

void constructGRAPH(int numHops, struct GRAPH* graph)
{
    for (int i = 0; i < numHops; i++)
    {
        int node1, node2;
        scanf("%d%d", &node1, &node2);
        // for node1 to node 2
        struct node* temp = makeNode(node2);
        temp->next = graph->adjList[node1];
        graph->adjList[node1] = temp;
        // for reverse
        temp = makeNode(node1);
        temp->next = graph->adjList[node2];
        graph->adjList[node2] = temp;
    }
}

// Create a queue
struct queue* createQueue() {
  struct queue* q = malloc(sizeof(struct queue));
  q->front = -1;
  q->rear = -1;
  return q;
}

// Check if the queue is empty
int isEmpty(struct queue* q) {
  if (q->rear == -1)
    return 1;
  else
    return 0;
}

// Adding elements into queue
void enqueue(struct queue*  q, int value) {
  if (q->rear == 5000 - 1)
    printf("\nQueue is Full!!");
  else {
    if (q->front == -1)
      q->front = 0;
    q->rear++;
    q->items[q->rear] = value;
  }
}

// Removing elements from queue
int dequeue(struct queue* q) {
  int item;
  if (isEmpty(q)) {
    //printf("Queue is empty");
    item = -1;
  } else {
    item = q->items[q->front];
    q->front++;
    if (q->front > q->rear) {
      //printf("Resetting queue ");
      q->front = q->rear = -1;
    }
  }
  return item;
}

// Print the queue
void printQueue(struct queue* q) {
  int i = q->front;

  if (isEmpty(q)) {
    printf("Queue is empty");
  } else {
    //printf("\nQueue contains \n");
    for (i = q->front; i < q->rear + 1; i++) {
      printf("%d ", q->items[i]);
    }
  }
}

int bfs(struct GRAPH* graph, int startVertex, int endVertex)//, int v, int pred[], int dist[]) 
{
  struct queue* q = createQueue();

  graph->visited[startVertex] = 1;
  enqueue(q, startVertex);

  while (!isEmpty(q)) {
    int currentVertex = dequeue(q);

    struct node* temp = graph->adjList[currentVertex];

    while (temp) {
      int adjVertex = temp->node_name;

      if (graph->visited[adjVertex] == 0) {
        graph->visited[adjVertex] = graph->visited[currentVertex] + 1;
        enqueue(q, adjVertex);
      }
      if (adjVertex == endVertex)
      {
        return graph->visited[currentVertex];
      }
      
      temp = temp->next;
    }
  }
}


int main(int argc, char const *argv[])
{
    int nCities, nHops, city1, city2;
    scanf("%d%d%d%d", &nCities, &nHops, &city1, &city2);
    struct GRAPH* graph = makeGraph(nCities);
    constructGRAPH(nHops, graph);
    printf("%d",100*bfs(graph, city1, city2));

    return 0;
}
