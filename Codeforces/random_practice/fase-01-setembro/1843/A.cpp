#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
    ll n; cin >> n;
    ll s = 0;
    deque<ll>v(n);
    for(ll &x:v) cin >> x;
    sort(v.begin(), v.end());
    while(v.size() > 1) {
        s += llabs(v.front() - v.back());
        v.pop_back();
        v.pop_front();
    }
    cout << s << "\n";
}

int main() {
    int t; cin >> t;
 
   while(t--) {
        solve();
    }
    return 0;
}