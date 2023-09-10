#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define INF 0x3f3f3f3f

void solve() {
    vector<int> v;
    
    for(int i=1;i<=10;i++) {
        v.push_back(i);
    }

    for(int i=0;i<2*3*4*5*6*7*8*9*10;i++) {
        int max = 0;
        int res = 0;
        for(int j=0;j<10;j++) {
            if(v[j]*(j+1) > max) {
                max = v[j]*(j+1);
            }
            res += v[j] * (j+1);
        }
        res -= max;
        for(int i=0;i<10;i++) cout << v[i] << " ";
        cout << ": " << res << "\n";
        if(res == 303) break;
        next_permutation(v.begin(), v.end());
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;cin >> t;
    while(t--) {
        solve();
    }


    return 0;
}