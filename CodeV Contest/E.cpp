#include<bits/stdc++.h>
#define f0(i,n) for(int i=0; i<n; i++)
#define f1(i,n) for(int i=1; i<=n; i++)

using namespace std;

int diff_pair(vector<int> vec, int diff){
    int pair = 0, n = vec.size();
    unordered_map<int, int> us;

    f0(i,n){
        if (us.find(vec[i]) != us.end()){
            pair += us[vec[i]];
        }
        
        if (us.find(vec[i]+diff) == us.end()){
            us[vec[i]+diff] = 1;
        }

        else{
            us[vec[i]+diff] += 1;
        }

        if (us.find(vec[i]-diff) == us.end()){
            us[vec[i]-diff] = 1;
        }

        else{
            us[vec[i]-diff] += 1;
        }
    }
    
    return pair;

}

int main (){
    vector<int> vec{2,3,5,2,7,9,1,10,4,11,8};
    int diff = 3;
    
    cout<< diff_pair(vec, diff);

    return 0;
}