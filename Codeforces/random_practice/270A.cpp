#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    while(n--) {
        int x; cin >> x;
        double N;

        N = 360.0/(180.0 - x); // Número de Lados de um polígono regular
        if(N == (int)N) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}