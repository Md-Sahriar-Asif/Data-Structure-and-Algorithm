
//shortest path between source and destination vertex

#include<bits/stdc++.h>
using namespace std;

int bellmanFord(int n, int m, int src, int dest, vector<vector<int>> &edges){
    vector<int> dist(n+1, INT_MAX); //starting from 1 not 0, so n+1
    dist[src] = 0;

    //n-1 times
    for(int i=1; i<=n; i++){
        //treverse on edge list
        for(int j=0; j<m; j++){
            int u = edges[j][0];
            int v = edges[j][1];
            int wt = edges[j][2];

            if(dist[u] != INT_MAX && ((dist[u] + wt) < dist[v])){
                dist[v] = dist[u] + wt;
            }
        }
    }

    //check for negative cycle
    bool flag = 0;
    for(int j=0; j<m; j++){
        int u = edges[j][0];
        int v = edges[j][1];
        int wt = edges[j][2];

        if(dist[u] != INT_MAX && ((dist[u]+wt) < dist[v])){
            flag = 1;
        }
    }
    if(flag==0){
        return dist[dest];
    }else
    return -1;
}

int main()
{
    int vertices = 3, edges = 3;
    vector<vector<int> > vec(edges, vector<int>(3));
    vec[0][0]=1; vec[0][1]=2; vec[0][2]=2;
    vec[1][0]=2; vec[1][1]=3; vec[1][2]=-1;
    vec[2][0]=3; vec[2][1]=1; vec[2][2]=-2;
   // vec[1][0]=3; vec[1][1]=1; vec[1][2]=2;

    int ans = bellmanFord(vertices, edges, 1, 3, vec);
    if(ans != -1)
        cout << ans << endl;
    else
        cout << "there is a negative cycle" << endl;

}


//approach no-2

/*const int INF = 1e9;

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges;

    for(int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }
    int src;
    cin >> src;
    vector<int> dist(n, INF); 
    dist[src] = 0;

    // Bellman-Ford algorithm to find shortest paths
    for(int it = 0; it < n-1; it++){
        for(auto e : edges){
            int u = e[0];
            int v = e[1];
            int w = e[2];

            if(dist[u] != INF && dist[v] > w + dist[u]) {
                dist[v] = w + dist[u];
            }
        }
    }

    // Check for negative weight cycles
    bool negativeCycle = false;
    for(auto e : edges){
        int u = e[0];
        int v = e[1];
        int w = e[2];

        if(dist[u] != INF && dist[v] > w + dist[u]) {
            negativeCycle = true;
            break;
        }
    }

    if(negativeCycle) {
        cout << "Graph contains a negative weight cycle" << endl;
    } else {
        for(auto i : dist){
            if(i == INF) {
                cout << "INF ";
            } else {
                cout << i << " ";
            }
        }
        cout << endl;
    }

    return 0;
}*/