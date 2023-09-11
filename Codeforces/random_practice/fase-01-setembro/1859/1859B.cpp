#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define INF 0x3f3f3f3f

void solve() {
    ll n;cin >> n;
    ll m, menor = INF, ans = 0;
    vector<pair<ll, ll>> v;
    for(ll i=0;i<n;i++) {
        m; cin >> m;
        vector<ll> aux(m);
        for(int j=0;j<m;j++) {
            cin >> aux[j];
        }
        sort(aux.begin(), aux.end());
        v.push_back(make_pair(aux[1], aux[0]));
        if(aux[0] < menor) {
            menor = aux[0];
        }
    }
    sort(v.begin(), v.end());
    for(int i=1;i<n;i++) {
        ans += v[i].first;
    }
    ans += menor;
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;cin >> t;
    while(t--) {
        solve();
    }


    return 0;
}