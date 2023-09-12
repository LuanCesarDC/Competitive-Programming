#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
    ll n; cin >> n;
    string s; cin >> s;
    string res;
    ll l = 0, r = n-1;
    ll x = 0;
    while(l < r) {
        if(s[l] != s[r]) {
            x++;
        }
        l++; r--;
    }

    for(ll i=0;i<=n;i++) {
        ll aux = x;
        ll mx = n - 2*x;
        ll faltam = i - x;
        if(faltam == 0) {
            res.push_back('1');
        } else if(faltam < 0) {
            res.push_back('0');
        } else {
            if(faltam > mx) {
                res.push_back('0');
            } else if(faltam%2 == 1) {
                if(n%2 == 1) {
                    res.push_back('1');
                } else {
                    res.push_back('0');
                }
            } else {
                res.push_back('1');
            }
        }
    }
    cout << res << '\n';
}

int main() {
    int t; cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}