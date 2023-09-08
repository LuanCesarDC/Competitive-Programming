#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {

    ll n; cin >> n;
    vector<bool>v(n, false);
    vector<ll>vpar, vimpar, vsorted;

    for(int i=0;i<n;i++) {
        ll aux; cin >> aux;
        if(aux%2 == 0) {
            v[i] = false;
            vpar.push_back(aux);
        } else {
            v[i] = true;
            vimpar.push_back(aux);
        }
    }
    sort(vpar.begin(), vpar.end());
    sort(vimpar.begin(), vimpar.end());
    ll indPar = 0, indImpar = 0;
    for(int i=0;i<n;i++) {
        if(v[i]) {
            vsorted.push_back(vimpar[indImpar]);
            indImpar++;
        } else {
            vsorted.push_back(vpar[indPar]);
            indPar++;
        }
    }
    for(int i=1;i<n;i++) {
        if(vsorted[i] < vsorted[i-1]) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while(t--) {
        solve();
    }
       




    return 0;
}