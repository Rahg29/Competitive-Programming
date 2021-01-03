#include<bits/stdc++.h>
using namespace std;

int main(){
    string ft, sd, out;
    cin >> ft >> sd; 
    multiset<char> ms;
    int n=0;
    
    for (auto sit : ft){
        ms.insert(sit);
        ++n;
    }
    
    for (int i=0; i< n; i++){
        auto it = ms.lower_bound(sd[i]);

        if (it == ms.end()){
                out = "-1";
                break;
        }

        else{
            if( *it == sd[i] && i < n-1){
                out +=sd[i];
                ms.erase(it);

            }


            else if (*it == sd[i] && i == n-1){
                out +=sd[i];
                bool flag = next_permutation(out.begin(), out.end());
            }

            else {
                out += *it;
                ms.erase(it);
                for (auto it: ms)
                    out += it;
                break;
    

            }


        }
    }

    cout<<out;
    return 0;
}