#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while(t--) {
        ll a, b; cin >> a >> b;
        vector<vector<char>>v(a, vector<char>(b));
        bool v1 = false, v2 = false, v3 = false, v4 = false;

        for(int i=0;i<a;i++) {
            for(int j=0;j<b;j++) {
                cin >> v[i][j];
            }
        }

        for(int i = 0;i<b;i++) {
            for(int j=0;j<a;j++) {
                if(!v1 && v[j][i] == 'v') {
                    v1 = true;
                    break;
                } else if(v1 && !v2 && v[j][i] == 'i') {
                    v2 = true;
                    break;
                } else if(v1 && v2 && !v3 && v[j][i] == 'k') {
                    v3 = true;
                    break;
                } else if(v1 && v2 && v3 && !v4 && v[j][i] == 'a') {
                    v4 = true;
                    break;
                }
            }
        }

        if(v1 && v2 && v3 && v4) {
            cout << "YES\n"; 
        } else {
            cout << "NO\n";
        }

    }

    return 0;
}