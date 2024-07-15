// DFS algo implementation in graph

#include<bits/stdc++.h>
using namespace std;

class Graph{
  public:
    map<int, bool> visited;
    map<int, list<int>> adj;

    void addEdge(int v, int w){
        adj[v].push_back(w);
    }
    void dfs(int v){
        visited[v] = true;
        cout << v << " ";

        list<int>::iterator i;  //auto can be used instead of this line
        for(i = adj[v].begin(); i!=adj[v].end(); i++){
            if(!visited[*i]){
                dfs(*i);
            }
        }
    }
};

int main(){
    Graph g;
    g.addEdge(0, 2);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    cout << "DFS starting vertex is: 2 -> ";
    g.dfs(0); 
    
 /*if any vertex isn't adjacent to anyone then
    use for loop here, like:
    for (int i = 0; i <= 3; ++i) {  // Assuming vertices are numbered from 0 to 3
        if (!g.visited[i]) {
            g.dfs(i);
        }
*/
    return 0;
}