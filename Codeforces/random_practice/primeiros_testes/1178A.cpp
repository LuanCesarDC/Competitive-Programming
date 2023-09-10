#include <bits/stdc++.h>

using namespace std;

#define MOD 998244353
typedef long long ll;

ll ffe(ll a, ll b) {
    ll act = 1;
    while(b > 0) {
        if(b & 1 == 1) {
            act = (act*a) % MOD;
        }
        a = (a*a) % MOD;
        b >>= 1;
    }
    return act % MOD;
}

int main() {
    ll m, n; cin >> m >> n;

    cout << ffe(2, m+n) << "\n";

    return 0;
}