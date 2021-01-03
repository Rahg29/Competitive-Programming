#include<iostream>
using namespace std;

int main(){
    long long n;
    cin>>n;

    if (n == 1){
        cout<<n;
    }
    
    else{
        long long i=2;
        if (n-2 <= 1){
            cout<<"NO SOLUTION";
        }
        else{

            while(i <= n){
                cout<<i<<" ";
                i=i+2;
            }
            i=1;
            while(i <= n){
                cout<<i<<" ";
                i=i+2;
            }    
        }
        
    }

    return 0;
}