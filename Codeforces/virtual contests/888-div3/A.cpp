#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    int t; cin >> t;
    while(t--) {
        ll n,m,k,H; cin >> n >> m >> k >> H;
        ll res = 0;
        for(int i=0;i<n;i++) {
            ll aux; cin >> aux;
            if((llabs(H-aux) % k == 0) && (llabs(H-aux) / k < m) && (H != aux)) {
                res++;
            }   
        }  
        cout << res << "\n";

    }

    return 0;
}