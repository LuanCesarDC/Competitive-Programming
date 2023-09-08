#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n; cin >> n;

    while(n != 1) {
        cout << n << " ";
        if(!(n & 1)) {
            n >>= 1;
        } else {
            n = 3*n + 1;
        }
    }
    cout << n << "\n";

    return 0;
}