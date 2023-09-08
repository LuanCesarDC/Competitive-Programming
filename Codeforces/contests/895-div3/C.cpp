#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--) {
        ll l, r; cin >> l >> r;
        if(r <= 3) {
            cout << -1 << "\n";
        } else if(r-l >= 1) {
            if(r%2 == 0) {
                cout << r/2 << " " << r/2 << "\n";
            } else {
                cout << (r-1)/2 << " " << (r-1)/2 << "\n";
            }
        } else {
            if(r%2 == 0) {
                cout << r/2 << " " << r/2 << "\n";
            } else {
                bool foi = false;
                for(ll i=2;i<=sqrt(r);i++) {
                    if(r%i == 0) {
                        cout << i << " " << r-i << "\n";
                        foi = true;
                        break;
                    }
                }
                if(!foi) {
                    cout << -1 << "\n";
                }
            }
        }

    }
    return 0;
}