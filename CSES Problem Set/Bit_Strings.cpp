#include<bits/stdc++.h>
using namespace std;

int main (){
    long long   p, mod = 1e9 + 7,
                bit_str=1, n=2;
    cin>>p;

    while(p !=0){
        if (p%2==0){
            n = (n * n) % mod;
            p =p/2;

        }

        else{
            bit_str = (bit_str * n) % mod;
            --p;

        }   
    }
    cout<<bit_str;
    //return 0;
}