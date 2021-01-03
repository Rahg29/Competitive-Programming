#include<bits/stdc++.h>

using namespace std;
int vertex, edge;
vector<int> parent;

int check( int a ){
    while( parent[a] != a){
        a = parent[a]; 
    }
    return a;
}

void union_set(int x, int y){
    int p = check(x);
    int q = check(y);
    parent[p] = parent[q];

}

void kruskal( pair<int, pair<int, int>> p[]){
    int count = vertex-1;
    for (int it = 0; it < edge; it++){
        int x = p[it].second.first;
        int y = p[it].second.second;

        if (check(x) != check(y)){
            --count;
            cout<< p[it].first<< " ";
            union_set(x, y);
            if (!count) break;
        }
    }
}


int main (){
    int v1, v2, w;
    cin>>vertex>>edge;
    pair<int, pair<int, int>> p[vertex];
    parent.resize(vertex);

    for(int i=0; i< vertex; i++){
        parent[i]=i;
    }

    for(int e=0; e<edge; e++){
        cin>>v1>>v2>>w;
        p[e] = make_pair(w, make_pair(v1,v2));
    }

    sort( p, p+edge );

    kruskal( p);
    return 0;
}