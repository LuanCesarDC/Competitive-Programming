#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    set<string> st;
    if(n == 2) {
        cout << "1\n";
        return;
    }
    for(int i=2;i<n;i++) {
        string st1 = s.substr(i-2, 2);
        string st2 = "";
        st2.push_back(st1.back());
        st2.push_back(s[i]);
        st.insert(st1);
        st.insert(st2);
    }
    cout << st.size() << "\n";
}

int main() {
    int t; cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}