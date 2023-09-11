#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
    ll n; cin >> n;
    ll aux;
    for(int i=0;i<n;i++) cin >> aux;
    if(n%2 == 0) {
        cout << "2\n";
        cout << 1 << " " << n << "\n";
        cout << 1 << " " << n << "\n";
    } else {
        cout << "4\n";
        cout << 1 << " " << n << "\n";
        cout << 1 << " " << n-1 << "\n";
        cout << n-1 << " " << n << "\n";
        cout << n-1 << " " << n << "\n";
    }
}

int main() {
    int t; cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}