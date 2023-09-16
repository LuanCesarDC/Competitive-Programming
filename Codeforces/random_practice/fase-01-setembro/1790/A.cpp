#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; cin >> t;
    string pi = "3141592653589793238462643383279502";
    while(t--) {
        string s; cin >> s;
        int res = 0;
        for(int i=0;i<s.size();i++) {
            if(pi[i] != s[i]) {
                break;
            } else {
                res++;
            }
        }
        cout << res << "\n";
    }
}