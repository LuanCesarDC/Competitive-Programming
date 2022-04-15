#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n; cin >> n;
	
	while(n--) {
		string s; cin >> s;
		int a, b, c;
		a = count(s.begin(), s.end(), 'A');
		b = count(s.begin(), s.end(), 'B');
		c = count(s.begin(), s.end(), 'C');
		if(b == a+c)
			cout << "YES\n";
		else
			cout << "NO\n";
	}

	return 0;
}
