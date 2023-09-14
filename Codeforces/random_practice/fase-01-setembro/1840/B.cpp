#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
    ll n, k; cin >> n >> k;
    if(k >= 30) {
        cout << n + 1 << "\n";
        return;
    }
    if(pow(2, k) <= n) {
        cout << (int) pow(2, k) << "\n";
    } else {
        cout << n+1 << "\n";
    }
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