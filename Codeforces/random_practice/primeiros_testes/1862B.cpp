#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--) {
        ll n;cin >> n;
        vector<ll> v(n), res;
        for(ll &x:v) cin >> x;
        res.push_back(v[0]);
        for(ll i=1;i<n;i++) {
            if(v[i-1] <= v[i]) {
                res.push_back(v[i]);
            } else {
                res.push_back(v[i]);
                res.push_back(v[i]);
            }
        }
        cout << res.size() << "\n";
        cout << res[0];
        for(int i=1;i<res.size();i++) {
            cout << " " << res[i];
        }
        cout << "\n";
    }

    return 0;
}