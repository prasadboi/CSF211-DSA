#include <stdio.h>
#include <math.h>

int A;    // number of authors 
int vert; // vert = publication
int edge; // edge = citation

// creating adjacency matrix
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
        scanf("%d%d", &EDGE_END, &EDGE_BEG);
        //printf("%d, %d\n", EDGE_BEG, EDGE_END);
        adj_mat[EDGE_BEG ][EDGE_END] = 1;
        //adj_mat[EDGE_END][EDGE_BEG] = 1;
    }  
}

// printing adjacency matrix
/*void printMat(int n, int adj_mat[n][n])
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

int sumArr(int arr[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    return sum;
}

int main(int argc, char const *argv[])
{
    scanf("%d%d%d", &A, &vert, &edge);
    int adj_mat[vert][vert];
    int authOfPub[vert];

    for (int i = 0; i < vert; i++)
    {
        scanf("%d", &authOfPub[i]);
    }
    adjacency_mat(adj_mat);
    //printMat(vert, adj_mat);

    for(int i= 0; i < A; i++)
    {
        int h_index = 10000;
        for (int j = 0; j < vert; j++)
        {
            //printf("%d ", j);
            if(authOfPub[j] == i)
            {
                //printf("in if ");
                if(h_index > sumArr(adj_mat[j], vert))
                    h_index = sumArr(adj_mat[j], vert);
            }
        }
        printf("%d ", h_index);
    }



    return 0;
}
