#include <stdio.h>
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

void printMat(int n, int adj_mat[vert][vert])
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

void DFS(int adj_mat[vert][vert], int i)
{
    visited[i] = 1;
    dfs_ctr++;
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
    scanf("%d%d", &vert, &edge);
    int adj_mat[vert][vert];
    adjacency_mat(adj_mat);
    printMat(vert, adj_mat);
    for (int i = 0; i < vert; i++)
    {
        if(visited[i] != 1)
        {
            DFS(adj_mat, i);
            printf("%d ", dfs_ctr);
            dfs_ctr = 0;
        }
    }
    
    return 0;
}
