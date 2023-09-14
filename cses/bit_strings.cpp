#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define MOD 1000000007

ll bin_exp(ll x) {
    ll ans = 1;
    ll base = 2;
    while(x > 0) {
        if(x&1) {
            ans = (ans*base)%MOD;
        }
        x >>= 1;
        base = (base*base)%MOD;
    }
    return ans%MOD;
}

int main() {
    ll x; cin >> x;
    cout << bin_exp(x) << "\n";

    return 0;
}