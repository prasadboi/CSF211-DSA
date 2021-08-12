#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void build_graph(int n, vector<vector<int>> &adjList, vector<vector<int>> ladders, vector<vector<int>> snakes) {
    cout<<"Building graph\n";
    
    for(int i = 0; i < n; i++) {
        for(int j = 1; j <= 6 && i + j < n; j++){
            adjList[i].push_back(i + j);
        }
    }
    for (int i = 0; i < ladders.size(); i++) {
        adjList[ladders[i][0]].push_back(ladders[i][1]);
    }
    for(int i = 0; i < snakes.size(); i++) {
        adjList[snakes[i][0]].push_back(snakes[i][1]);
    }
}

int BFS(int n, vector<vector<int>> &adjList, int start)
{
    cout<<"BFS\n";
    vector<bool> visited(n, false);
    vector<int> distance(n, INT_MAX);
    distance[start] = 0;
    vector<int> parent(n, -1);

    queue<int> q;
    q.push(start);
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int v = 0; v < adjList[u].size(); v++)
        {
            if(!visited[adjList[u][v]])
            {
                parent[v] = u;
                distance[v] = distance[u] + 1;
                q.push(v);
                visited[adjList[u][v]] = true;
            }
        }
    }
    return distance[n-1];
}

int snakeLadder(vector<vector<int>> A, vector<vector<int>> B) {
    unordered_map<int,int> ladder,snakes;
    for(auto v: A)
        ladder.insert({v[0],v[1]});
    for(auto v: B)
        snakes.insert({v[0],v[1]});
    queue<pair<int,int>> q;
    vector<bool> visited(101,false);
    q.push({1,0});
    visited[1] = true;
    while(!q.empty()){
        auto ele = q.front();
        q.pop();
        if(ele.first==100)
            return ele.second;
        for(int k =1; k<=6; k++){
            int pos = ele.first+k;
            // if you roll a dice and end up at a ladder
            if(ladder.find(pos) != ladder.end())
                pos = ladder[pos];
            // if you roll a dice and end up at a snake
            if(snakes.find(pos) != snakes.end())
                pos = snakes[pos];
            if(!visited[pos]){
                visited[pos] = true;
                q.push({pos,ele.second+1});
            }
        }
    }
    return -1;
}

int main(int argc, char const *argv[])
{
    int n, m, k;
    
    n = 10;
    cin>>m>>k;

    vector<vector<int>> ladders(m);
    cout<<"Enter ladders info : \n";
    for(int i = 0; i < m; i++){
        int a, b;
        cin>>a>>b;
        ladders[i].push_back(a);
        ladders[i].push_back(b);
    }
    vector<vector<int>> snakes(n);
    cout<<"Enter snakes info : \n";
    for(int i = 0; i < k; i++){
        int a, b;
        cin>>a>>b;
        snakes[i].push_back(a);
        snakes[i].push_back(b);
    }

    vector<vector<int>> adjList(n*n);
    cout<<"for every node you can go uptil i + 6 with a dice roll\n";
    for(int i = 0; i < n; i++) {
        for(int j = 1; j <= 6 && i + j < n; j++) {
            adjList[i].push_back(i + j);
        }
    }
    cout<<"you can get eaten by a snake\n";
    for(auto v : snakes){
        adjList[v[0]].push_back(v[1]);
    }
    cout<<"you can climb a ladder\n";
    for(int j = 0; j < ladders.size(); j++){
        adjList[ladders[j][0]].push_back(ladders[j][1]);
    }
    
    cout<<"BFS\n : "<<BFS(n, adjList, 0)<<endl;
    return 0;
}
