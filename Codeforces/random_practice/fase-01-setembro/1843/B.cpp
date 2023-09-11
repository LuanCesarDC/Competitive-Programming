#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define CIN ios_base::sync_with_stdio(false);cin.tie(0)

void solve() {
    ll n; cin >> n;
    vector<ll>v(n);
    ll negativo = 0, positivo = 0;
    cin >> v[0];
    bool pos = false;
    if(v[0] < 0) {
        pos = false;
        negativo++;
    } else if(v[0] > 0){
        pos = true;
        positivo++;
    }
    for(int i=1;i<n;i++) {
        cin >> v[i];
        if(v[i-1]*v[i] < 0) {
            
        }
    }

}

int main() {
    CIN;
    int t; cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}