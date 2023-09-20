#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<ll>fib(1000000, -1);

ll calcfib(ll x) {
    if(x == 0) return 0;
    if(x == 1) return 1;
    if(fib[x] != -1) return fib[x];
    return fib[x] = calcfib(x-1) + calcfib(x-2);
}

void solve() {
    ll n, k; cin >> n >> k;
    ll ans = 0;
    if(k >= 1000000) {
        cout << "0\n";
        return;
    }

    if(n < calcfib(k)) {
        cout << "0\n";
        return;
    }
    ll idx = 0;
    while(n - calcfib(k)*idx >= 0) {
        if((n - calcfib(k)*idx)%(calcfib(k-1)) == 0) {
            ans++;
        }
        idx++;
    }
    cout << idx << "\n";

}

int main() {
    int t; cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}