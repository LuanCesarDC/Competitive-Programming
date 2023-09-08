#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
    ll n, k; cin >> n >> k;
    vector<ll> v(n);

    for(ll &x:v) {
        cin >> x;
    }
    ll ind_first = -1, ind_last = -1;
    ll first = v[0], last = v[n-1], fk = 0, lk = 0;
    for(int i=0;i<n;i++) {
        if(v[i] == first) {
            fk++;
        }
        if(fk == k) {
            ind_first = i;
            break;
        }   
    }
    for(int i=n-1;i>=0;i--) {
        if(v[i] == last) {
            lk++;
        }
        if(lk == k) {
            ind_last = i;
            break;
        }   
    }
    if(v[ind_first] == v[n-1]) {
        cout << "YES\n";
        return;
    }
    if(ind_first == -1 || ind_last == -1 || ind_first > ind_last) {
        cout << "NO\n";
        return;
    }
    // vector<int> vcount(ind_last - ind_first + 1, 0);
    // for(int i=ind_first+1;i<ind_last;i++) {
    //     vcount[v[i]]++;
    //     if(vcount[v[i]] >= k) {
    //         cout << "YES\n";
    //         return;
    //     }
    // }
    cout << "YES\n";
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