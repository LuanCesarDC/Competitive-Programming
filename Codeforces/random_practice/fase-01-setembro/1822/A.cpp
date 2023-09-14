#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, t; cin >> n >> t;
    vector<int> a(n), b(n);
    int idx = -1, mx = 0;

    for(int &x:a) cin >> x;
    for(int &x:b) cin >> x;

    for(int i=0;i<n;i++) {
        if(b[i] > mx && a[i]+i <= t) {
            mx = b[i];
            idx = i+1;
        }
    }
    cout << idx << "\n";
}

int main() { 
    int t; cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}