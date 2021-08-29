#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> build_adj_list(int n, int m, vector<vector<int>> edges)
{
    vector<vector<int>> adj_list(n);
    for (int i = 0; i < m; i++)
    {
        adj_list[edges[i][0]].push_back(edges[i][1]);
        adj_list[edges[i][1]].push_back(edges[i][0]);
    }
    return adj_list;
}

// for checking cycle using dfs simply check if there is a neighbour node that has been visited and is not a parent of v
bool dfs(vector<vector<int>> adj_list, int v, vector<bool> &visited, vector<bool> &parent)
{
    visited[v] = true;
    for (int i = 0; i < adj_list[v].size(); i++)
    {
        parent[i] = v;
        if (!visited[adj_list[v][i]])
        {
            if (dfs(adj_list, adj_list[v][i], visited, parent))
                return true;
        }
        else if (visited[i] && parent[v] != i)
            return true;
    }
    return false;
}

int main(int argc, char const *argv[])
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges(m, vector<int>(2));
    for (int i = 0; i < m; i++)
    {
        cin >> edges[i][0];
        cin >> edges[i][1];
    }

    vector<vector<int>> adj_list = build_adj_list(n, m, edges);
    vector<bool> visited(n, false);
    vector<bool> parent(n, false);
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            if (dfs(adj_list, i, visited, parent))
            {
                cout << "YES" << endl;
                return 0;
            }
        }
    }
    cout << "NO" << endl;

    return 0;
}
