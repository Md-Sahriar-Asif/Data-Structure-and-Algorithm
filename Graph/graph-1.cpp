#include<bits/stdc++.h>
using namespace std;

class graph{
   public: 
      map<int, list<int>> adj;

      void addEdges(int u, int v, bool direction){
         //direction = 0 -> undirected graph
         //direction = 1 -> directed graph

         adj[u].push_back(v);
         if(!direction)
            adj[v].push_back(u);
      }

      void printAdjList(){
         for(auto i : adj){
            cout << i.first << "-> ";
            for(auto j : i.second){
               cout << j << ", ";
            }
            cout << endl;
         }
      }

};

int vertArr[50][50];  // Adjacency matrix

void displayMatrix(int v){
   for(int i=0; i<v; i++){
      for(int j=0; j<v; j++){
         cout << vertArr[i][j] << " ";
      }
      cout << endl;
   }
}

void add_edge(int a, int b){
   vertArr[a][b]=1;
   vertArr[b][a]=1;
}

int main(){
   
   /*int v=6;   // Adjacency matrix
   add_edge(0, 4);
   add_edge(0, 3);
   add_edge(1, 2);
   add_edge(1, 4);
   add_edge(1, 5);
   add_edge(2, 3);
   add_edge(2, 5);
   add_edge(5, 3);
   add_edge(5, 4);

   displayMatrix(v);*/

   int n, m; 
   cout << "Enter the number of nodes: " << endl;
   cin >> n;
   cout << "Enter the number of edges: " << endl;
   cin >> m;

   graph g;

   for(int i=0; i<m; i++){
      int u,v;
      cin >> u >> v;
      g.addEdges(u, v, 0);  //undirected graph
   }

   g.printAdjList();

}
