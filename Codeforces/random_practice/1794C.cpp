#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    int t; cin >> t;

    while(t--) {
        ll n; cin >> n;
        vector<ll>v(n), res;
        ll index = 1;

        for(ll &x:v) {
            cin >> x;
        }
    
        ll es=0, di=0;
        while(di<n) {
            ll k = di - es + 1;
            if(v[es] >= k) {
                cout << k << "\n";
            } else {
                while(v[es] < k) {
                    es++;
                    k = di - es + 1;
                }
                cout << k << "\n";
            }
            di++;
        }
        
        

    }

    return 0;
}