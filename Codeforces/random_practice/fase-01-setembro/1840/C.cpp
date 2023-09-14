#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
    ll n, k, q; cin >> n >> k >> q;
    ll acum = 0, sum = 0;
    for(int i=0;i<n;i++) {
        ll aux; cin >> aux;
        if(aux <= q) {
            acum++;
        } else if(acum >= k){
            sum += (acum-k+2)*(acum-k+1)/2 > 0 ? (acum-k+2)*(acum-k+1)/2 : 0;
            acum = 0;
        } else {
            acum = 0;
        }
    }
    if(acum >= k) {
        sum += (acum-k+2)*(acum-k+1)/2 > 0 ? (acum-k+2)*(acum-k+1)/2 : 0;
    }
    cout << sum << "\n";

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