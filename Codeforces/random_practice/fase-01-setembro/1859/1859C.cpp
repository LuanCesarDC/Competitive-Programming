#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define INF 0x3f3f3f3f

void solve() {
    ll n; cin >> n;
    ll ans = 0;
    vector<int> v(n+1);
    for(int i=1;i<=n;i++) {
        v[i] = i;
    }
    for(int i=1;i<=n;i++) {
        ll sum = 0, mx = 0;
        reverse(v.end()-i+1, v.end());
        reverse(v.end()-i, v.end());
        for(int j=1;j<=n;j++) {
            sum += v[j] * j;
            mx = (mx < v[j] * j) ? v[j] * j : mx;
        }
        sum -= mx;
        ans = max(ans, sum);
    }
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