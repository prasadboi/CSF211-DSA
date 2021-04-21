#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ll int
#define BOOL int
void print_array(ll arr[], ll n)
{
    for (size_t i = 0; i < n; i++)
    {
        printf("%lld ", arr[i]);
    }
    printf("\n");
}

void printMat(int n, int adj_mat[n][n])
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

// min heap  = priority queue

void swap(ll *a, ll *b){ll temp = *a; *a = *b; *b = temp;}
ll left_child(ll i){return 2*i + 1;}
ll right_child(ll i){return 2*i + 2;}
ll parent(ll i){return (ll)((i-1)/2);}

// min heapify down
void min_heapify_down(ll heap[], ll heap_size, ll i)
{
    ll left = left_child(i);
    ll right = right_child(i);
    ll minimum = i;

    if(left < heap_size && heap[left] < heap[i])
        minimum = left;
    if(right < heap_size && heap[right] < heap[minimum])
        minimum = right;
    if(minimum != i)
    {
        swap(&heap[minimum], &heap[i]);
        min_heapify_down(heap, heap_size, minimum);
    }
}

void min_heapify_up(ll heap[], ll heap_size, ll i)
{
    ll p = parent(i);
    if(p >= 0 && heap[p] > heap[i])
    {
        swap(&heap[p], &heap[i]);
        min_heapify_up(heap, heap_size, p);
    }
}

void insert(ll heap[], ll *heap_size, ll val)
{
    (*heap_size)++;
    heap[(*heap_size) - 1] = val;
    min_heapify_up(heap, (*heap_size), (*heap_size)-1);
}

ll poll(ll heap[], ll *heap_size)
{
    ll root = heap[0];
    swap(&heap[0], &heap[(*heap_size) - 1]);
    (*heap_size)--;
    min_heapify_down(heap, (*heap_size), 0);
    return root;
}

// adjacency matrix

void adjacency_mat(ll vert, ll edge, ll adj_mat[vert][vert])
{
    int EDGE_BEG, EDGE_END;

    for (ll i = 0; i < vert; i++)
    {
        for (ll j = 0; j < vert; j++)
        {
            adj_mat[i][j] = 0;
        }
    }
    for(ll i = 0; i < edge; i++)
    {
        ll wt;
        scanf("%d%d%d", &EDGE_BEG, &EDGE_END, &wt);
        //printf("%d, %d\n", EDGE_BEG, EDGE_END);
        adj_mat[EDGE_BEG][EDGE_END] = wt;
        adj_mat[EDGE_END][EDGE_BEG] = wt;
    }  
}


// dijkstra's algorithm

void dijkstra(ll src, ll dist[], ll visited[], ll vert, ll adj_mat[vert][vert])
{

    ll heap[vert];
    ll heap_size = 0;
    dist[src] = 0;
    insert(heap, &heap_size, src);

    while(heap_size > 0)
    {
        // min dist node is at the top of the min heap
        ll u = poll(heap, &heap_size);
        printf("u : %d\n", u);
        visited[u] = 1;
        for(ll v = 0; v < vert; v++)
        {
            if((!visited[v]) && (adj_mat[u][v] != 0) && (dist[v] > dist[u] + adj_mat[u][v] ))
            {
                dist[v] = dist[u] + adj_mat[u][v];
                insert(heap, &heap_size, v);
            }
        }
    }
}

int main()
{
    int N,M,S;

    scanf("%d",&N);
    scanf("%d",&M);
    scanf("%d",&S);
    int heap[N];
    int heap_size = 0;
    int A[N][N];
	adjacency_mat(N, M, A);
	//printMat(N, A);
	int dist[N];
    int visited[N];
    int pred[N];
    for(int i = 0;i<N;i++){
        visited[i] = 0;
        dist[i] = INT_MAX;
    }
    dijkstra(S, dist, visited, N, A);
    print_array(dist, N);
    return 0;
}