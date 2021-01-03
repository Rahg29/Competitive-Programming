#include<iostream>
using namespace std;

int main (){
    int t;
    long long a, b;
    cin>>t;

    for (int i=0; i<t; i++){
        cin>>a>>b;

        if (a > b){
            if (a <= 2*b){
                while(a != b){
                    a -=2;
                    b -=1;
                }
            }
            else a=1;
        }

        else if (b > a){
            if (b <= 2*a){
                while(a != b){
                    b -=2;
                    a -=1;
                }
            }
            else a=1;
        }

        if (a % 3 ==0){
            cout<<"YES";
        }

        else{
            cout<<"NO";
        }

        cout<<endl;
    }
    return 0;
}