#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
    ll n, m, d; cin >> n >> m >> d;
    vector<ll>v(n);
    for(ll &x:v) cin >> x;
    ll ans = 0, sum = 0;
    set<pair<ll, ll>> st;
    for(int i=0;i<n;i++) {
        if(v[i] > 0) {
            st.insert(make_pair(v[i], i));
            sum += v[i];
            if(st.size() > m) {
                sum -= st.begin()->first;
                st.erase(st.begin());
            }
            ans = max(ans, sum - (i+1)*d);
        }
    }
    cout << ans << "\n";
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