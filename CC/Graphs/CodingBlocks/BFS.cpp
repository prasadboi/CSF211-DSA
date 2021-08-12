#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void BFS(vector<vector<int>> &adjList, vector<bool> &visited, vector<int> &parent, vector<int> &dist, int start) {
    queue<int> q;
    q.push(start);
    visited[start] = true;
    parent[start] = -1;
    dist[start] = 0;

    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        cout<<u<<" ";
        for(auto v : adjList[u])
        {
            if(!visited[v])
            {
                visited[v] = true;
                parent[v] = u;
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
}

// single source shortest path using BFS in unweighted graph
void BFS_SSP(vector<int> &parent, vector<int> &dist, int dest)
{
    vector<int> path;
    int u = dest;
    while(u != -1){
        path.push_back(u);
        u = parent[u];
    }
    reverse(path.begin(), path.end());
    for(auto v : path) cout<<v<<" ";
    cout<<endl;
}

int main(int argc, char const *argv[])
{
    int n, m;
    cin >> n;
    cin>>m;
    vector<vector<int>> edges(m, vector<int> (2));
    for(int i = 0; i < m; i++)
    {
        cin>>edges[i][0];
        cin>>edges[i][1];
    }


    vector<bool> visited(n, false);
    vector<int> parent(n, -1);
    vector<vector<int>> adjList(n, vector<int>());
    vector<int> dist(n, INT_MAX);
    // make adjList
    for(int i = 0; i < m; i++)
    {
        adjList[edges[i][0]].push_back(edges[i][1]);
        adjList[edges[i][1]].push_back(edges[i][0]);
    }

    int start = 0;
    // print BFS traversal
    BFS(adjList, visited, parent, dist, start);
    cout<<endl;
    //print the parent
    for(int i = 0; i < n; i++) cout<<parent[i]<<" ";
    cout<<endl;
    //print the distance
    for(int i = 0; i < n; i++) cout<<dist[i]<<" ";
    cout<<endl;
    // print shortest path from 0 to 5
    BFS_SSP(parent, dist, 5);
    return 0;
}
