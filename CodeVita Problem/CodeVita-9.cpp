#include<iostream>
using namespace std;

int main(){
    int test, N, *arr, *cmp, *temp;
    
    cin>>test;
    for (int i=0; i<test; i++){
        cin>>N;
        arr = new int[N];
        cmp = new int[N];
        temp = new int[N];
        
        for (int j=0; j<N; j++){
            cin>>arr[j];
            cmp[j]=j;
            temp[j]=j;
        }

        int count=0;
        bool flag=true;

        while (flag){
            flag = false;

            for (int k=0; k<N; k++){
                temp[arr[k]-1]=cmp[k];
                
                if ( temp[arr[k]-1] != arr[k]-1 ){
                    flag=true;
                }

            }

            for (int l=0; l<N; l++){
                cmp[l]=temp[l];
            }

            ++ count;
        }
     
    cout<<count<<endl;
    delete [] arr, cmp, temp;
    }

    return 0;
}
