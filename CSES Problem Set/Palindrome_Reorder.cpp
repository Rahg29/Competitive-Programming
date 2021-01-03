#include<bits/stdc++.h>
using namespace std;

int main(){
    string st;
    unordered_map<char, int> m;
    bool flag =false;
    //list<char> l1, l2 ,l3;
    cin>>st;
    int len = st.size();
    for(int i=0; i < len; i++){
        if (m.find(st[i]) == m.end()){
            m[st[i]] = 1;
        }

        else{
            m[st[i]] += 1;
        }

    }

    int pos = 0;
    for (auto it : m){
        int i = it.second;
        char c = it.first;
        if (i % 2 == 1 && !flag){
            flag = true;
            st[(len - 1)/2] = c;
            --i;
            
        }
        else if (i % 2 == 1 && flag){
            cout<<"NO SOLUTION";
            return 0;
        }

        while( i !=0 ){
            st[pos] = c;
            st[len-1-pos] = c;
            ++pos;
            i -= 2;
        }
    }
    cout<<st; 
    return 0;
}