/******************************************************************************

                              Online C++ Debugger.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Debug" button to debug it.

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> res;
    void comb_calculation(string s, int n, int pt, int cnt){
        if (n == pt){
            while (cnt){
                s +=")";
                --cnt;
            }
            res.push_back(s);
        } 
        else{
            comb_calculation(s+"(", n, pt+1, cnt+1);
            if (cnt) comb_calculation(s+")", n, pt, cnt-1);
        }
    };
    
    vector<string> generateParenthesis(int n) {
        comb_calculation("", n, 0, 0);
        return res;
    }
};

int main()
{
    Solution s;
    vector<string> vs;
    vs = s.generateParenthesis(3);
    for(auto it:vs){
        cout<<it<<" ";
    }
    return 0;
}
