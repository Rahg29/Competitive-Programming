#include<iostream>
using namespace std;

int fibonacci_number(int n, int dp[]){
    if (n <= 1) return n;

    else if (dp[n] != -1) return dp[n];

    else{
        dp[n] = fibonacci_number(n-1, dp) + fibonacci_number(n-2, dp);
        return dp[n];
    }

}

int main (){
    int n;
    cin>>n;
    int dp[n+1];
    for (int i=0; i<=n; i++) dp[i]=-1;
    cout << fibonacci_number(n, dp);
    return 0;
}