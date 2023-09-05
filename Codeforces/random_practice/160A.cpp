#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n; cin >> n;
    ll sum = 0, totalearned = 0;
    ll res = 0;
    vector<ll> v(n);

    for(ll &x:v) {
        cin >> x;
        sum += x;
    }
    
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());

    for(ll x:v) {
        totalearned += x;
        res++;
        sum -= x;

        if(totalearned > sum) {
            cout << res << "\n";
            return 0;
        }
    }


    return 0;
}