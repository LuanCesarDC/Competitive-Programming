#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
   ll n; cin >> n;
    ll res = 1;
    while(n%res == 0) {
        res++;
    }
    cout << res-1 << "\n";
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