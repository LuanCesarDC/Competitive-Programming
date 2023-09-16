#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll calculaFaixa(ll n, ll x, ll y) {
    if(x > n/2) x = n+1-x;
    if(y < x) return y;
    if(y >= x && y <= n+1-x) return x;
    if(y > n/2) return n+1-y;
    else return y;
}

int main() {
    int t; cin >> t;
    while(t--) {
        ll n, x1,y1, x2,y2;
        cin >> n >> x1 >> y1 >> x2 >> y2;
        cout << llabs(calculaFaixa(n, x1, y1)-calculaFaixa(n, x2, y2)) << "\n";
    }

    return 0;
}