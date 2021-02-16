#include <stdio.h>
#include <math.h>

#define N 10000
int vert;
int edge;
int visited[N];
int dfs_ctr = 0;


void adjacency_mat(int adj_mat[vert][vert])
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
        scanf("%d%d", &EDGE_BEG, &EDGE_END);
        //printf("%d, %d\n", EDGE_BEG, EDGE_END);
        adj_mat[EDGE_BEG][EDGE_END] = 1;
        adj_mat[EDGE_END][EDGE_BEG] = 1;
    }  
}

// sort
void insertionSort(int arr[], int n) 
{ 
    int i, key, j; 
    for (i = 1; i < n; i++) { 
        key = arr[i]; 
        j = i - 1; 
        while (j >= 0 && key < arr[j]) { 
            arr[j + 1] = arr[j]; 
            j = j - 1; 
        } 
        arr[j + 1] = key; 
    } 
} 

void DFS(int adj_mat[vert][vert], int i)
{
    visited[i] = 1;
    dfs_ctr++;
    //printf("%d ",i);
    for (int j = 0; j < vert; j++)
    {
        if(adj_mat[i][j] == 1)
        {
            if (visited[j] == 0)
            {
                DFS(adj_mat, j);
            }       
        }
    }
}

int main(int argc, char const *argv[])
{
    int sum = 0;
    scanf("%d%d", &vert, &edge);
    int adj_mat[vert][vert];
    int clusterSizes[10000];
    int ctr = 0;
    adjacency_mat(adj_mat);
    //printMat(vert, adj_mat);
    for (int i = 0; i < vert; i++)
    {
        if(visited[i] != 1)
        {
            DFS(adj_mat, i);
            
            //printf("%d ", dfs_ctr);
            clusterSizes[ctr] = dfs_ctr;
            ctr++;
            dfs_ctr = 0;
        }
    }
    insertionSort(clusterSizes, ctr);
    for (int i = 0; i <= ctr; i++)
    {
        sum += clusterSizes[i];
        if(sum >= (0.8*vert))
        {
            printf("%d", i);
            return 0;
        }
    }
    



    return 0;
}
