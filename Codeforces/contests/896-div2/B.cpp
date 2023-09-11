#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define INF 4e9+7

void solve() {
    ll n, k, a, b; cin >> n >> k >> a >> b;
    vector<pair<ll, ll>>v;
    pair<ll, ll> prox_a = pair(INF, INF), prox_b = pair(INF, INF);
    ll dist_a = INF, dist_b = INF;
    for(ll i=0;i<n;i++) {
        ll x, y; cin >> x >> y;
        v.push_back(make_pair(x, y));
    }
    for(int i=0;i<n;i++) {
        if(i+1 == a || i+1 == b) continue;
        if(i >= k) break;
        if(llabs(v[i].first-v[a-1].first) + llabs(v[i].second-v[a-1].second) < dist_a) {
            prox_a = pair(v[i].first, v[i].second);
            dist_a = llabs(v[i].first-v[a-1].first) + llabs(v[i].second-v[a-1].second);
        }
        if(llabs(v[i].first-v[b-1].first) + llabs(v[i].second-v[b-1].second) < dist_b) {
            prox_b = pair(v[i].first, v[i].second);
            dist_b = llabs(v[i].first-v[b-1].first) + llabs(v[i].second-v[b-1].second);
        }
    }
    if(a <= k && b <= k) {
        cout << "0\n";
    } else if(a <= k) {
        ll op1 = llabs(v[a-1].first - v[b-1].first) + llabs(v[a-1].second - v[b-1].second);
        ll op2 = llabs(prox_b.first-v[b-1].first) + llabs(prox_b.second-v[b-1].second); 
        cout << min(op1, op2) << "\n";
    } else if(b <= k){
        ll op1 = dist_a + dist_b;
        ll op2 = llabs(v[a-1].first - v[b-1].first) + llabs(v[a-1].second - v[b-1].second);
        ll op3 = llabs(prox_a.first-v[a-1].first) + llabs(prox_a.second-v[a-1].second);
        cout << min(op1, min(op2, op3)) << "\n";
    } else {
        ll op1 = dist_a + dist_b;
        ll op2 = llabs(v[a-1].first - v[b-1].first) + llabs(v[a-1].second - v[b-1].second);
        ll op3 = llabs(prox_b.first-v[a-1].first) + llabs(prox_b.second-v[a-1].second) + dist_b;

        cout << min(op1, min(op2, op3)) << "\n";
    }

}

int main() {
    int t; cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}