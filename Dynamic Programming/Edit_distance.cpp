#include<bits/stdc++.h>
using namespace std;

int edit_distance( int n, int m, string &s1, string &s2, vector<vector<int>> dp){
    if (n < 0 || m < 0){
        return n+1+m+1;
    }

    else if (dp[n][m] != -1) return dp[n][m];

    else if ( s1[n] == s2[m]) return dp[n][m] = edit_distance(n-1, m-1, s1, s2, dp);

    else{
        int i = 1 + edit_distance(n, m-1, s1, s2, dp);         // Insert opertion
        int j = 1 + edit_distance(n-1, m, s1, s2, dp);        // Remove operation
        int k = 1 + edit_distance(n-1, m-1, s1, s2, dp);     // Replace operation

        dp[n][m] = min(i, min(j, k));
        return dp[n][m];
    }

}

int main(){
    string s1, s2;
    cin>>s1>>s2;
    int n = s1.size(), m = s2.size(); 
    vector<vector<int>> dp(n, vector<int>(m, -1));

    cout<<edit_distance(n-1, m-1, s1, s2, dp);
    return 0;
}