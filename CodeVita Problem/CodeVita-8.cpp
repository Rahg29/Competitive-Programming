#include <bits/stdc++.h>
using namespace std;

int main (){
    int n, j=0, bit_min, bit_max, bit_pair=0;
    string st;
    vector<string> vec;
    unordered_map<int, int> bit1, bit2;

    cin>>n;
    for( int i=0; i<n; i++){
        cin>>st;
        vec.push_back(st);
    }

    for(auto it: vec){
        int t;
        bit_max = (it[0]>it[1]) ? it[0] : it[1];
	    bit_max = (it[2]>bit_max) ? it[2] : bit_max;
	    bit_min = (it[0]<it[1]) ? it[0] : it[1];
	    bit_min = (it[2]<bit_min) ? it[2] : bit_min;

        bit_min=int(bit_min-48);
        bit_max=int(bit_max-48);
        int temp = bit_max*11 + bit_min*7;
        
        temp = temp % 100;
        temp = temp/10;
        if (j % 2 == 0){
            if (bit1.find(temp) == bit1.end())
                bit1.insert(make_pair(temp, 1));
            
            else 
                bit1[temp] +=1;
                
        }

        else{
            if (bit2.find(temp) == bit2.end())
                bit2.insert(make_pair(temp, 1));
            
            else
                bit2[temp] +=1;

        }

        ++j;
    }
    
    for(auto it1: bit1){
        if(it1.second >=3)
            bit_pair +=2;
        else if(it1.second == 2)
            bit_pair +=1;
    }

    for(auto it2: bit2){
        if(it2.second >=3)
            bit_pair +=2;
        else if(it2.second == 2)
            bit_pair +=1;
    }    

    cout<<bit_pair;
    return 0;
}