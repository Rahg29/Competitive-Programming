#include<iostream>
#include<vector>
using namespace std;

int main(){
    long long  result, N, ele;
    cin>>N;
    result = (N * (N+1)) / 2;
    for(int i=0; i < N-1; i++){
        cin>>ele;
        result -= ele;
    }
    cout<<result;
    return 0;
}