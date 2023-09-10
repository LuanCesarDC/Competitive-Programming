#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    int t; cin >> t;
    while(t--) {
        ll n; cin >> n;
        vector<int> v(n),X;
        X.push_back(0);
        for(int &x:v) cin >> x;
        for(int i=0;i<n;i++) X.push_back(X[i] ^ v[i]);
        string bits; cin >> bits;
        ll A = 0;
        for(int i=0;i<n;i++) {
            if(bits[i] == '0') {
                A ^= v[i];
            }
        }
        ll q; cin >> q;
        while(q--) {
            ll tp; cin >> tp;
            if(tp == 1) {
                ll l,r; cin >> l >> r;
                A ^= X[r] ^ X[l-1];
            } else {
                ll g; cin >> g;
                if(g == 0) {
                    cout << A;
                    if(q == 0) cout << "\n";
                    else cout << " ";
                } else {
                    cout << (A ^ X[n]);
                    if(q == 0) cout << "\n";
                    else cout << " ";
                }
            }
        }

    }


    return 0;
}