#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> adj[n+1], altura(n+1);
    vector<bool> visited(n+1, false);
    queue<int> st;
    int height = 0;
    for(int i=0;i<n-1;i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    st.push(1);
    cout << "1 0\n";
    while(!st.empty()) {
        int s = st.front();
        st.pop();
        height++;
        
        if(!visited[s]) {
            visited[s] = true;
        }

        for(int i=0;i<adj[s].size();i++) {
            if(!visited[adj[s][i]]) {
                if(adj[adj[s][i]].size() == 0) {
                    cout << "FOLHA: ";
                }
                cout << adj[s][i] << " " << height << "\n";
                st.push(adj[s][i]);
            }
        }
    }
    cout << "\n";

    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}