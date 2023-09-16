#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; cin >> t;
    string base = "YesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYes";
    while(t--) {
        string s; cin >> s;
        if(base.find(s) != string::npos) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
    return 0;
}