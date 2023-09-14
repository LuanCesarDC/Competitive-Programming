#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ll n; cin >> n;
    if(((n+1)*n/2) % 2 != 0) {
        cout << "NO\n";
    } else {
        vector<ll> res;
        ll x = 0, act = n, i=1, esq = false, qtd = 0;
        while(x != n*(n+1)/4) {
            if(esq) {
                res.push_back(i);
                x+=i;
                i++;    
                esq = false;
            } else {
                res.push_back(act);
                x+=act;
                act--;
                esq = true;
            }
            qtd++;
        }
        cout << "YES\n";
        cout << qtd << "\n";
        cout << res[0];
        for(int j=1;j<qtd;j++) {
            cout << " " << res[j];
        }
        cout << "\n";
        cout << n-qtd << "\n" << i;
        for(int j=i+1;j<=act;j++) {
            cout << " " << j;
        }
        cout << "\n";

    }


    return 0;
}