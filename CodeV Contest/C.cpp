#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size(), max_len=1, i,j;
        vector<vector<bool>> dp (n, vector<bool>(n, false));
        
        if (s.size() == 0) return "";

        string res = s.substr(0,1);
        
        for (int r = n; r >= 1; r--){
            i = -1;
            j = n-r-1;
            
            for (int pt=0; pt < r; pt ++){
                i += 1;
                j += 1;
                string temp_str = s.substr(i, j-i+1);
                
                if ( j-i == 0) dp[i][j] = true;
                
                else if (j-i == 1){
                    if (s[i] == s[j]){
                        dp[i][j] = true;
                        
                        if (max_len < 2){
                            max_len = 2;
                            res = temp_str;
                        }
                    }
                }
                
                else{
                    if (s[i] == s[j]){
                        if (dp[i+1][j-1]){
                            dp[i][j] = true;
                            
                            if (max_len < j-i+1){
                                max_len = j-i+1;
                                res = temp_str;
                            }
                            
                        }
                    }
                }
            }
        }
        
        return res;
        
    }
};

int main(){
    Solution sl;
    string r = sl.longestPalindrome("klvxwqyzugrdoaccdafdfrvxiowkcuedfhoixzipxrkzbvpusslsgfjocvidnpsnkqdfnnzzawzsslwnvvjyoignsfbxkgrokzyusxikxumrxlzzrnbtrixxfioormoyyejashrowjqqzifacecvoruwkuessttlexvdptuvodoavsjaepvrfvbdhumtuvxufzzyowiswokioyjtzzmevttheeyjqcldllxvjraeyflthntsmipaoyjixygbtbvbnnrmlwwkeikhnnmlfspjgmcxwbjyhomfjdcnogqjviggklplpznfwjydkxzjkoskvqvnxfzdrsmooyciwulvtlmvnjbbmffureoilszlonibbcwfsjzguxqrjwypwrskhrttvnqoqisdfuifqnabzbvyzgbxfvmcomneykfmycevnrcsyqclamfxskmsxreptpxqxqidvjbuduktnwwoztvkuebfdigmjqfuolqzvjincchlmbrxpqgguwuyhrdtwqkdlqidlxzqktgzktihvlwsbysjeykiwokyqaskjjngovbagspyspeghutyoeahhgynzsyaszlirmlekpboywqdliumihwnsnwjc");

    cout<<r;
    return 0;
}