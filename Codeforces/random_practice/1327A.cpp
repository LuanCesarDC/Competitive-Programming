#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ll t; cin >> t;

    while(t--) {
        ll n,k; cin >> n >> k;

        if((n-k)%2 == 0 && (n-k)/2 >= (k-1)*k/2) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}