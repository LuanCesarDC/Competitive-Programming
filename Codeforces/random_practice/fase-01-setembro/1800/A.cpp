#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, index = 0; cin >> n;
    string s; cin >> s;
    int fase = 0; 
    bool M = false, E = false, O = false, W = false;

    while(fase == 0 && index < n) {
        if(s[index] == 'm' || s[index] == 'M') {
            index++;
            M = true;
        } else if((s[index] == 'e' || s[index] == 'E') && M) {
            fase++;
        } else {
            cout << "NO\n";
            return;
        }
    }
    while(fase == 1 && index < n) {
        if(s[index] == 'e' || s[index] == 'E') {
            index++;
            E =true;
        } else if((s[index] == 'o' || s[index] == 'O') && E) {
            fase++;
        } else {
            cout << "NO\n";
            return;
        }
    }

    while(fase == 2 && index < n) {
        if(s[index] == 'o' || s[index] == 'O') {
            index++;
            O = true;
        } else if((s[index] == 'w' || s[index] == 'W') && O) {
            fase++;
        } else {
            cout << "NO\n";
            return;
        }
    }

    while(fase == 3 && index < n) {
        if(s[index] == 'w' || s[index] == 'W') {
            index++;
        } else {
            cout << "NO\n";
            return;
        }
    }

    if(fase == 3) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

}

int main() {
    int t; cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}