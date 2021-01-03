#include<iostream>
using namespace std;

int main(){
    int n, num_five, sum;
    cin>>n;
    num_five = (n-5)/5;
    if ( (5+(n-5)%5) <= 7 ) sum = num_five + 3;
    else sum = num_five + 4;
    cout<<sum;
    

    return 0;
}