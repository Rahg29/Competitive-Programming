/*
      Graph
1 => (2,1) (3,4) (5,4)
2 => (2,1) (4,2)
3 => (1,4) (5,3) (6,4)
4 => (2,3) (5,1) (8,5)
5 => (1,3) (3,2) (4,1) (6,2)
6 => (3,4) (5,2) (7,1)
7 => (6,1) (8,3)
8 => (4,3) (7,2)

Find minimum distance from node 1 to node 8 by bfs
*/

#include<bits/stdc++.h>
using namespace std;

#define f(i, n) for(int i=0; i<n; i++)
#define max INT_MAX; 

int minimum_distance_bfs(vector<list<pair<int,int>>> vec, int s, int x, int d[]){
    d[s] = 0;
    

}


int main (){
    int vertex, edge, source, destination, v1, v2, weight, min_dis;
    cin>>vertex>>edge>>source>>destination;
    int distance[vertex];

    vector<list<pair<int, int> > > adj_list(vertex);
    f (i,edge) {
        cin>>v1>>v2>>weight;
        adj_list[v1].push_back(make_pair(v2, weight));
    }

    f(i, vertex) distance[i] = max;

    min_dis = minimum_distance_bfs(adj_list,source,destination, distance);
    
    cout<<min_dis;

    return 0;
}