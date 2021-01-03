/*
                [S  .   .   X   .   X]
                [.  .   X   .   X   X]
                [.  X   .   .   .   .]
                [X  .   .   X   E   X]
                [.  X   .   X   .   X]
*/
#include<bits/stdc++.h>

using namespace std;

#define f0(i, n) for(int i=0; i<n; i++)
typedef pair<int, int> pr;

int min_dist;
const int row = 5, col = 6;
int arr[row][col];
vector<vector<pr>> parent ( row, vector<pr> (col));

pr distance_calculate(vector<vector<char>> v){
    int move_r[] ={0, 1, 1, 1, 0}, move_c[] ={-1, -1, 0, 1, 1};
    queue<int> q1, q2;

    vector<vector<bool>> vis( row, vector<bool> (col, false));
    pr p;

    q1.push(0);
    q2.push(0);
    
    parent[0][0].first = -1;
    parent[0][0].second = -1;    
    arr[0][0] = 0;
    vis[0][0] = true;
    p.first = -1;
    p.second = -1;

    while ( !q1.empty() ){
        int it1 = q1.front();
        int it2 = q2.front();
        q1.pop();
        q2.pop();
        
        f0(i, 5){
            int r = it1 + move_r[i];
            int c = it2 + move_c[i];

            if ( 0 <= r && r < row && 0 <= c && c < col && v[r][c] != 'X' && vis[r][c] == false ) {
                arr[r][c] = arr[it1] [it2] + 1;
                vis[r][c] = true;
                parent[r][c].first = it1;
                parent[r][c].second = it2;

                if (v[r][c] == 'E'){
                    p.first = r;
                    p.second = c;

                    return p;

                }                 
                q1.push(r);
                q2.push(c);
            }


        }

    }

    return p;

}


void puzzle_solution (vector<vector<char>> vec){
    
    list<pr> ls;
    pr p;
    int r,c;
    p = distance_calculate(vec);
    
    if (p.first != -1){
        r = p.first;
        c = p.second;
        min_dist = arr[r][c];
        cout<< min_dist;

        while(parent[r][c].first != -1){
            ls.push_front(make_pair(r,c));
            pr temp = parent[r][c];
            r = temp.first;
            c = temp.second;
        }
        
        cout<<endl<<"(0,0)";
        
        for( auto it: ls){
            cout<<" --->"<<"("<<it.first<<","<<it.second<<")";
        }
    }

    else {
        min_dist = -1;
        cout<< min_dist;
    }
    
    }


int main (){

    int row = 5, col = 6;
    char c;
    //vector<vector<char>> vec;
    vector<vector<char>> vec {{'S', '.', '.', 'X', '.', 'X'},
                              {'.', '.', 'X', 'X', 'X', 'X'},
                              {'.', '.', 'X', 'x', '.','.'},
                              {'X', 'X', '.', '.', 'X','.'},
                              {'.', 'X', '.', 'X', 'E', 'X'}};
    //cin >> row >> col;

    /*f0(i, row){
        vector<char> dumy;
        f0(j, col){
            cin>> c;
            dumy.push_back(c);
        }
        vec.push_back(dumy);
    }
    */
    puzzle_solution (vec);
    
    return 0;
}