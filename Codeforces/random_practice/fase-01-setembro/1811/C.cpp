#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> v(n), res;
    bool foi = false;
    for(int &x:v) cin >> x;

    for(int i=0;i<n-1;i++) {
        if(v[i] < v[i+1] && !foi) {
            res.push_back(v[i]);
            res.push_back(v[i]);
        } else if(!foi) {
            res.push_back(v[i]);
        } else if(v[i] < v[i+1]){
            
        }
    }
}

int main() {
    int t; cin >> t;
    while(t--) {

    }


    return 0;
}