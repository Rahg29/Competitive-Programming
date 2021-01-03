#include <bits/stdc++.h>
using namespace std;

bool average_detect(int i, int n, int s1, int arr[], vector<int> &res, vector<vector<vector<bool>>> dp){
      if ( i < 0 || n == 0) return s1 == 0;

      else if (dp[s1][n][i] == false) return dp[s1][n][i];

      else if (arr[i] > s1){
          if (average_detect(i-1, n, s1, arr, res, dp)){
              return true;
          }
      }

      else{
          res.push_back(arr[i]);
          if (average_detect(i-1, n-1, s1-arr[i], arr, res, dp)) return true;
          res.pop_back();
          if (average_detect(i-1, n, s1, arr, res, dp)) return true;
      }
      return dp[s1][n][i] = false;    
      
}

int main (){
    int n, a, s = 0, s1;
    cin >> n;
    int arr[n];
    
    for (int i=0; i<n; i++){
        cin >> a;
        arr[i] = a;
        s += a;
    }

    vector<vector<vector<bool>>> dp( s, vector<vector<bool>>( n, vector<bool>(n, true)));
    
    for (int i=1; i<n; i++){
        a = s*i;
        if ( a % n == 0 ){
            s1 = a / n ;
            vector<int> res;

            if(average_detect(n-1, i, s1, arr, res, dp)){
                
                unordered_set<int> us;
                cout<<"ELements for set 1:"<<endl;
                
                for (auto s: res){
                    cout<<s<<" ";
                    us.insert(s);
                } 
                
                cout<<"\nElements for Set 2:\n";
                
                for (int i=0; i<n; i++){

                    if (us.find(arr[i]) == us.end()) cout<<arr[i]<<" "; 
                
                }
                break;
            }



        }


    }
    return 0;
}