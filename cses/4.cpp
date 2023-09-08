#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n; cin >> n;
    vector<ll>v(n);
    ll res = 0;
    for(ll &x:v) {
        cin >> x;
    }
    
    for(int i=1;i<n;i++) {
        if(v[i] < v[i-1]) {
            res += v[i-1] - v[i];
            v[i] = v[i-1];
        }
    }
    cout << res << "\n";
    return 0;
}