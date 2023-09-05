#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n; cin >> n;
    vector<pair<ll, ll>> ql;

    for(ll i=0;i<n;i++){
        ll aux1, aux2; cin >> aux1 >> aux2;
        ql.push_back(make_pair(aux1, aux2));
    }   

    sort(ql.begin(), ql.end());

    ll ant = -1;
    for(pair<ll, ll> x:ql) {

        if(ant <= x.second) {
            ant = x.second;
        } else {
            cout << "Happy Alex\n";
            return 0;
        }
    }

    cout << "Poor Alex\n";


}