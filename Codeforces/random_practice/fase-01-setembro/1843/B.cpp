#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define CIN ios_base::sync_with_stdio(false);cin.tie(0)

void solve() {
    ll n; cin >> n;
    vector<ll>v(n);
    ll negativo = 0, positivo = 0, sum = 0;
    int pos = -1;
    for(int i=0;i<n;i++) {
        cin >> v[i];
        sum += llabs(v[i]);
        if(v[i] < 0) {
            if(pos == 0 || pos == -1) {
                pos = 1;
                negativo++;
            }
        } else if(v[i] > 0) {
            if(pos == 1 || pos == -1) {
                pos = 0;
                positivo++;
            }
        }
    }
    if(positivo >= negativo) {
        cout << sum << " " << negativo << "\n";
    } else {
        cout << sum << " " << positivo + 1 << "\n";
    }
}

int main() {
    CIN;
    int t; cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}