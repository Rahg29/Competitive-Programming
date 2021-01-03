#include<bits/stdc++.h>
using namespace std;

int main (){
    int n,m, res=0;
    long long k;
    cin>>n>>m>>k;
    long long arr[n], ele;
    multiset<long long> s;
    
    for(int i=0; i<n; i++){
        cin>>ele;
        arr[i]=ele;
    }

    for(int i=0; i<m; i++){
        cin>>ele;
        s.insert(ele);
    }

    for(int e=0; e<n; e++){
        auto it = s.lower_bound(arr[e]-k);

        if (arr[e]-k <= *(it) &&  *(it) <= arr[e]+ k ){
            res +=1;
            s.erase(*it);
        } 
        
    }
    cout<<res;
    return 0;
}