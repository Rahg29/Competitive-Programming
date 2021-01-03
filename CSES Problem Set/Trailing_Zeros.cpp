#include<iostream>
using namespace std;

int main (){
    long long n, trail_zero = 0;
    cin>>n;
    while(n >= 5){
        n = n / 5;
        trail_zero +=n;
    }
    cout<<trail_zero;
    return 0;
}