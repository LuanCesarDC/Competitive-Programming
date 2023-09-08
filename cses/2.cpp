#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n; cin >> n;
    ll ans = n;
    for(int i=1;i<=n-1;i++) {
        ll aux; cin >> aux;
        ans ^= (aux^i);
    }
    cout << ans << "\n";

    return 0;
}