#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
    ll n; cin >> n;
    bool pegar = true;
    string s, res = ""; cin >> s;
    for(ll i=0;i<n;i++) {
        if(pegar) {
            res.push_back(s[i]);
            pegar = false;
        } else if(s[i] == res.back()) {
            pegar = true;
        }
    }
    cout << res << "\n";
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