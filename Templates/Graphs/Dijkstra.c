#include <stdio.h>
#include <limits.h>
#define ll int
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





// dijkstra algo
int minDist(int dist[],int visited[],int V){
    int min = INT_MAX,min_index;
    for(int i = 0;i<V;i++){
        if(visited[i] == 0 && dist[i] <= min){
            min = dist[i];
            min_index = i;
        }
    }
    return min_index;
}
void djikstra(int V,int dist[],int visited[],int A[V][V],int S){
    dist[S] = 0;

    for(int c = 0;c < V-1;c++){
        int l = minDist(dist,visited,V);
		//printf("l is  : %lld\n", l);
        visited[l] = 1;

        for(int i = 0;i<V;i++){
            //printf("%d ",*(A+l*V + i));
            if(visited[i] == 0 && A[l][i]!=0 && dist[l] != INT_MAX && dist[l] + A[l][i] < dist[i]){
                dist[i] = dist[l] + A[l][i];
            }
        }
    }
}


// driver calls
int main() {
    int N,M,S;

    scanf("%d",&N);
    scanf("%d",&M);
    scanf("%d",&S);
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
    djikstra(N,dist,visited,A,S);
    print_array(dist, N);

    return 0;
}

/*
9 9 0
0 1 7
0 2 9
1 3 2
1 4 6
2 5 4
2 6 2
2 7 1
3 8 1
6 8 3
*/