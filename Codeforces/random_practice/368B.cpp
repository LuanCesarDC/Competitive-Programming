#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll m, n; cin >> m >> n;
    ll acum = 0;
    set<ll>st;
    vector<ll>v(m), ps(m);
    
    for(ll &x:v) {
        cin >> x;    
    }

    for(int i=m-1;i>=0;i--) {
        ll aux = v[i];
        if(st.find(aux) == st.end()) {
            acum++;
        }
        st.insert(aux);
        ps[i] = acum;
    }

    while(n--) {
        ll aux; cin >> aux;
        cout << ps[aux-1] << "\n";
    }

    return 0;
}

// 1 2 3 4 1 2 3 4 100000 99999
//            5 4  3    2       1