#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll calculaFaixa(ll n, ll x, ll y) {
    if(y >= x && x+y <= n+1) {
        return x;
    } else if(y >= x && x+y < n+1) {
        return n-x+1;
    } else if(y < x && x+y <= n+1) {
        return n-y+1;
    } else {
        return y;
    }
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