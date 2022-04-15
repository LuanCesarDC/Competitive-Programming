#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t; cin >> t;
	
	while(t--) {
		int n; cin >> n;
		int num = 0;
		vector <int> v(n);
		vector <string> s;
		
		for(int &x:v) {
			cin >> x;
		}
		for(int i=0;i<n;i++) {
			int l = max_element(v.begin(), v.end()) - v.begin() + 1;
			int r = n-i;
			int d = 1;
			
			if(l!=r) {
				char aux[100];
				sprintf(aux, "%d %d 1\n", l, r);
				s.push_back(aux);
				num++;
			}
			
			v.erase(v.begin()+l-1);
			
		}
		cout << num << "\n";
		for(string st:s)
			cout << st;

	}
	
	return 0;
}
