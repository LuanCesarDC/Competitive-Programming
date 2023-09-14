#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    int t; cin >> t;
    while(t--) {
        ll n; cin >> n;
        ll res = (n+1)*2 + n*n;
        cout << res << "\n";
    }   

    return 0;
}