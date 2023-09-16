#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; cin >> t;
    while(t--) {
        int n, k; cin >> n >> k;
        long long s = 0, last = 1, mx = -1;
        vector<bool> v(51, false);
        for(int i=1;i<=n;i++) {
            int aux; cin >> aux;
            v[aux] = true;
            if(aux > mx) mx=aux;
        }
        for(int i=1;i<=mx;i++) {
            if(!v[i]) s += i;
            if(v[i]) last = i;
        }
        k -= s;
        while(k > 0) {
            last++;
            k-=last;
        }
        if(k == 0) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
        
    }

    return 0;
}