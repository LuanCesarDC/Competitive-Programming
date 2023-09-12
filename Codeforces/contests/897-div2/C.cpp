#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
    ll n; cin >> n;
    ll menor=1e9+7, maior = -1;
    vector<ll>v;
    
    for(ll i=0;i<n;i++) {
        ll aux; cin >> aux;
        v.push_back(aux);
        if(aux < menor) {
            menor = aux;
        }
        if(aux > maior) {
            maior = aux;
        }
    }
    ll res = 0;
    if(menor == 0) {
        bool foi = false;
        for(ll i=1;i<n;i++) {
            if(v[i]-v[i-1] > 1) {
                cout << v[i-1]+1 << "\n";
                foi = true;
                break;
            }
        }
        if(!foi) {
            cout << maior+1 << "\n";
        }
        cout.flush();
        while(true) {
            cin >> res;
            if(res == -1) return;
            cout << res << "\n";
        }
    } else {
        cout << "0\n";
        cin >> res;
    }

}

int main() {
    int t; cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}