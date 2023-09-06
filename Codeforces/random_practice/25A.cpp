#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ll n; cin >> n;
    ll npar = 0, nimpar = 0;
    ll par = -1, impar = -1;
    for(int i=0;i<n;i++) {
        ll aux; cin >> aux;
        if(aux%2 == 0) {
            npar++;
            par = i+1;
        } else {
            nimpar++;
            impar = i+1;
        }
    }

    if(npar > nimpar) {
        cout << impar << "\n";
    } else {
        cout << par << "\n";
    }

    return 0;
}