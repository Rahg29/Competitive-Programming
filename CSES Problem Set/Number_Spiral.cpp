#include<iostream>
using namespace std;

int main(){
    int test;
    long long r, c, out;
    cin>>test;

    for (int t=0; t<test; t++){
        cin>>r>>c;

        if (r > c){
            if (r%2 == 0){
                out = r*r - c + 1;
                cout<<out;
            }
            else{
                out = (r-1)*(r-1) + c;
                cout<<out;
            }
        }

        else{
            if(c%2 == 1){
                out = c*c -r + 1;
                cout<<out;

            }

            else{
                out = (c-1)*(c-1) + r;
                cout<<out;
            }
        }
        cout<<endl;     

    }

    return 0;
}