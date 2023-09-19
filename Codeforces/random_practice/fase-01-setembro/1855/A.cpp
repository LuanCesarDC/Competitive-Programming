#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    int val = 0;
    for(int i=1;i<=n;i++) {
        int aux; cin >> aux;
        if(aux == i) val++;
    }
    cout << val/2 + val%2 << "\n";
}

int main() {
    int t; cin >> t;
    while(t--) {
        solve();
    }
}