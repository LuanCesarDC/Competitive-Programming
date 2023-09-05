#include <bits/stdc++.h>

#define INF 0x3f3f3f3f

using namespace std;

typedef long long ll;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, k; cin >> n >> k;
    vector<ll> v(n);

    for(ll &x:v) {
        cin >> x;
    }

    if(n == 1) {
        cout << 1 << endl;
        return 0;
    }

    ll sum = 0;
    ll minimum = INF;

    for(int i=0;i<k;i++) {
        sum += v[i];
    }
    minimum = sum;
    ll res = 1;

    for(int i = k;i<n;i++) {
        sum -= v[i-k];
        sum += v[i];

        if(sum < minimum) {
            minimum = sum;
            res = i-k+2;
        }
    } 

    cout << res << "\n";

    return 0;
}