#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<ll>fib(46, 1);

bool solve(ll n, ll x, ll y) {
    if(n == 0) return true;
    if(n == 1) return true;
    if(y > fib[n-1] && y <= fib[n]) {
        return false;
    }
    if(y > fib[n]) y = fib[n+1] - y + 1;
    
    return solve(n-1, fib[n-1]-y+1, x);
}

int main() {
    for(ll i=2;i<=45;i++) fib[i] = fib[i-1] + fib[i-2];

    int t; cin >> t;
    while(t--) {
        ll n, x, y; cin >> n >> x >> y;
        bool res = solve(n, x, y);
        if(res) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}