#include<bits/stdc++.h>
using namespace std;

int chain_multiplication(int i, int n, int arr[], vector<vector<int>> dp){
    int min = INT_MAX;
    
    if(i == n) return 0;

    else if (dp[i][n] != -1) return dp[i][n];

    else{
        int temp;

        for(int k=i; n > k; k++){
            temp = arr[i-1] * arr[k] * arr[n] + chain_multiplication(i, k, arr, dp) + chain_multiplication(k+1, n, arr, dp);

            if (temp < min ) min = temp;
        }

        return dp[i][n] = min;
    }
}

int main(){
    int arr[]={10, 30, 5, 60};
    int n = 4;
    vector<vector<int>> dp(n, vector<int>(n, -1));
    cout<<chain_multiplication(1, n-1, arr, dp);
    return 0;
}