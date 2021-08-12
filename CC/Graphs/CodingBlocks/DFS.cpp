#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void DFS(vector<vector<int>> adjList, int start, vector<bool> visited) {
    visited[start] = true;
    cout<<start<<" ";
    for (int i = 0; i < adjList[start].size(); i++)
        {
            if (!visited[adjList[start][i]])
                DFS(adjList, adjList[start][i], visited);
        }
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
    DFS(adjList, start, visited);
    return 0;
}
