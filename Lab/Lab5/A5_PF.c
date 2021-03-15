#include <stdio.h>
#include <stdlib.h>

#define N 10000
int vert;
int edge;
int* visited;
//int dfs_ctr = 0;



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
        adj_mat[EDGE_BEG-1][EDGE_END-1] = 1;
        adj_mat[EDGE_END-1][EDGE_BEG-1] = 1;
    }  
}

/*void printMat(int n, int adj_mat[vert][vert])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", adj_mat[i][j]);
        }
        printf("\n");
        
    }
    
}*/

void DFS(int adj_mat[vert][vert], int i,int done)
{
    visited[i] = 1;
    //dfs_ctr++;
    printf("%d ",i+1);
    int min=vert+1;
    for(int k=0;k<vert;k++)
    {
    	if(visited[k]==1)
    	{
    	for (int j = 0; j < vert; j++)
    	{
            if(adj_mat[k][j] == 1 && j<min && visited[j]==0)
            {
            	    //if (visited[j] == 0)
            	    //{
                	//DFS(adj_mat, j);
            	    //}       
                min=j;
            }
    	}
    	}
    }
    done++;
    if(done<=vert)
    DFS(adj_mat,min,done);
}    

int main(int argc, char const *argv[])
{
    scanf("%d%d", &vert, &edge);
    int adj_mat[vert][vert];
    visited = malloc(vert*sizeof(int*));
    for (int i = 0; i < vert; i++)
    {
        visited[i] =  0;
    }
    
    adjacency_mat(adj_mat);
    //printMat(vert, adj_mat);
    DFS(adj_mat, 0,1);
    
    return 0;
}