#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    int res = n;
    vector<int> v, s;
    for(int i=0;i<n;i++) {
        int aux; cin >> aux;
        v.push_back(aux);
        s.push_back(aux);
    }
    sort(s.begin(), s.end());

    for(int i=n-1;i>=0;i--) {
        if(s[i] == v[i]) {
            res--;
        } else {
            break;
        }
    }
    int mx = 0;
    for(int i=0;i<res;i++) {
        if(v[i] > mx) mx = v[i];
    }
    cout << mx << "\n";

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}