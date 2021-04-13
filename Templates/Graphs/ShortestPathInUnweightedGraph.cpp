#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// It is well-known, that you can find the shortest paths between
// a single source and all other vertices in O(|E|) using
// Breadth First Search in an unweighted graph


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

// This changed bfs finds shortest path in O(m+n) time


void bfs(std::vector<std::vector<int>> adj_mat, int src, int dest, bool visited[])
{
    // creating visited array and queue
    queue< int > q;
    // creating distance array and array of parents p
    vector<int> d(adj_mat.size());
    vector<int> p(adj_mat.size());

    // putting src into queue and visited and distance arrays 
    q.push(src);
    visited[src] = true;
    d[src] = 0;
    p[src] = -1;

    //std::cout << src +1 <<" ";

    while(!q.empty())
    {
        // getting the front of the queue
        int u = q.front();
        q.pop();

        for (int v = 0; v < adj_mat[u].size(); v++)
        {
            if((visited[v] != true) && (adj_mat[u][v] == 1))
            {
                //std::cout << v + 1<<" ";
                visited[v] = true;
                q.push(v);
                d[v] = d[u]+1;
                p[v] = u;
            }
        }
    }
    //std::cout<<"\n";

    // in case the destination node was never traversed
    if(visited[dest] == false)  
    {
        cout<<"no path!!!\n";
    }
    else
    {
        // to store path
        vector<int> path;
        // v gets updated to its parent node's location every time
        for (int v = dest; v != -1; v=p[v])
        {
            path.push_back(v);
        }
        // printing shortest path
        reverse(path.begin(), path.end());
        cout << "Path: ";
        for (int v : path)
            cout << v<<" ";
    }
}

int main(int argc, char const *argv[])
{
    
    int vert, edge;
    cin>>vert>>edge;

    // initializing the visited array and the adj matrix
    std::vector<std::vector<int>> adj_mat(vert, std::vector<int>(vert));
    bool visited[adj_mat.size()] = {false};

    // creating the adjacency matrix
    adjacency_matrix(vert, edge, &adj_mat);
    //print_adjacency_matrix(vert, adj_mat);

    bfs(adj_mat, 0, 5,visited);

    return 0;
}
