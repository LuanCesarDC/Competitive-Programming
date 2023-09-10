#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
    ll n,m,h; cin >> n >> m >> h;
    ll pts = 0, total = 0, tempo_gasto = 0;
    ll pos = 1;
    vector<ll>v(m);
    for(int i=0;i<m;i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    for(int i=0;i<m;i++) {
        if(tempo_gasto + v[i] > h) {
            break;
        } else {
            tempo_gasto += v[i];
            total += tempo_gasto;
            pts++;
        }
    } 
    for(int i=1;i<n;i++) {
        ll pti = 0, totali = 0, tempo_gastoi = 0;
        vector<ll>vi(m);
        for(int j=0;j<m;j++) {
            cin >> vi[j];
        }
        sort(vi.begin(), vi.end());
        for(int j=0;j<m;j++) {
            if(tempo_gastoi + vi[j] > h) {
                break;
            } else {
                tempo_gastoi += vi[j];
                totali += tempo_gastoi;
                pti++;
            }
        }
        if(pti > pts) {
            pos++;
        } else if(pti == pts) {
            if(total > totali) {
                pos++;
            }
        }
    }
    cout << pos << "\n";

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >>  t;

    while(t--) {
        solve();

    }

    return 0;
}