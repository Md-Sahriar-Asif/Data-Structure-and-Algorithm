#include<bits/stdc++.h>
using namespace std;

vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source){
    // create adjacency list
    unordered_map<int, list<pair<int, int>>> adj;
    for(int i=0; i<edges; i++){
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];

        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }

    //creation of distance array with infinite value initially
    vector<int> dist(vertices, INT_MAX);
    //creation of set on basis (distance, node)
    set<pair<int, int>> st; 

    dist[source] = 0;
    st.insert(make_pair(0, source));

    while(!st.empty()){
        // fetch top record
        auto top = *(st.begin());

        int nodeDistance = top.first;
        int topNode = top.second;
        
        //remove top record
        st.erase(st.begin());

        //traverse on neighbours
        for(auto neighbour : adj[topNode]){
            if(nodeDistance + neighbour.second < dist[neighbour.first]){
                auto record = st.find(make_pair(dist[neighbour.first], neighbour.first));
                //If record found
                if(record != st.end()){
                    st.erase(record);
                }

                //update distance
                dist[neighbour.first] = nodeDistance+neighbour.second;
                //record push in set
                st.insert(make_pair(dist[neighbour.first], neighbour.first));

            
            }
        }

    }

    return dist;
}

int main(){
    int vertices = 5, edges = 7;
    vector<vector<int>> vec(edges, vector<int>(3));
    vec[0][0]=0; vec[0][1]=1; vec[0][2]=7;
    vec[1][0]=0; vec[1][1]=2; vec[1][2]=1;
    vec[2][0]=0; vec[2][1]=3; vec[2][2]=2;
    vec[3][0]=1; vec[3][1]=2; vec[3][2]=3;
    vec[4][0]=1; vec[4][1]=3; vec[4][2]=5;
    vec[5][0]=1; vec[5][1]=4; vec[5][2]=1;
    vec[6][0]=3; vec[6][1]=4; vec[6][2]=7;

    vector<int> ans = dijkstra(vec, vertices, edges, 0);
    for(int i=0; i<vertices; i++){
        cout << ans[i] << " ";
    }

}