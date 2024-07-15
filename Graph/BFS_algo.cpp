// BFS algo implementation in graph

#include<bits/stdc++.h>
using namespace std;

void bfs(vector<vector<int>>&adjList, int starter, vector<bool>&visited){
    cout << "BFS starting from vertex: " << starter << "-> ";
    queue<int> q;

    visited[starter] = true;
    q.push(starter);

    while(!q.empty()){
        int currNode = q.front();
        q.pop();
        cout << currNode << " ";

        for(int neighbor : adjList[currNode]){
            if(!visited[neighbor]){
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

void addEdge(vector<vector<int>>&adjList, int u, int v){
    adjList[u].push_back(v);
}

int main(){
    int vertices = 5;

    vector<vector<int>> adjList(vertices);
    addEdge(adjList, 0, 1);
    addEdge(adjList, 0, 2);
    addEdge(adjList, 1, 3);
    addEdge(adjList, 1, 4);
    addEdge(adjList, 2, 4);

    vector<bool> visited(vertices, false);
    bfs(adjList, 0, visited);

}