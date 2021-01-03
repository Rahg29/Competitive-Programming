#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> rev_adj;
vector<bool> vis;
stack<int> stk;

void dfs(int v, vector<vector<int>> adj){
    vis[v]=true;
    for(auto it : adj[v]){
        if(!vis[it]){
            dfs(it, adj);
        }
    }

    stk.push(v);
}

void rdfs(int v){
    vis[v]=false;
    for(auto it : rev_adj[v]){
        if(vis[it]){
            rdfs(it);
        }
    }

    cout<<v<<" ";
}


void strongly_connected_comp(){

    while (! stk.empty()){
        int p = stk.top();
        stk.pop();
        if (vis[p]){
            rdfs(p);
        }
        cout<<endl;
    }

}

int main (){
    int vertex, edge, v1, v2;
    cin>>vertex>>edge;
    vector<vector<int>> adj(vertex);
    vis.assign(vertex, false);
    
    rev_adj.resize(vertex);
    
    for(int e=0; e<edge; e++){
        cin>> v1>>v2;
        adj[v1].push_back(v2);
    }

    for ( int i=0; i < vertex; i++ ){
        if(!vis[i]){
            dfs( i, adj);
        }
    }

    for(int i=0; i<vertex; i++){
        for( auto it: adj[i]){
            rev_adj[it].push_back(i);
        }
    }

    strongly_connected_comp();
     
    return 0;
}