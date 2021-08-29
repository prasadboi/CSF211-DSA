/*
You are given an m x n grid where each cell can have one of three values:

0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

*/

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

int multiSourceBFS(vector<vector<int>> &grid, int m, int n)
{
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    queue<pair<int, int>> q;
    int ctr = 0;
    // first we initialize all the possible starting points
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 2) // if it is a rotten orange
            {
                q.push({i, j}); // inserting into q the location of a rotten orange
            }
        }
    }

    // then we perform normal BFS
    while (!q.empty())
    {
        pair<int, int> u = q.front();
        q.pop();
        visited[u.first][u.second] = true;
        //cout << u.first << " " << u.second << endl;
        // check if there is any orange in the 4 direction of the rotten orange
        if (u.first - 1 >= 0 && grid[u.first - 1][u.second] == 1 && !visited[u.first - 1][u.second])
        {
            //cout << "YES : " << u.first - 1 << " " << u.second << ", " << grid[u.first - 1][u.second] << endl;
            grid[u.first - 1][u.second] = 2;
            q.push({u.first - 1, u.second});
            visited[u.first - 1][u.second] = true;
        }
        if (u.first + 1 < m && grid[u.first + 1][u.second] == 1 && !visited[u.first + 1][u.second])
        {
            //cout << "YES : " << u.first + 1 << " " << u.second << ", " << grid[u.first + 1][u.second] << endl;
            grid[u.first + 1][u.second] = 2;
            q.push({u.first + 1, u.second});
            visited[u.first + 1][u.second] = true;
        }
        if (u.second - 1 >= 0 && grid[u.first][u.second - 1] == 1 && !visited[u.first][u.second - 1])
        {
            //cout << "YES : " << u.first << " " << u.second - 1 << ", " << grid[u.first][u.second - 1] << endl;
            grid[u.first][u.second - 1] = 2;
            q.push({u.first, u.second - 1});
            visited[u.first][u.second - 1] = true;
        }
        if (u.second + 1 < n && grid[u.first][u.second + 1] == 1 && !visited[u.first][u.second + 1])
        {
            //cout << "YES : " << u.first << " " << u.second + 1 << ", " << grid[u.first][u.second + 1] << endl;
            grid[u.first][u.second + 1] = 2;
            q.push({u.first, u.second + 1});
            visited[u.first][u.second + 1] = true;
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 1 && !visited[i][j])
                return -1;
        }
    }
    return 1;
    // if we want the number of steps required to destroy all the oranges, the max depth of the graph is the number of oranges
}

int main(int argc, char const *argv[])
{
    int m, n;
    cin >> m >> n;
    vector<vector<int>> grid(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
        }
    }

    // print grid
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }

    cout << "calling func : \n"
         << multiSourceBFS(grid, m, n);
    return 0;
}
