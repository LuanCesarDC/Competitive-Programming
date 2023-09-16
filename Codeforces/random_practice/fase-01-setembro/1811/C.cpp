#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> v(n-1);
    for(int &x:v) cin >> x;

    cout << v[0];
    for(int i=0;i<n-2;i++) {
        cout << " " << min(v[i], v[i+1]);
    }
    cout << " " << v.back() << "\n";
}

int main() {
    int t; cin >> t;
    while(t--) {
        solve();
    }


    return 0;
}