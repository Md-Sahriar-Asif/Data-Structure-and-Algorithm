// Cycle detection in undirected graph using bfs

#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[], int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

bool cycleDetection(vector<int> adj[], int v, vector<bool>&visited){
    queue<int> q;
    q.push(v);

    while(!q.empty()){
        int curr = q.front();
        q.pop();

        if(visited[curr]==1)
            return true;  //cycle detected

        visited[curr]=1;
        for(auto it : adj[curr]){
            if(visited[it] == 0){
                q.push(it);
            }
        }
    }
    return false;
}

bool isCyclick(vector<int> adj[], int V){
    vector<bool> visited(V, false);
    for(int i=0; i<V; i++){
        if(!visited[i] && cycleDetection(adj, i, visited)){
            return true;
        }
    }
    return false;
}

int main(){
    int vertices = 4;
    vector<int> adj[vertices];

    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 0);
    addEdge(adj, 2, 3);

    if(isCyclick(adj, vertices)){
        cout << "Yes, the graph is cyclick" << endl;
    }else{
        cout << "No, the graph isn't cyclick" << endl;
    }
}