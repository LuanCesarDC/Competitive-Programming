#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
    ll n, k; cin >> n >> k;
    vector<pair<ll, ll>> a, b;
    vector<ll> b_unord;
    for(ll i=0;i<n;i++) {
        ll aux; cin >> aux;
        a.push_back(make_pair(aux, i));
    }
    for(ll i=0;i<n;i++) {
        ll aux; cin >> aux;
        b_unord.push_back(aux);
    }
    sort(a.begin(), a.end());
    sort(b_unord.begin(), b_unord.end());

    for(ll i=0;i<n;i++) {
        b.push_back(make_pair(a[i].second, b_unord[i]));
    }
    sort(b.begin(), b.end());
    for(pair<ll, ll> x:b) {
        cout << x.second << " ";
    }
    cout << "\n";
}

int main() {
    int t; cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}