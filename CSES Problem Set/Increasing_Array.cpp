#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    long long ele, turn=0;
    cin>>n;
    vector<long long> vec;
    for(int i=0; i<n; i++){
        cin>>ele;
        vec.push_back(ele);
    }

    for(int i=0; i<n-1; i++){
        if(vec[i] > vec[i+1]){
            turn += vec[i] - vec[i+1];
            vec[i+1] = vec[i];
        }
    }
    cout<<turn;
    return 0;
}