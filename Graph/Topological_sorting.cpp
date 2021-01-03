#include<bits/stdc++.h>
using namespace std;

vector<bool> vis;
stack<int> stk;

void dfs(vector<int> adj[],int v){
    vis[v]=true;

    for( auto it: adj[v]){
        
        if (!vis[it]){
            dfs(adj, it);
        }

    }
    stk.push(v);
}

void topological_sorting(vector<int> adj[], int vertex, vector<int> & top_sort){
    
    for (int v=0; v < vertex; v++ ){
        if (!vis[v]){

            dfs( adj, v);
        }
    }

    while ( !stk.empty()){
        int p = stk.top();
        stk.pop();
        top_sort.push_back(p);
    }
}

int main(){
    int vertex, edge, v1, v2;
    cin>>vertex>>edge;
    vector<int> adj[vertex], top_sort;
    vis.assign(vertex, false);
    for (int e=0; e < edge; e++){
        cin>>v1>>v2;
        adj[v1].push_back(v2);
    }

    topological_sorting(adj, vertex, top_sort);

    for ( auto it: top_sort){
        cout<<it<<" ";
    }
    return 0;
}