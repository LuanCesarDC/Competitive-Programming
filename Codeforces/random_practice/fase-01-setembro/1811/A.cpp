#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
    ll n; cin >> n;
    char c; cin >> c;
    string s; cin >> s;

    for(int i=0;i<n;i++) {
        if(s[i] < c) {
            cout << s.substr(0,i) << c << s.substr(i, n-i) << "\n";
            return;
        }
    } 
    cout << s << c << "\n";

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}