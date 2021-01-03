#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> r_arr = {-1, 0, 1, 0}, c_arr = {0, 1, 0, -1};
    int N, M;
    bool detect_cycle( int i, int j, int x, int y, vector<vector<bool>> vis, vector<vector<char>> grid){
        vis[i][j] = true;
        for(int e=0; e < 4; e++){
            int R = i+r_arr[e], C = j+c_arr[e];
            if ( R >=0 && R < N && C >= 0 && C < M 
                && grid[i][j] == grid[R][C] ){
                
                if ( !vis[R][C] ){
                    if ( detect_cycle( R, C, i, j, vis, grid) ) return true;
                }
                
                else if (R != x || C != y ) return true;
            }
        }
        return false;        
    };
    
    bool containsCycle(vector<vector<char>>& grid) {
        N = grid.size();
        M = grid[0].size();
        
        vector<vector<bool>> vis(N, vector<bool>(M, false));
        
        for (int i=0; i < N; i++){
            for(int j=0; j < M; j++){
                if (!vis[i][j]){
                    if (detect_cycle ( i, j, -1, -1, vis, grid )) return true;
                }
            }
        }
        return false;
    }
};

int main(){
    Solution s;
    vector<vector<char>> grid {{'w', 'w', 'm'},{'w', 'w', 'm'}, {'m', 'm', 'm'}};
    if (s.containsCycle(grid)) cout<<"Cycle Detected";
    else cout<<"Cycle Not Detected";
    return 0;
}