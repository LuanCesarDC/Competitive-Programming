#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ll n; cin >> n;
    ll max = 9999999;

    while(n--) {
        ll aux; cin >> aux;
        aux = abs(aux);
        
        if(max > aux) {
            max = aux;
        }
    }
    cout << max << "\n";
}