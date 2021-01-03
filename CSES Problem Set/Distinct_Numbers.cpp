#include<iostream>
#include<unordered_set>
using namespace std;

int main() {
    int n, res=0;
    cin >> n;
    long ele;
    unordered_set<long> us;
    for (int i=0; i< n; i++){
        cin>>ele;
        if (us.find(ele) == us.end()){
            us.insert(ele);
            res +=1;
        }  
    }
    cout<<res;
    return 0;
}