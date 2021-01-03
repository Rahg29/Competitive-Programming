#include<bits/stdc++.h>
using namespace std;

int main (){
    int n, ele, LIS;
    cin>>n;
    int arr[n];
    vector<int> vec;
    
    for (int i=0; i<n; i++){
        cin>>ele;
        arr[i] = ele;
    }

    vec.push_back(arr[0]);
    
    for(int i=1; i<n; i++){
        if (arr[i] > vec[i-1]) vec.push_back(arr[i]);
        
        else{
            auto it = upper_bound( vec.begin(), vec.end(), arr[i] );
            int e = it - vec.begin();
            vec[e] = arr[i];
        }
    }
    cout<<vec.size();
    return 0;
}