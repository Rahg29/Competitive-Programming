#include <bits/stdc++.h>
using namespace std;

int longest_common_subsequence(int i, int j, string s1, string s2, vector<vector<int>> dp){
    if (i < 0 || j < 0 ) return 0;

    else if (dp[i][j] != -1) return dp[i][j];

    else if (s1[i] == s2[j]) return 1 + longest_common_subsequence(i-1, j-1, s1, s2, dp);

    else{
        dp[i][j] = max (longest_common_subsequence(i-1, j, s1, s2, dp) , longest_common_subsequence(i, j-1, s1, s2, dp));
        return dp[i][j];
    }
}

int main (){
    int n, m;
    string s1, s2;
    cin>>s1>>s2;
    n = s1.size();
    m = s2.size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    
    cout<< longest_common_subsequence(n-1, m-1, s1, s2, dp);
    return 0;
}