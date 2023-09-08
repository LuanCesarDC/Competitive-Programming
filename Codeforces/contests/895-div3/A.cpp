#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    int t; cin >> t;
    while(t--) {
        float a, b, c; cin >> a >> b >> c;
        float x = fabs(a-b)/2;

        cout << ceil(x/c) << "\n";
    }
    return 0;
}