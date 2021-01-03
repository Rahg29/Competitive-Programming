#include<bits/stdc++.h>
#define f(i,n) for(int i=1; i<n; i++ )
#define f0(i,n) for(int i=0; i<n; i++ )


using namespace std;

int main (){
    vector<vector<int>> vec { {2, 3, 12, 32, 7, 3},
                              {8, 1, 5, 3, 27, 9},
                              {1, 6, 13, 36, 8, 1},
                              {1, 15, 22, 32, 39, 10},
                              {1, 40, 12, 32, 7, 3},
                              {1, 1, 1, 1, 1, 1}  
                            };
    f( i, vec.size()) vec[0][i] += vec[0][i-1];
    f( i, vec.size()) vec[i][0] += vec[i-1][0];

    f(i, vec.size()){
        f(j, vec[i].size()){
            int min_value = min(vec[i][j-1], vec[i-1][j]);
            vec[i][j] += min_value; 

        }
    }

    f0(i, vec.size()){
        f0(j, vec[i].size())
            cout<< vec[i][j]<<" ";
        cout<<endl;
    }
    
    return 0;
}