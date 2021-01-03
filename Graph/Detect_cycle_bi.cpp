#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> graph;
vector<bool> vis;
bool Detect_cycle(int u, int p){
    vis[u]=true;
    for (auto v: graph[u]){
        if (!vis[v]){
            if (Detect_cycle(v, u)) return true;
        }
        else if (v != p) return true;
    }
    return false;

}

int main (){
    int vertex, edge, v1, v2;
    cin>>vertex>>edge;
    graph.resize(vertex);
    vis.assign(vertex, false);
    for (int e=0; e<edge; e++){
        cin>>v1>>v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }

    if (Detect_cycle(0, -1)) cout<<"Cycle Detected";
    else cout<<"Cycle Not Detected";
}