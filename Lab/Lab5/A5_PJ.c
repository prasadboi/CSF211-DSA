#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
 
#define N 500
#define ull unsigned long long int
#define ll long long int
#define INF 9223372036854775807LL
 
ll graph[N][N];
ll cost[N];

ll min(ll x, ll y) 
{
    return x < y ? x : y; 
}
 
void swap(ll *a, ll *b) {
    ll temp = *a;
    *a = *b;
    *b = temp;
}
 
void minHeapify(ll arr[], int *size, ll i) {
    if (*size == 1) return;
    if (i >= (*size) / 2) return;
 
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
 
    if (left < (*size) && cost[arr[left]] < cost[arr[smallest]])
        smallest = left;
 
    if (right < (*size) && cost[arr[right]] < cost[arr[smallest]])
        smallest = right;
 
    if (smallest != i) 
    {
        swap(arr + i, arr + smallest);
        minHeapify(arr, size, smallest);
    }
}
 
void push(ll heap[], int *size, ll key) 
{
    if ((*size) == 0) 
    {
        heap[(*size)++] = key;
        return;
    }
    heap[(*size)++] = key;
 
    for (int i = (*size) / 2 - 1; i >= 0; --i) minHeapify(heap, size, i);
}
 
ll peek(ll heap[], int *heap_size) 
{
    if ((*heap_size) <= 0) return -1;
 
    if ((*heap_size) == 1) 
    {
        (*heap_size)--;
        return heap[0];
    }
 
    ll key = heap[0];
    heap[0] = heap[(*heap_size) - 1];
    (*heap_size)--;
    minHeapify(heap, heap_size, 0);
    return key;
}
 
/*void printHeap(ll harr[], int *size) {
    for (int i = 0; i < (*size); i++) {
        printf("%lld ", harr[i]);
    }
 
    printf("\n");
}*/
 
void djikstra(int src, int n) 
{
    int visited[N];
 
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
        cost[i] = INF;
    }
 
    cost[src] = 0;
    ll p_q[N];
    int pq_Size = 0;
 
    push(p_q, &pq_Size, src);
    while (pq_Size > 0) 
    {
        ll u = peek(p_q, &pq_Size);
        visited[u] = 1;
 
        for (int i = 0; i < n; i++) 
        {
            if (graph[u][i] && !visited[i]) 
            {
                cost[i] = min(cost[i], cost[u] + graph[u][i]);
 
                push(p_q, &pq_Size, i);
            }
        }
    }
 
    for (int i = 0; i < n; i++) 
    {
        printf("%lld ", cost[i]);
    }
}
 
int main() {
    int n, m, s, u, v;
    ll w;
    scanf("%d %d %d", &n, &m, &s);
 
    for (int i = 0; i < m; ++i) {
        scanf("%d %d %lld", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w;
    }
    djikstra(s, n);
 
    return 0;
}