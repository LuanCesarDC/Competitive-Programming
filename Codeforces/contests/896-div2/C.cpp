#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll MEX(vector<ll>v) {
    ll x = v.size();
    vector<bool>b(x+1, 0);
    for(ll i=0;i<x;i++) {
        b[v[i]] = true;
    }
    for(ll i=0;i<=x;i++) {
        if(b[i] == false) {
            return i;
        }
    }
    return 0;
}

void solve() {
    ll n, m; cin >> n >> m;
    vector<vector<ll>> v(n, vector<ll>(m));
    vector<ll> res;
    ll act = 1;
    
    for(ll i=0;i<n;i++) {
        if((i+1)%m == 0) {
            act = (act+1)%m;
        }
        for(ll j=0;j<m;j++) {
            v[i][j] = act;
            act = (act+1)%m;
        }
        act = (act+1)%m;
    }  
    
    for(ll i=0;i<m;i++) {
        vector<ll> aux;
        for(ll j=0;j<n;j++) {
            aux.push_back(v[j][i]);
        }
        res.push_back(MEX(aux));
    }
    cout << MEX(res) << "\n";

    for(ll i=0;i<n;i++) {
        for(ll j=0;j<m;j++) {
            cout << v[i][j] << " ";
        }
        cout << "\n";
    }


}

int main() {
    int t; cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}