#include<bits/stdc++.h>
#define f0(i,n) for(int i=0; i<n; i++)
#define f1(i,n) for(int i=1; i<=n; i++)

using namespace std;

int main (){
    string str="aaaabaaaa";
    int i=1, n, it;
    vector<string> vec;
    unordered_set<char> s;
    //cin>> str;
    stack<char> stk;
    bool flag=false;
    n = str.size();
    
    if (str[0] == str[1]){
        i=1;
    }

    else{
    
    stk.push(str[0]);
    s.insert(str[0]);

    while( !stk.empty() && i < n){
        if (s.find(str[i]) == s.end()){
            stk.push(str[i]);
            s.insert(str[i]);
        }

        else{
            if (str[i] != stk.top()){
                char temp = stk.top();
                stk.pop();
                if (str[i] == stk.top()) stk.pop();
                else{
                    stk.push(temp);
                    stk.push(str[i]);
                }
            }

            else{
                stk.pop();
            }
            

        }
        ++i;

    }

    }

    if (stk.empty() && i < n){
        it = i;
        vec.push_back(str.substr(0,i));
        
        if ( str[i] == str[i+1]){
            i++;
        }
        
        else{
        
        stk.push(str[i]);
        s.clear();
        s.insert(str[i]);
        ++i;
        while( !stk.empty() && i < str.size()){
            if (s.find(str[i]) == s.end()){
                stk.push(str[i]);
                s.insert(str[i]);
            }

            else{
                if (str[i] != stk.top()){
                    char temp = stk.top();
                    stk.pop();
                    if (str[i] == stk.top()) stk.pop();
                    
                    else{
                        stk.push(temp);
                        stk.push(str[i]);
                    }
                }

                else{
                    stk.pop();
                }
            }
            
            ++i;

        }

        }

        if (stk.empty() && i < n){
            vec.push_back(str.substr(it, i-it));
            int lst = i;
            while(n > i){
                if (str[n-1] != str[i]){
                    flag=true;
                    break;
                }
                --n;
                ++i;
            }
            if (flag) cout<<"Impossible";
            else{
                vec.push_back(str.substr(lst));
                cout<<vec[0]<<endl;
                cout<<vec[1]<<endl;
                cout<<vec[2];
            }
        }

        else cout<<"Impossible";

    }

    else{
        cout<<"Impossible";
    }
    
    return 0;
}