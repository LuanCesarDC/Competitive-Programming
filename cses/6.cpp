#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll t; cin >> t;
    while(t--) {
        ll x, y; cin >> x >> y;
        ll mxy = max(x,y);
        ll z = (mxy-1) * (mxy-1);

        if(mxy & 1) {
            ll a = 1, b = mxy;
            ll res = z + (x-a) + (y-b);
            cout << res << "\n";
        } else {
            ll a = mxy, b = 1;
            ll res = z + abs(x-a) + abs(y-b);
            cout << res << "\n";
        }
    }

    return 0;
}