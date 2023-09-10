#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        ll sum = 0;
        while(n--) {
            int a, b; cin >> a >> b;
            if(b < a) {
                sum++;
            }

        }
        cout << sum << "\n";
    }
    

    return 0;
}