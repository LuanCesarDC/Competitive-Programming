#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
    ll n; cin >> n;
    vector<pair<ll, ll>>v;
    vector<ll> res(n);
    for(ll i=0;i<n;i++) {
        ll aux; cin >> aux;
        v.push_back(make_pair(aux, i));
    }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    for(ll i=0;i<n;i++) {
        res[v[i].second] = i+1;
    }
    for(ll i=0;i<n;i++) {
        cout << res[i] << " ";
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