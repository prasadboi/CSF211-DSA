#include <iostream>
#include <bits/stdc++.h>

using namespace std;



void adjacency_matrix(int vert, int edge, std::vector<std::vector<int>> *adj_mat)
{
    //std::cout << "creating adjacency matrix" << std::endl;
    int EDGE_BEG, EDGE_END;

    for (int i = 0; i < vert; i++)
    {
        for (int j = 0; j < vert; j++)
        {
            (*adj_mat)[i][j] = 0;
        }
    }
    for(int i = 0; i < edge; i++)
    {
        //std::cout << "edge number "<< i+1 << std::endl;
        scanf("%d%d", &EDGE_BEG, &EDGE_END);
        //printf("%d, %d\n", EDGE_BEG, EDGE_END);
        (*adj_mat)[EDGE_BEG][EDGE_END] = 1;
        (*adj_mat)[EDGE_END][EDGE_BEG] = 1;
    }

}

void print_adjacency_matrix(int n, std::vector<std::vector<int>> adj_mat)
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

void dfs(std::vector<std::vector<int>> adj_mat, int src, bool visited[])
{
    visited[src] = true;
    cout<<src + 1 <<" ";
    for (int v = 0; v < adj_mat[src].size(); v++)
    {
        if((visited[v] != true) && (adj_mat[src][v] == 1))
            dfs(adj_mat, v, visited);
    }
    
}

int main(int argc, char const *argv[])
{
    
    int vert, edge;
    cin>>vert>>edge;

    // initializing visited array and adjacency matrix
    std::vector<std::vector<int>> adj_mat(vert, std::vector<int>(vert));
    bool visited[adj_mat.size()] = {false};

    // creating the adjacency matrix
    adjacency_matrix(vert, edge, &adj_mat);
    //print_adjacency_matrix(vert, adj_mat);

    dfs(adj_mat,0, visited);

    return 0;
}
