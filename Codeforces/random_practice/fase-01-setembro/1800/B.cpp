#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k; cin >> n >> k;
    int res = 0;
    vector<int> v(300, 0);
    string s; cin >> s;
    for(int i=0;i<n;i++) {
        v[s[i]]++;
    }

    for(int i=0;i<26;i++) {
        int up, lo, aumento;
        up = v['A'+i];
        lo = v['a'+i];
        // cout << k << " " << (char)('A'+i) << " " << up << " " << (char)('a'+i) << " " << lo << " " << res <<"\n";
        // if(up == 0 || lo == 0) continue;
        aumento = abs(up - lo);
        res += max(up, lo) - aumento;
        if(aumento/2 >= k) {
            res += k;
            k = 0;
        } else {
            res += aumento/2;
            k -= aumento/2;
        }
    }
    cout << res << "\n";
}

int main() {
    int t; cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}