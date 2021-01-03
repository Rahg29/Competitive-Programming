#include <bits/stdc++.h>
using namespace std;

int knapsack_problem (int i, int w, vector<int> vec, vector<int> wgh, vector<vector<int>> dp){
    if (i < 0 || w == 0) return 0;

    else if (dp[i][w] != -1) return dp[i][w];

    else if (wgh[i] > w) return dp[i][w] = knapsack_problem( i-1, w, vec, wgh, dp);

    else{
        dp[i][w] = max( vec[i] + knapsack_problem( i-1, w - wgh[i], vec, wgh, dp), 
        knapsack_problem( i-1, w, vec, wgh, dp) );
        return dp[i][w];
    }

}

int main (){
    int n, element, w, weight;
    cin >> n >> w;
    vector<int> vec(n);
    vector<int> wgh(n);

    for (int i=0; i<n; i++){
        cin>>element>>weight;
        vec[i] = element;
        wgh[i] = weight;
    }
    vector<vector<int>> dp(n, vector<int>(w+1, -1));
    cout<<knapsack_problem( n-1, w, vec, wgh, dp);
    return 0;
}