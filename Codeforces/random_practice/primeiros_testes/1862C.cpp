#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
    ll n; cin >> n;
    ll l=0, r=n, count = 0;
    vector<ll>v(n), res;
    for(ll &x:v) cin >> x;
    reverse(v.begin(), v.end());
    while(r-l > 0) {
        ll last = v[r-1];   
        if(last-count != r-l) {
            cout << "NO\n";
            return;
        } else {
            count++;
            r--;
            l = upper_bound(v.begin(), v.end(), count) - v.begin();
        }
    }
    cout << "YES\n";
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