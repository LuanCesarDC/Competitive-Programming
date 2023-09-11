#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
    ll a, b,c; cin >> a >> b >> c;
    if(a+c > b+c) {
        cout << "First\n";
    } else if(a+c < b+c) {
        cout << "Second\n";
    } else {
        if(c%2 == 0) {
            cout << "Second\n";
        }else {
            cout << "First\n";
        }
    }

}

int main() {
    int t; cin >> t;

    while(t--) {
        solve();

    }

    return 0;
}