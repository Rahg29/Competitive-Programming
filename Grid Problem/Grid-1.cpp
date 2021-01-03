#include <iostream>
using namespace std;
int count;

void dfs(int x,int y, int arr[][6]){
    bool flag=false;
    ++count;
    arr[x][y] = 0;
    int a1 [] = {0, -1, -1, -1, 0, 1, 1, 1}, a2 [] = {-1, -1, 0, 1, 1, 1, 0, -1};
    for (int i=0; i<8; i++ ){
        if ( x+a1[i] >= 0 && x+a1[i] < 6 && y+a2[i] >=0 && y+a2[i] < 6 && arr[x+a1[i]][y+a2[i]] == 1 ){
            dfs( x+a1[i], y+a2[i], arr);
        }

    }

}
int main (){
    int max_value=0, no_of_forest=0, 
    Arr[6][6]={     {1,1,0,0,0,1},
                    {0,1,1,0,1,0},
                    {0,1,0,0,1,1},
                    {0,0,0,0,0,0},
                    {1,1,0,0,1,1},
                    {0,1,0,0,1,1}   };
    
    for (int i=0; i<6; i++){
        for (int j=0; j<6; j++){
            if (Arr[i][j] == 1){
                count = 0;
                dfs(i,j, Arr);
                ++no_of_forest;
                if (max_value < count) max_value = count;
                cout<<"forest: "<<no_of_forest<<" trees "<<count<<endl;
            }
        }
    }


    cout<<"The number of forest in a given grid: "<<no_of_forest<<" and maximum trees in a given forest is "<<max_value;
        

    return 0;
}