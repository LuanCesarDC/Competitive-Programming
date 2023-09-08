#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s; cin >> s;
    char last = s[0];   
    ll res = 1, maxi = 1;
    
    for(int i=1;i<s.length();i++) {
        if(s[i] == last) {
            res++;
            if(res > maxi) {
                maxi = res;
            }
        } else {
            res = 1;
            last = s[i];
        }
    }
    cout << maxi << "\n";

    return 0;
}