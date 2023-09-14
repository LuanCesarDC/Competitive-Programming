#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ll n; cin >> n;
    ll x = 5, res = 0;
    while(x <= n) {
        res += n/x;
        x *= 5;
    }
    cout << res << "\n";


    return 0;
}