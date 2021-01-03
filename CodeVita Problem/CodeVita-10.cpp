#include<bits/stdc++.h>
#define f(i,n) for(int i=1; i<n; i++ )


using namespace std;

int main (){
    int r, c;
    cin>>r>>c;
    int arr[r+1][c+1];
    f(i,r) arr[i][0] =1;
    f(i,c) arr[0][i] =1;

    f (i,r){
        f (j, c){
            arr[i][j]=arr[i-1][j]+arr[i][j-1];
        }
    }

    cout<<arr[r-1][c-1];
    return 0;
}