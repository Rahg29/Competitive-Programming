#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    long long weight, sum=0;
    cin>>n;
    multiset<int> ms;
    for (int i=0; i<n; i++){
        cin>>weight;
        ms.insert(weight);
        sum += weight;
    }

    long long half_weig = sum/2, temp=0;

    for (auto s: ms){
        temp +=s;
        if (temp >= half_weig) break;
    }
    
    for(auto s: ms){
        if( temp >= half_weig) temp -= s;

        if ( temp < half_weig) {
            temp += s;
            break;
        }
    }

    cout<< ((2*temp) - sum);
    
    return 0;
}