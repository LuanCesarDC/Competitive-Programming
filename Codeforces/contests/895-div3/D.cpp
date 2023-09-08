#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while(t--) {
        ll n, x, y; cin >> n >> x >> y;
        ll lcm = x * y / __gcd(x, y);
        ll choques = n/lcm;
        ll nx = n/x - choques;
        ll ny = n/y - choques;

        ll valx = (n + (n-nx+1))*nx/2;
        ll valy = (1+ny)*ny/2;

        cout << valx - valy << "\n";

        



    }
    return 0;
}