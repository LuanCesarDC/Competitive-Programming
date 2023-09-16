#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    int idx = 0;
    long long res = 0;
    vector<int>v(n);
    priority_queue<int> st;
    for(int &x:v) cin >> x;

    while(idx < n) {
        if(v[idx] > 0) {
            st.push(v[idx]);
            idx++;
        } else {
            if(!(v[idx] == 0 && idx < n && !st.empty())) {
                idx++;
            }
            while(v[idx] == 0 && idx < n && !st.empty()) {
                idx++;
                res += st.top();
                st.pop();
            }
            // st = priority_queue<int>();
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