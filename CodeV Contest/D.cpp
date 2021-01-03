#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int str_count; 
    string res;
    
    string shortestPalindrome(string s) {
        int n = s.size();
        str_count = n;
        if (n < 2){
            return s;
        }
        
        else{
            for (int i=0; i<n-1; i++){
                shortest_string(s, i, i);
                shortest_string(s, i, i+1);
            }
            reverse(res.begin(), res.end());
            return res + s;
        }
    }
    
    void shortest_string(string s, int begin, int end){
        int n = s.size();
        while(begin>=0 && end < n && s[begin] == s[end]){
            --begin;
            ++end;
        }
        
        if (begin == -1){
            if (str_count > n-end){
                str_count = n-end;
                res = s.substr(end, n-end);
            }
        } 
    }
};

int main(){
    Solution sl;
    
    cout<<sl.shortestPalindrome("vbpbgbpbvvehmsdocuqfnpzsqqsjbjkvzpqsubqbpjhzojdtkjc");

    return 0;
}