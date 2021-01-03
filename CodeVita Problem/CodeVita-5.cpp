#include<iostream>
using namespace std;

int factorial(int num){
    int fac=1;
    if (num >= 1){
        for(int i=2; i<=num; i++){
            fac *=i;
        }
    }
    return fac;
}

int main(){
    int n, num_two=1,count=1;
    cin>>n;
    
    while((num_two*2) <=n){
        int ele = n - num_two*2 + num_two;
        count += factorial(ele)/(factorial(num_two)*factorial(ele-num_two));
        ++num_two; 
    }
    cout<< count;


    return 0;
}