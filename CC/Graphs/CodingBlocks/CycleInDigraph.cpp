#include <iostream>
#include <bits/stdc++.h>

using namespace std;


// recVisited = recursion stack 
// visited = visited array

bool findCycle(int cur, vector<vector<int>>&adj, vector<bool>&visited, vector<bool>&ancestor){
    visited[cur] = true;
    ancestor[cur] = true;
    
    for(auto itr: adj[cur]){
        if(!visited[itr]){
            if(findCycle(itr, adj, visited, ancestor))return true;
        }
        // if it is visited then check in recVisited
        else if(ancestor[itr]){
            return true;
        }
    }
    ancestor[cur] = false;
    return false;
}

int solve(int v, vector<vector<int> > &B) {
    
    vector<vector<int>>adj(v+1);
    for(int i = 0; i < B.size(); ++i){
        adj[B[i][0]].push_back(B[i][1]);
    }
    vector<bool>visited(v+1);
    vector<bool>ancestor(v+1);
    
    for(int i = 1; i <= v; ++i){
        if(!visited[i]){
            if(findCycle(i, adj, visited, ancestor)){
                return true;
            }
        }
    }
    return false;
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
