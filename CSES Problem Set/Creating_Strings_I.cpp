#include<bits/stdc++.h>
using namespace std;

int calculate_numerator(int len, int max){
    int n_fact = 1;
    for (int i = max+1; i<=len; i++){
        n_fact *= i;
    }
    return n_fact;
}

int calculate_denominator(int v){
    int n_fact = 1;
    
    for (int i = 2; i <= v; i++){
        n_fact *= i;
    }
    return n_fact;
}

int main(){
    string st;
    unordered_map<char, int> um;
    cin>>st;
    vector<int> vec;
    int len = st.size();
    
    for (int i=0; i < len; i++){
        
        if (um.find(st[i]) == um.end()){
            um[st[i]] = 1;
        }
        else{
            um[st[i]] += 1;
        }
    }
    int max_v = 0;

    for (auto it : um){
        if (it.second > max_v) max_v = it.second;
        else vec.push_back(it.second);
    }

    int numerator = calculate_numerator( len, max_v);    
    int denominator=1;
    for (auto v:vec){
        if (v > 2) denominator *= calculate_denominator(v);
        else denominator *= v;
    }

    cout<< numerator/denominator;

    sort( st.begin(), st.end());

    do{
        cout<<endl<<st;
    }
    while (next_permutation(st.begin(), st.end()));
        

    return 0;
}