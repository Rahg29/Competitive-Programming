#include<iostream>
#include<unordered_set>
using namespace std;

int main (){
    long long n, sum;
    unordered_set<int> s;
    cin>>n;
    sum = (n * (n+1)) / 2;
    if (sum % 2 != 0){
        cout<<"NO";
    }
    else{
        cout<<"YES"<<endl;
        sum = sum/2;
        int temp, i=1;
        if (sum % n == 0){
            s.insert(n);
            temp = sum / n;
            while(temp>1){
                s.insert(n-i);
                s.insert(i);
                --temp;
                ++i;
            }

        }

        else{
            temp = sum/(n+1);
            while(temp !=0){
                s.insert(n-i+1);
                s.insert(i);
                --temp;
                ++i;
            }
            ++n;
        }
        cout<<s.size()<<endl;
        for(auto it: s){
            cout<<it<<" ";
        }

        cout<<endl<< n-i-i+1 <<endl;
        for(int e=i; e<= n-i; e++){
            cout<<e<<" ";
        }
    }

    return 0;
}