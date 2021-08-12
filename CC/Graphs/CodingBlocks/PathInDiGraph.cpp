#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool DFS(int start, int goal, vector<vector<int>> &graph, vector<bool> &visited)
{
    if(start == goal) return true;
    visited[start] = true;
    for (int i = 0; i < graph[start].size(); i++)
    {
        if (!visited[graph[start][i]] )
        {
            if(DFS(graph[start][i], goal, graph, visited)) return true;
        }
    }
    return false;
}

int solve(int A, vector<vector<int> > &B) {
    vector<bool> visited(A, false);
    // create adj list
    vector<vector<int>> adjList(A);
    for(int i = 0; i < B.size(); i++)
        adjList[B[i][0] - 1].push_back(B[i][1] - 1);
    
    // call DFS
    if(DFS(0, A - 1, adjList, visited)) return 1;
    else return 0;
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
    
    cout<<solve(n, edges)<<endl;
    return 0;
}
