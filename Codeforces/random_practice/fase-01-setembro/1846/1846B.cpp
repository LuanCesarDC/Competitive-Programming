#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
    vector<string> v;
    for(int i=0;i<3;i++) {
        string s; cin >> s;
        v.push_back(s);
    }

    for(int i=0;i<3;i++) {
        if(v[i] == "XXX") {
            cout << "X" << "\n";
            return;
        }
        if(v[i] == "OOO") {
            cout << "O" << "\n";
            return;
        }
        if(v[i] == "+++") {
            cout << "+" << "\n";
            return;
        }
    }
    for(int i=0;i<3;i++) {
        if(v[0][i] != '.' && v[0][i] == v[1][i] && v[1][i] == v[2][i]) {
            cout << v[0][i] << "\n";
            return;
        }
    }
    if(v[0][0] != '.' && v[0][0] == v[1][1] && v[1][1] == v[2][2]) {
        cout << v[0][0] << "\n";
        return;
    }
    if(v[0][2] != '.' && v[0][2] == v[1][1] && v[1][1] == v[2][0]) {
        cout << v[1][1] << "\n";
        return;
    }
    cout << "DRAW\n";
}

int main() {
    int t; cin >> t;

    while(t--) {
        solve();


    }


    return 0;
}