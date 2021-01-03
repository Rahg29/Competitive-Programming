#include<bits/stdc++.h>

using namespace std;

int vertex, edge;
int timer=0;

vector<int> *adj;
vector<int> parent, dis, low;
set<int> art_pts;
vector<bool> vis;

void articulation_points(int v){
    int child=0;
    ++timer;
    vis[v] = true;
    dis[v] = timer;
    low [v] = timer;

    for(auto it : adj[v]){
        if (vis[it] == false){
            
            ++child;
            parent[it] = v;

            articulation_points(it);
            
            
            low[v] = min(low[v], low[it]);

            if (parent[v] != -1 && low[it] >= dis[v]){
                art_pts.insert(v);
            }

            else if ( parent[v] == -1 && child >= 2){
                art_pts.insert(v);
            }

        }

        else if( it != parent[v]){
            low[v] = min( low[v], dis[it]);            
        }
    }

}

int main (){
    int v1, v2;
    cin>>vertex>>edge;
    adj = new vector<int>[vertex];
    
    vis.assign(vertex, false);
    parent.assign(vertex, -1);
    dis.assign(vertex, -1);
    low.assign(vertex, -1);

    for(int i=1; i<=edge; i++){
        cin>>v1>>v2;
        adj[v1].push_back(v2);
        adj[v2].push_back(v1);
    }

    articulation_points(1);

    for(auto s: art_pts){
        cout<<s<<" ";
    }

    delete [] adj;
    return 0;
}