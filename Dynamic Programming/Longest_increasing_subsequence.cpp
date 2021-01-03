#include <bits/stdc++.h>
using namespace std;

int main (){
    vector<int> vec;
    string s, t;
    getline(cin, s);
    stringstream ss(s);
    int n=0;
    while(ss >> t){
        int i = stoi(t);
        vec.push_back(i);
        ++n;
    }
    int seq[n];
    seq[0] = 1;
    for (int i=1; i<n; i++){
        seq[i] = 1;
        for(int j=0; j<i; j++){
            if (seq[j] + 1 > seq[i] && vec[i] > vec[j] ) seq[i] = seq[j] + 1;
        }
    }

    auto it = max_element(seq, seq+n);
    cout<< "Length of longest subsequence: "<<*it;
    int idx = it - seq;
    stack<int> stk;
    stk.push(vec[idx]);
    --idx;
    for (idx; idx>=0; idx--){
        if (seq[idx] + 1 == seq[idx+1]){
            stk.push(vec[idx]);
        }
    }
    cout<<"Longest increasing sequence:\n";
    while(! stk.empty()){
        cout<<stk.top()<<" ";
        stk.pop();
    }
    return 0;
}