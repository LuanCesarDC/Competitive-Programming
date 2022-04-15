#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t; cin >> t;
	while(t--) {
		int n, m, k; cin >> n >> m >> k;
		int mat[n][m];
		
		for(int i=0;i<n;i++) {
			for(int j=0;j<m;j++) {
				char aux; cin >> aux;
				if(aux == '.')
					mat[i][j] = 0;
				else
					mat[i][j] = 1;
			}
		}
		
		for(int i=n-1;i>=0;i--) {
			for(int j=m-1;j>=0;j--) {
				if(j < k || m-j-1 < k)
					continue;	
				
			}
		}
	
	}
	
	return 0;
}
