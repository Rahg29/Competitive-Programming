#include <iostream>
#include <sstream>
#include <vector>
#include<cmath>
using namespace std;

int min_time_cal(vector<int> p, int t){
    int n = p.size();
    bool dp[n+1][t+1];
    for (int i=0; i<=t; i++) dp[0][i]=false;
    for (int i=0; i<=n; i++) dp[i][0]=true;

    for (int k=1; k<=n; k++){
        for(int l=1; l<=t; l++){
            
            dp[k][l] = dp[k-1][l];

            if (p[k] <= l){
                dp[k][l] = dp[k][l] || dp[k-1][l - p[k]];
            }


        }
    }

    int m=t;
    while(m){
        if (dp[n][m]) break;
        --m;
    }
    return m; 
}

int main(){
    int time_sum, min_time;
    float f;
    vector<int> petrol;
    string str, cache;
    
    getline(cin, str);
    stringstream ss(str);

    while(ss >> cache){
        int num = stoi(cache);
        petrol.push_back(num);
        f +=num;
    }
    time_sum = ceil(f/2);
    min_time = min_time_cal(petrol, time_sum);
    cout<<min_time; 
    return 0;
}
 