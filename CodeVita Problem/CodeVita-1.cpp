#include <iostream>
#include<queue>
using namespace std;

int main (){
    int n, count;
    char c;
    string str;
    queue <char> bride, groom;
    cin>>n;
    // An alternate way to assign value using char c. For that there is no requirement of getline function.
    cin.ignore(); // It is used when cin is used before getline. It inserts new line character.

    getline(cin, str); // Optinal for alternative method
    for (int i=0; i<n; i++){
        // cin>>c;
        //bride.push(c);

        bride.push(str[i]); // Optional for alternative method 
    }

    getline(cin, str); // Optinal for alternative method
    for (int i=0; i<n; i++){
        // cin>>c;
        //groom.push(c);
        
        groom.push(str[i]); // Optinal for alternative method
    }

    int iter=0;

    while (!bride.empty() && iter < n){
        if (bride.front() == groom.front()){
            bride.pop();
            groom.pop();
            iter = 0;
            --n;
        }

        else{
            
            c = groom.front();
            groom.pop();
            groom.push(c);
            ++iter;
        }
    }
    
    count = bride.size();
    cout<<count;
    
    
    
    return 0;
}