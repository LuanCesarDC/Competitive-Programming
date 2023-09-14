#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
    ll n; cin >> n;
    vector<ll> v(n);
    for(ll &x:v) cin >> x;

    sort(v.begin(), v.end());

    cout << max(v[0]*v[1], v[n-1]*v[n-2]) << "\n";



}

int main() {
    int t; cin >> t;
    while(t--) {
        solve();
    }   

    return 0;
}