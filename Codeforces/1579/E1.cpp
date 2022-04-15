#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		int aux;
		deque <int> d;
		
		cin >> aux;
		d.push_front(aux);
		for(int i=1;i<n;i++) {
			cin >> aux;
			if(aux < d.front())
				d.push_front(aux);
			else
				d.push_back(aux);
		}
		while(!d.empty()) {
			cout << d.front() << " ";
			d.pop_front();
		}
		cout << "\n";
	}
	
	return 0;
}
