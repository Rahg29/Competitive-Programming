#include<bits/stdc++.h>
using namespace std;
pair<int, pair<int, int>> *edg;

int main(){
    int vertex, edge, v1, v2, w;
    cin>>vertex>>edge;
    edg = new pair<int, pair<int, int>>[edge];
    vector<int> dis(vertex, INT_MAX);
    dis[0] = 0;
    for (int e=0; e<edge; e++){
        cin>>v1>>v2>>w;

        edg[e].first = w;
        edg[e].second.first = v1;
        edg[e].second.second = v2;
    }

    for (int i=0; i < vertex-1; i++){
        for (int j=0; j < edge; j++){
            w = edg[j].first;
            v1 = edg[j].second.first;
            v2 = edg[j].second.second;

            if (dis[v1] != INT_MAX && dis[v2] > dis[v1] + w) dis[v2] = dis[v1] + w; 
        }
    }

    for (int e = 0; e < edge; e++){
        w = edg[e].first;
        v1 = edg[e].second.first;
        v2 = edg[e].second.second;

        if (dis[v1] != INT_MAX && dis[v2] > dis[v1] + w){
            cout<<"Graph contains a negative weight cycle";
            return 0;
        }
    }

    for (auto it: dis){
        cout<<it<<" ";
    }

    return 0;
}