#include "bits/stdc++.h"
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;
 
typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;
 
typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;

template<class T> using pq = priority_queue<T>;
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
 
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define trav(a,x) for (auto& a : x)
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)
 
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ", "; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? ", " : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifdef DEBUG
#define dbg(x...) cerr << "\e[91m"<<__func__<<":"<<__LINE__<<" [" << #x << "] = ["; _print(x); cerr << "\e[39m" << endl;
#else
#define dbg(x...)
#endif


const int MOD = 998244353;
const char nl = '\n';
const int MX = 210; 

struct mi {
	ll v; explicit operator ll() const { return v; }
	mi() { v = 0; }
	mi(ll _v) { 
		v = (-MOD < _v && _v < MOD) ? _v : _v % MOD;
		if (v < 0) v += MOD;
	}
	friend bool operator==(const mi& a, const mi& b) { 
		return a.v == b.v; }
	friend bool operator!=(const mi& a, const mi& b) { 
		return !(a == b); }
	friend bool operator<(const mi& a, const mi& b) { 
		return a.v < b.v; }
   
	mi& operator+=(const mi& m) { 
		if ((v += m.v) >= MOD) v -= MOD; 
		return *this; }
	mi& operator-=(const mi& m) { 
		if ((v -= m.v) < 0) v += MOD; 
		return *this; }
	mi& operator*=(const mi& m) { 
		v = v*m.v%MOD; return *this; }
	mi& operator/=(const mi& m) { return (*this) *= inv(m); }
	friend mi pow(mi a, ll p) {
		mi ans = 1; assert(p >= 0);
		for (; p; p /= 2, a *= a) if (p&1) ans *= a;
		return ans;
	}
	friend mi inv(const mi& a) { assert(a.v != 0); 
		return pow(a,MOD-2); }
		
	mi operator-() const { return mi(-v); }
	mi& operator++() { return *this += 1; }
	mi& operator--() { return *this -= 1; }
    mi operator++(int) { v++; if (v == MOD) v = 0; return mi(v); }
    mi operator--(int) { v--; if (v < 0) v = MOD-1; return mi(v); }
	friend mi operator+(mi a, const mi& b) { return a += b; }
	friend mi operator-(mi a, const mi& b) { return a -= b; }
	friend mi operator*(mi a, const mi& b) { return a *= b; }
	friend mi operator/(mi a, const mi& b) { return a /= b; }
    friend ostream& operator<<(ostream& os, const mi& m) {
        os << m.v; return os;
    }
    friend istream& operator>>(istream& is, mi& m) {
        ll x; is >> x;
        m.v = x;
        return is;
    }
};


typedef vector<mi> vmi;
typedef pair<mi,mi> pmi;
typedef vector<pmi> vpmi;

void __print(mi X) {
    cout << X.v;
}
int N;
string S;

const int V = 350;
mi dp[MX][700][4][4][4];
mi ans[3];

int nv[4][2], np[4][2];

void go(int m) {
    F0R(i, N+1) F0R(j, 700) F0R(a, 4) F0R(b, 4) F0R(c, 4) dp[i][j][a][b][c] = 0;
    dp[0][V][0][0][0] = 1;
    F0R(i, N) {
        F0R(j, 700) {
            F0R(a, 4) {
                F0R(b, 4) {
                    F0R(c, 4) {
                        if (dp[i][j][a][b][c].v == 0) continue;
                        F0R(v, 2) {
                            if (v == 0 && S[i] == 'b') continue;
                            if (v == 1 && S[i] == 'a') continue;
                            int nvv = j + (m&1?nv[a][v]:0) + (m&2?nv[b][v]:0) + (m&4?nv[c][v]:0);
                            int na = np[a][v];
                            int nb = (i>0?np[b][v]:0);
                            int nc = (i > 1 ? np[c][v] : 0);
                            /*if (S == "ab" && m == 1 && i == 0 && j == V && a == 0 && b == 0 && c == 0) {
                                dbg(nvv, na, nb, nc);
                            }*/
                            dp[i+1][nvv][na][nb][nc] += dp[i][j][a][b][c];
                        }
                    }
                }
            }
        }
    }

    F0R(a, 4) {
        F0R(b, 4) {
            F0R(c, 4) {
                array<int, 3> nxtC;
                array<int, 3> p = {a, b, c};
                int curAdd = 0;
                F0R(i, 3) {
                    int nxt = N;
                    while (p[i] != 0) {
                        if (m & (1 << i)) {
                            curAdd += nv[p[i]][S[nxt%N] == 'a'?0:1];
                        }
                        p[i] = np[p[i]][S[nxt%N] == 'a'?0:1];
                        nxt++;
                    }
                    nxtC[i] = nxt%N;
                }

                bool used[3]; F0R(i, 3) used[i] = false;
                vi cyc;
                cyc.pb(0);
                while (!used[cyc.back()]) {
                    used[cyc.back()] = true;
                    cyc.pb(nxtC[cyc.back()]);
                }
                int cm = 0;
                F0Rd(i, sz(cyc) - 1) {
                    cm |= 1<<cyc[i];
                    if (cyc[i] == cyc.back()) break;
                }
                if (cm != m) continue;
                F0R(i, 700) {
                    int ty = 1;
                    if (i + curAdd > V) ty = 0;
                    if (i + curAdd < V) ty = 2;
                    ans[ty] += dp[N][i][a][b][c];
                    /*if (dp[N][i][a][b][c].v != 0) {
                        dbg(S, m, i, a, b, c, dp[N][i][a][b][c].v);
                        dbg(cyc);
                    }*/
                }
            }
        }
    }

}

void solve() {
    F0R(i, 4) {
        nv[i][0] = 0; nv[i][1] = 0;
        if (i & 1) {
            nv[i][0] = 1;
        } 
        if (i & 2) {
            nv[i][1] = -1;
        }
        F0R(j, 2) {
            if (i & (1 << j)) {
                np[i][j] = 0;
            } else np[i][j] = i|(1<<j);
        }
    }

    vector<string> ops(1);
    cin >> ops[0];
    N = sz(ops[0]);
    F0R(i, min(2, N)) {
        if (ops[0][i] == '?') {
            vector<string> nxt;
            trav(a, ops) {
                string s1 = a, s2 = a;
                s1[i] = 'a';
                s2[i] = 'b';
                nxt.pb(s1); nxt.pb(s2);
            }
            ops = nxt;
        }
    }

    trav(a, ops) {
        S = a;
        FOR(i, 1, 8) {
            go(i);
        }
    }
    F0R(i, 3) {
        cout << ans[i] << nl;
    }
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int T = 1;
//    cin >> T;
    while(T--) {
        solve();
    }

	return 0;
}


