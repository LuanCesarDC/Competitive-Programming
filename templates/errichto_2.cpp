#include <bits/stdc++.h>
using namespace std;
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
	*this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
// debug & operator << (debug & dd, P p) { dd << "(" << p.x << ", " << p.y << ")"; return dd; }

const int NAX = 3e5 + 5;
const int MOD = 998244353;
vector<int> edges[NAX];
int subtree[NAX];
int parent[NAX];
int k;
#define distance distance_compile
int distance;

void dfs(int a, int par) {
	parent[a] = par;
	for (int b : edges[a]) {
		if (b != par) {
			dfs(b, a);
			subtree[a] += subtree[b];
		}
	}
	distance = (distance + (long long) subtree[a] * (k - subtree[a])) % MOD;
}

void print(int a) {
	for (int i = 0; i <= 50; i++) {
		for (int j = 1; j <= 50; j++) {
			if (i == (long long) a * j % MOD) {
				cerr << (double) i / j << " ";
				return;
			}
		}
	}
	assert(false);
}

int my_pow(int a, int b) {
	int r = 1;
	while (b) {
		if (b % 2) {
			r = (long long) r * a % MOD;
		}
		a = (long long) a * a % MOD;
		b /= 2;
	}
	return r;
}
int my_inv(int a) {
	return my_pow(a, MOD - 2);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n >> k;
	vector<int> p(n+1);
	
	for (int i = 0; i < k; i++) {
		int x;
		cin >> x;
		p[x] = 1;
		subtree[x] = 1;
	}
	vector<pair<int,int>> order;
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		edges[a].push_back(b);
		edges[b].push_back(a);
		order.emplace_back(a, b);
	}
	dfs(1, -1);
	// debug() << imie(distance);
	for (auto &[a,b] : order) {
		int pa = p[a];
		int pb = p[b];
		// p[a] = p[b] = 0;
		for (int rep = 0; rep < 2; rep++) {
			// a -> b
			int tmp = (long long) pa * (MOD + 1 - pb) % MOD;
			tmp = ((long long) tmp * (MOD + 1) / 2) % MOD;
			
			int diff = 0;
			if (parent[b] == a) {
				// a is parent of b
				diff = (k - subtree[b] - 1) - subtree[b];
			}
			else {
				diff = (subtree[a]-1) - (k - subtree[a]);
			}
			diff = (diff + MOD) % MOD;
			debug() << imie(diff) imie(tmp);
			distance = (distance + (long long) diff * tmp) % MOD;
			
			p[b] = (p[b] + tmp) % MOD;
			p[a] = (p[a] - tmp + MOD) % MOD;
			swap(a, b);
			swap(pa, pb);
		}
	}
	// debug() << imie(p);
	// cout << distance << "\n";
	// print(distance);
	int ways = (long long) k * (k - 1) % MOD * ((MOD + 1) / 2) % MOD;
	int answer = (long long) distance * my_inv(ways) % MOD;
	// print(answer);
	cout << answer << "\n";
}
