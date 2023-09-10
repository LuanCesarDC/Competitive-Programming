#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

void solve() {
    ld n, d, h; cin >> n >> d >> h;
    vector<ld> v(n);
    ld area = (ld) d*h/2.0;
    for(ld &x:v) cin >> x;

    for(ll i=1;i<n;i++) {
        ld htot = v[i] - v[i-1];
        ld b = 0;

        if(htot < h) {
            b = (ld)(h-htot) * d / ((ld) 1.0 * h);
        } else {
            htot = h;
        }

        area += (b+d) * htot / 2;
    }
    cout << area << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout.precision(10);
    cout.setf(ios::fixed);

    int t; cin >> t;
    while(t--) {
        solve();

    }


    return 0;
}