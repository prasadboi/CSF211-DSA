#include <stdio.h>
#include <stdlib.h>
int vert;
int edge;

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

int canGraphBeColoured(int adj_mat[vert][vert], int COLOR[vert], int x)
{
    int isConsistent = 1;
    for (int i = 0; i < vert; i++)
    {
        for (int j = i+1; j < vert; j++)
        {
            if((adj_mat[i][j] == 1)&&(COLOR[i] == COLOR[j]))
                isConsistent = 0;
        }
        
    }

    if (x == vert)
    {
        if(isConsistent)
        {
            for (int i = 0; i < vert; i++)
            {
                if(COLOR[i] == 1)
                    printf("R");
                else if(COLOR[i] == 2)
                    printf("B");
            }
            return 1;
            
        }
        return 0;
    }

    for (int i = 1; i <= 2; i++)
    {
        COLOR[x] = i;

        if(canGraphBeColoured(adj_mat, COLOR, x+1))
        {
            return 1;
        }
        COLOR[x] = 0;
        
    }
    
    return 0;
    
}

int main(int argc, char const *argv[])
{
    scanf("%d%d", &vert, &edge);
    int adj_mat[vert][vert];
    adjacency_mat(adj_mat);
    int COLOR[vert];
    for (int i = 0; i < vert; i++)
    {
        COLOR[i] = 0;
    }
    
    if(!canGraphBeColoured(adj_mat, COLOR, 0))
        printf("NEED MORE COLOURS");
    return 0;
}
