// Cycle detection in undirected graph using dfs

#include<bits/stdc++.h>
using namespace std;

class Graph{
    int V;
    list<int> *adj;

    bool cyclicCheck(int v, bool visited[], int parent)
    {
        visited[v] = true;

        list<int>::iterator i;
        for(i=adj[v].begin(); i!=adj[v].end(); i++){
              
              if(!visited[*i]){
                if(cyclicCheck(*i, visited, v))
                    return true;
              }
              else if(*i != parent)
                return true;  // cycle detected
        }
        return false;
    }

    public:
    Graph(int vertices){
        V = vertices;
        adj = new list<int>[vertices];
    }

    void addEdge(int u, int v){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bool isCyclic(){

        bool visited[V];
        for(int i=0; i<V; i++)
            visited[i]=false;

        for(int i=0; i<V; i++){
            if(!visited[i])
              if(cyclicCheck(i, visited, -1))
                 return true;
        }
        return false;
    }
};

int main(){
    int vertices = 5;
    Graph g(5);

    g.addEdge(1, 0);
    g.addEdge(0, 2);
    g.addEdge(2, 1);
    g.addEdge(0, 3);
    g.addEdge(3, 4);

    g.isCyclic() ? cout << "Cycle detected" << endl :
                   cout << "There is no cycle" << endl;

    int vertices2 = 3;
    Graph g2(vertices2);
    g2.addEdge(0, 1);
    g2.addEdge(1, 2);


    if(g2.isCyclic())
        cout << "Cycle detected" << endl;
    else
        cout << "There is no cycle" << endl;

}