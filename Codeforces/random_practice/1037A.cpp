#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ll n; cin >> n;
    ll res = 0;
    while(n > 0) {
        n /= 2;
        res++;
    }
    cout << res << "\n";
    return 0;
}