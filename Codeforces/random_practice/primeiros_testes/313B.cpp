#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s; cin >> s;
    vector<int>v(1, 0);
    ll aux = 0;
    
    for(int i=1;i<s.length();i++) {
        if(s[i-1] == s[i]) {
            aux++;
        }
        v.push_back(aux);
    }

    ll n; cin >> n;
    while(n--) {
        ll a, b; cin >> a >> b;
        cout << v[b-1] - v[a-1] << "\n";
    }


    return 0;
}

// #..###
// 001123