#include <bits/stdc++.h>
using namespace std;

vector<int> dis, low, parent;
vector<bool> visited;
vector<pair<int, int>> bridge;
vector<vector<int>> adj;

int timer=0;

void bridge_identifcation(int v){
    visited[v] =true;
    ++timer;
    dis[v]=timer;
    low[v]=timer;

    for(auto it: adj[v]){
        if(visited[it] == false){
            parent[it] = v;
            bridge_identifcation(it);
            low[v] = min(low[v], low[it]);

            if (low[it] > dis[v]){
                bridge.push_back(make_pair(it,v));
            }
        }

        else if ( it != parent[v]){
            low[v] = min(low[v], dis[it]);
        }
    }
}


int main(){
    int vertex, edge, v1, v2;
    cin>>vertex>>edge;

    adj.resize(vertex+1);
    dis.assign(vertex+1, -1);
    low.assign(vertex+1, -1);
    parent.assign(vertex+1, -1);
    visited.assign(vertex+1, false);


    for(int e=0; e<edge; e++){
        cin>>v1>>v2;
        adj[v1].push_back(v2);
        adj[v2].push_back(v1);
    }

    bridge_identifcation(1);

    for(auto s: bridge){
        cout<<"("<<s.first<<","<< s.second <<")  ";
    }
    return 0;
}