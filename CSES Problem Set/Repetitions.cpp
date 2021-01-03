#include <iostream>
 
using namespace std;
 
int main() {
    int max_rep = 0, rep = 0;
    string s;
    cin >> s;
    char base = s[0];

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == base) rep++;
        else {
            max_rep = max(max_rep, rep);
            base = s[i];
            rep = 1;
        }
    }
    max_rep = max(rep, max_rep);
    cout << max_rep;
    return 0;
}