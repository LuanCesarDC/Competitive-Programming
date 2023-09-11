#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
    ll n; cin >> n;
    vector<bool>v(n+1, false);
    vector<ll> ans(1, 1);
    v[1] = true;
    for(ll i=2;i<=n;i++) {
        if(!v[i]) {
            ans.push_back(i);
            v[i] = true;
        }
        int j = i;
        while(j*2 <= n && !v[j*2]) {
            ans.push_back(j*2);
            v[j * 2] = true;
            j *= 2;
        }
    }
    cout << ans[0];
    for(int i=1;i<n;i++) {
        cout << " " << ans[i];
    }
    cout << "\n";
}

int main(){ 
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}