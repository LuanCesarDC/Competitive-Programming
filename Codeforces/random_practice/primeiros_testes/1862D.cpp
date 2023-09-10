#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
    ll x; cin >> x;
    ll l = (1+sqrt(8*x+1))/2;
    ll r = l+1;
    ll vall = l*(l-1)/2, valr = r*(r-1)/2;
    ll tot_used = max(vall, valr-(r-1)+1);
    ll i_used = vall > valr-(r-1)+1 ? l : r;
    cout << i_used + x - tot_used << "\n";
}

void solve2() {
    ll x; cin >> x;
    ll l = 2, r = 2e9;
    ll val = 2;
    while(l <= r) {
        ll mid = (l+r)/2;
        if(mid*(mid-1)/2 <= x) {
            val = mid;
            l = mid+1;
        } else {
            r = mid-1;
        }
    }
    ll ans = val + x - val*(val-1)/2;
    cout << ans << endl;
}

int main() {
    int t; cin >> t;
    while(t--) {
        solve2();

    }

    return 0;
}