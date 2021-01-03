#include<iostream>
using namespace std;

int main (){
    int l1, l2, w1, w2, sum=0, a, b;
    cin>>l1;
    cin>>l2;
    cin>>w1;
    cin>>w2;

    for (int i=l1; i<=l2; i++){
        for(int j=w1; j<=w2; j++){
            a=i;
            b=j;
            while( a % b != 0 ){
                int temp=b;
                sum += a / b;
                b = a % b;
                a=temp;

            }

            sum += a/b;
        }
    }

    cout<<sum;
    return 0;
}