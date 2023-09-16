#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; cin >> t;
    while(t--) {
        int n, s, r; cin >> n >> s >> r;
        int falta = n-1, sobrou = r; 
        for(int i=0;i<n-2;i++) {
            cout << (int) sobrou/falta << " ";
            sobrou -= sobrou/falta;
            falta--;
        }
        cout << sobrou << " " << s-r << "\n";
    }
}