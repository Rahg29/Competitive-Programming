#include<iostream>
using namespace std;
#define f0(i, it, n) for(int i=it; i<n-it; i++)
#define f1(i, it, n) for(int i= it+1; i<n-it; i++)
#define f2(i, it, n) for(int i= it+1; i<n-it-1; i++)
int main (){

    int N, max_ind,it=0, temp=0;
    cin>>N;
    int Arr[N][N];
    max_ind = (N-1)/2;
    while ( it < max_ind){

    f0( i,it, N ) Arr[it][i] = temp+i+1;
    
    temp = Arr[it][N-1-it];
    
    f1(i,it,N) Arr[i][N-1-it] = temp+i;

    temp = Arr[N-1-it][N-1-it];

    f1(i,it,N) Arr[N-1-it][N-1-i-it] = temp+i;  

    temp = Arr[N-1-it][it];

    f2(i, it, N) Arr[N-i-it][it] = temp+i;

    ++it;
    temp = Arr[it][it];
    }

    Arr[max_ind][max_ind] = N*N;

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cout<<Arr[i][j]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}