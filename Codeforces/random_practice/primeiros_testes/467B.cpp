#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ll n, m, k; cin >> n >> m >> k;
    ll res = 0;
    vector<ll> v;

    for(ll i=0;i<=m;i++) {
        ll aux; cin >> aux;
        v.push_back(aux);
    }

    for(ll i=0;i<m;i++) {
        ll dif = v[m] ^ v[i];
        ll count = 0;
        while(dif) {
            count += dif & 1;
            dif >>= 1;
        }
        if(count <= k) {
            res++;
        }
    }

    cout << res << "\n";
    return 0;
}

// 7 3 1
// 8    0001000
// 5    0000101
// 111  1101111
// 17   0010001