#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
    ll n; cin >> n;
    vector<ll>v(n), b, c;
    for(ll &x:v) cin >> x;
    sort(v.begin(), v.end());
    if(v.front() == v.back()) {
        cout << "-1\n";
    } else {
        ll x=0, y=0;
        for(int i=0;v[i]!=v.back();i++) {
            b.push_back(v[i]);
            x++;
        }
        for(int i=x;i<n;i++) {
            c.push_back(v[i]);
            y++;
        }
        if(b.size() == 0 || c.size() == 0) {
            cout << "-1\n";
        } else {
            cout << x << " " << y << "\n";
            cout << b[0];
            for(ll i=1;i<b.size();i++) {
                cout << " " << b[i];
            }
            cout << "\n";
            cout << c[0];
            for(ll i=1;i<c.size();i++) {
                cout << " " << c[i];
            }
            cout << "\n";
        }
        
    }   

}

int main() {
    int t;cin >> t;
    while(t--) {
        solve();

    }

    return 0;
}