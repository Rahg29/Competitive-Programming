#include<bits/stdc++.h>
#define f0(i,n) for(int i=0; i<n; i++)
#define f1(i,n) for(int i=1; i<=n; i++)

int cnt=0;
bool flag=false;
using namespace std;

void remaining_edge_cal(long long small){
    long long g = small/2;
   
    while( g > 1){
        if (small % g == 0){
            ++cnt;
            remaining_edge_cal(g);
            break;
        }
        --g;
    }
    if (g == 1) ++cnt;
}


void largest_factor(long long big, long long small){
    long long f = big / 2;
    while(f > 1){
        if (big % f == 0){
            ++cnt;
            if (f == small){
                flag = true;
                break;
            }
            largest_factor(f, small);
            break;
        }
        --f;
    }

    if (!flag){
        ++cnt;
        remaining_edge_cal(small);
    }   


}


int main (){
    long long m,n;
    cin>>m>>n;

    if (m > n){
        largest_factor(m, n);
    }

    else if (n > m){
        largest_factor(n, m);
    }
    
    else cout<< cnt;

    cout<<cnt;
    return 0;
}