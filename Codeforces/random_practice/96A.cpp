#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s; cin >> s;

    int countone = 0;
    int countzero = 0;
    for(char c:s) {
        if(c == '0') {
            countzero++;
            countone = 0;
        } else {
            countone++;
            countzero = 0;
        }
        if(countone >= 7 || countzero >= 7) {
            cout << "YES\n";
            return 0;
        }
    }

    cout << "NO\n";

    return 0;
}