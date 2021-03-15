#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
 
#define N 500
#define ull unsigned long long int
#define ll long long int
#define INF 9223372036854775807LL
 
ll adj_mat[N][N];
ll cost[N];


//making adjacency matrix--------------------------------------------------------------------------------
void adjacency_mat(int vert, int edge)
{
    int EDGE_BEG, EDGE_END;

    for (int i = 0; i < vert; i++)
    {
        for (int j = 0; j < vert; j++)
        {
            adj_mat[i][j] = 0;
        }
    }
    for(int i = 0; i < edge; i++)
    {
        int wt;
        scanf("%d%d%d", &EDGE_BEG, &EDGE_END, &wt);
        //printf("%d, %d\n", EDGE_BEG, EDGE_END);
        adj_mat[EDGE_BEG][EDGE_END] = wt;
        adj_mat[EDGE_END][EDGE_BEG] = wt;
    }  
}
void printMat(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", adj_mat[i][j]);
        }
        printf("\n");
        
    }
    
}
//----------------------------------------------------------------------------------------------------------------

// heaps and helper functions------------------------------------------------------------------------------------
ll min(ll x, ll y) 
{
    return x < y ? x : y; 
}
 
void swap(ll *a, ll *b) {
    ll temp = *a;
    *a = *b;
    *b = temp;
}
 
void minHeapify(ll arr[], int *heap_size, ll i) {
    if (*heap_size == 1) return;
    if (i >= (*heap_size) / 2) return;
 
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
 
    if (left < (*heap_size) && cost[arr[left]] < cost[arr[smallest]])
        smallest = left;
 
    if (right < (*heap_size) && cost[arr[right]] < cost[arr[smallest]])
        smallest = right;
 
    if (smallest != i) 
    {
        swap(arr + i, arr + smallest);
        minHeapify(arr, heap_size, smallest);
    }
}
 
void push(ll heap[], int *heap_size, ll val) 
{
    if ((*heap_size) == 0) 
    {
        heap[(*heap_size)++] = val;
        return;
    }
    heap[(*heap_size)++] = val;
    
    for (int i = (*heap_size) / 2 - 1; i > -1; --i) minHeapify(heap, heap_size, i);
}
 
ll peek(ll heap[], int *heap_size) 
{
    if ((*heap_size) <= 0) return -1;
 
    if ((*heap_size) == 1) 
    {
        (*heap_size)--;
        return heap[0];
    }
 
    ll val = heap[0];
    heap[0] = heap[(*heap_size) - 1];
    (*heap_size)--;
    minHeapify(heap, heap_size, 0);
    return val;
}
 
/*void printHeap(ll harr[], int *size) {
    for (int i = 0; i < (*size); i++) {
        printf("%lld ", harr[i]);
    }
 
    printf("\n");
}*/
//-----------------------------------------------------------------------------------------------------------------------------

// dijkstra's algorithm----------------------------------------------------------------------------------------------------------
void djikstra(int num_vert, int source) 
{
    int visited[N] = {0};
 
    for (int i = 0; i < num_vert; i++) {
        cost[i] = INF;
    }
 
    cost[source] = 0;
    ll p_q[N];
    int pq_Size = 0;
 
    push(p_q, &pq_Size, source);
    while (pq_Size > 0) 
    {
        ll small = peek(p_q, &pq_Size);
        visited[small] = 1;
 
        for (int i = 0; i < num_vert; i++) 
        {
            if (adj_mat[small][i] && !visited[i]) 
            {
                cost[i] = min(cost[i], cost[small] + adj_mat[small][i]);
 
                push(p_q, &pq_Size, i);
            }
        }
    }
 
    for (int i = 0; i < num_vert; i++) 
    {
        printf("%lld ", cost[i]);
    }
}
//--------------------------------------------------------------------------------------------------------------------------------


int main() {
    int num_vert, num_edge, source;
    ll w;
    scanf("%d %d %d", &num_vert, &num_edge, &source);
 
    adjacency_mat(num_vert, num_edge);
    //printMat(num_vert);
    djikstra(num_vert, source);
    return 0;
}