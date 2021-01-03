#include <bits/stdc++.h>
#define inf INT_MAX

using namespace std;

vector<int> short_dis;
vector<vector<pair<int, int>>> graph;

void dijktra_algo(int u){
    set<pair<int, int>> s;
    short_dis[u] = 0;
    s.insert(make_pair(0, u));

    while( !s.empty()){
        pair<int, int> p = *(s.begin());
        s.erase(s.begin());
        int v;
        v = p.second;
        for( auto it : graph[v]){

            if ( short_dis[it.second] > it.first + short_dis[v]){
                int n = it.second;
                int w = it.first;
                if (short_dis[n] != inf){
                    s.erase(s.find(make_pair(short_dis[n], n)));

                }
                short_dis[n] = w + short_dis[v];
                s.insert(make_pair(short_dis[n], n));

            }
        }
    }
}

int main(){
    int vertex, edge, source,v1, v2, w;
    cin>>vertex>>edge>>source;
    
    short_dis.assign(vertex, inf);
    graph.resize(vertex);

    for(int e=0; e<edge; e++){
        cin>>v1>>v2>>w;
        graph[v1].push_back(make_pair(w, v2));
        graph[v2].push_back(make_pair(w, v1));
    }

    dijktra_algo(source);

    for (auto dis: short_dis){
        cout<<dis<<" ";
    }
    return 0;
}