#include<iostream>
#include<list>
#include<vector>
#include<cmath>
using namespace std;

bool perfect_square(int num){
    double srt = sqrt(num);
    return (srt == floor(srt));
}

int main (){
    int n, i=1, factor, non_sqr=0;
    list<int> lst;
    vector<int> v_sqr;
    
    cin >> n;
    factor = n;

    while (factor >= 2){
        factor = n/i;
        if( (factor*i) == n ){
            lst.push_front(factor);
        }
        ++i;
    }
    if (lst.size()){
        for (auto lt: lst){
            if (perfect_square(lt)){
                v_sqr.push_back(lt);
                continue; 
            }
            bool flag= true;
            for (auto vt: v_sqr){
                if( lt % vt == 0 ){
                    flag = false;
                }

            }

            if (flag) non_sqr += 1; 
        }

        cout<<non_sqr;

    }
    else
    {
        non_sqr = 0;
        cout<<non_sqr;
    }
    
    return 0;
}