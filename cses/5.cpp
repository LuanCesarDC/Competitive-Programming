#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n; cin >> n;

    if(n == 3 || n == 2) {
        cout << "NO SOLUTION\n";
    } else if(n == 1) {
        cout << "1\n";
    } else {
        for(int i=2;i<=n;i+=2) {
            cout << i << " ";
        }
        for(int i=1;i<=n;i+=2) {
            if(i == n || i == n-1) {
                cout << i << "\n";
            } else {
                cout << i << " ";
            }
        }
    }

    return 0;
}