#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
    ll n; cin >> n;
    ll pares = 0, impares = 0;
    vector<ll>v(n);
    for(ll &x:v) {
        cin >> x;
        if(x%2==0) pares++;
        else impares++;
    };
    sort(v.begin(), v.end());
    if(v[0]%2 == 0) {
        for(ll i=n-1;i>=0;i--) {
            if(v[i]%2!=0) {
                impares--;
                if(impares <= 0) {
                    cout << "NO\n";
                    return;
                }
            } else {
                pares--;
            }
        }
    } else {
        for(ll i=n-1;i>=0;i--) {
            if(v[i]%2==0) {
                pares--;
                if(impares <= 0) {
                    cout << "NO\n";
                    return;
                }
            } else {
                impares--;
            }
        }
    }
    cout << "YES\n";
}

int main() {
    int t; cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}