#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n, m; cin >> n >> m;
    vector<ll> v(n+1, 0);
    ll diff = 0;

    for(int i=0;i<m;i++) {
        ll aux; cin >> aux;
        if(v[aux] == 0)
            diff++;
        v[aux]++;

        if(diff == n) {
            cout << 1;
            for(int j=1;j<=n;j++) {
                v[j]--;
                if(v[j] == 0) {
                    diff--;
                }
            }
        } else {
            cout << 0;
        }
    }

    cout << "\n";
    return 0;
}