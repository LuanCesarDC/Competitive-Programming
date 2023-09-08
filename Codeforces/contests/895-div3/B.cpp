#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define INF 0x3f3f3f3f

int main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        ll maxim = INF;
        for(int i=0;i<n;i++) {
            ll d, s; cin >> d >> s;
            ll trap_value = d+s/2;
            if(s%2 == 0) trap_value--;
            // cout << trap_value << "\n";
            if(trap_value < maxim) {
                maxim = trap_value;
            }
        }
        // cout << "\n";
        cout << maxim << "\n";
    }

    return 0;
}