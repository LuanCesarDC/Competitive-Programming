#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
    ll n; cin >> n;
    ll sum = (n+1) * n / 2, calc = 0;
    vector<ll> v, vind(n+1, 0);
    v.push_back(0);

    for(int i=0;i<n-1;i++) {
        ll aux; cin >> aux;
        v.push_back(aux);
    }
    ll passou = 0;
    for(int i=1;i<n;i++) {
        if(v[i]-v[i-1] <= n && vind[v[i]-v[i-1]] == 0) {
            vind[v[i]-v[i-1]]++;
        } else {
            passou = v[i]-v[i-1];
        }
    }
    ll faltou = 0, f1=-1, f2=-1;
    for(int i=1;i<=n;i++) {
        if(vind[i]==0) {
            faltou++;
            if(f1 == -1) {
                f1 = i;
            } else {
                f2 = i;
            }
        }
        if (faltou > 2) {
            cout << "NO\n";
            return;
        }
    }
    if(faltou == 2) {
        if(f1+f2 == passou) {
            cout << "YES\n";
            return;
        }
    }
    if(faltou == 1 && sum - v.back() == f1) {
        cout << "YES\n";
        return;
    }
    cout << "NO\n";
    // if(calc+faltou == sum) {
    //     cout << "YES\n";
    // } else {
    //     cout << "NO\n";
    // }
}

int main() {
    int t; cin >> t;
    while(t--) {
        
        solve();

    }

    return 0;
}