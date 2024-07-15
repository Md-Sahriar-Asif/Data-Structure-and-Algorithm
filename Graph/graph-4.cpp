// Cycle detection in a directed graph using bfs

#include<bits/stdc++.h>
using namespace std;

class Graph{
    int V;
    list<int>* adj;

    public:
    Graph(int vertices){
        V = vertices;
        adj = new list<int>[V];
    }

    void addEdge(int u, int v){
        adj[u].push_back(v);
    }

    bool isCycle(){
        vector<int> in_degree(V, 0);

        for(int i=0; i<V; i++){
            for(auto t : adj[i]){
                in_degree[t]++;
            }
        }

        queue<int> q;
        for(int i=0; i<V; i++){
            if(in_degree[i]==0)
                q.push(i);
            }
    
        int cnt = 1;

        while(!q.empty()){
            int curr = q.front();
            q.pop();

            list<int>::iterator it;
            for(it=adj[curr].begin(); it!=adj[curr].end(); it++){
                if(--in_degree[*it] == 0){
                    q.push(*it);
                    cnt++;
                }
            }
        }

        if(cnt != V)
            return true;
        else
            return false;
    }
};

int main(){
    Graph g(6);

    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(3, 4);
    g.addEdge(4, 5);

    if(g.isCycle())
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}