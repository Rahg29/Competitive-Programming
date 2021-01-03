#include <bits/stdc++.h>
using namespace std;

int coin_change (int idx, int change, int arr[], vector<vector<int>> dp){
    
    if (idx == 6 || change < 0) return 0;
    
    else if (change == 0) return 1;

    else if (dp[idx][change] != -1) return dp[idx][change];

    else{
        dp[idx][change] = coin_change(idx, change-arr[idx], arr, dp) + coin_change(idx+1, change, arr, dp);
        return dp[idx][change];
    }
}


int main(){
    int change, arr[]={1, 2, 5, 10, 20, 50};
    cin>>change;
    vector<vector<int>> dp(6, vector<int>(change+1, -1));
    
    cout<<coin_change(0, change, arr, dp);
    return 0;
}