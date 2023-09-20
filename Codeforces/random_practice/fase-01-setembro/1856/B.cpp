#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
    ll n; cin >> n;
    ll count1 = 0, counth = 0;

    for(int i=0;i<n;i++) {
        ll aux; cin >> aux;
        if(aux == 1) count1++;
        else counth += aux-1;
    }

    if((counth >= count1) && (n > 1)) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

}


int main() {
    int t; cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}