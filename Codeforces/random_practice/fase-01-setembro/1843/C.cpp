#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
    ll n; cin >> n;
    ll sum = 0;
    while(n != 0) {
        sum += n;
        n /= 2;
    }
    cout << sum << "\n";
}

int main() {
    ll t; cin >> t;
    while(t--) {
        solve();

    }

    return 0;
}