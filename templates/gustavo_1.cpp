#include<bits/stdc++.h>
using namespace std;

#pragma region

#define all(x) x.begin(), x.end()
#define lef(x) (x<<1)
#define rig(x) (lef(x)|1)
#define ft first
#define sd second
#define mt make_tuple
#define mp make_pair
#define eb emplace_back
#define pb push_back


#define rep(i, begin, end) for(__typeof(begin) i = (begin) - ((begin)> (end)); i!= (end) -((begin) > (end)); i+=1-2*((begin)>(end)))
// #define rep(i, begin, end) for(int i = begin; i<end; i++)

typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int, int> pii;
typedef pair<double, double> pdb;


template<typename T>
ostream& operator<<(ostream &os, pair<T, T> p){
    os << "(" << p.ft << ", " << p.sd << ")";
    return os;
}
template<typename T>
istream& operator>>(istream &is, pair<T, T> p){
    is >> p.ft >> p.sd;
    return is;
}

#define error(args...) {string _s =#args; replace(_s.begin(), _s.end(), ',', ' '); stringstream __ss(_s); err(_it, args);}

void err(istream_iterator<string> it){}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args){
    cerr << *it << " = " << a << endl;
    err(++it, args...);
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#pragma endregion

const ll mod = 998244353LL;

const int N = 5100;

ll inv(ll x)
{
    ll b = mod-2, rs = 1;
    while(b)
    {
        if(b&1)
            rs = rs*x%mod;
        x = x*x%mod;
        b >>= 1;
    }
    return rs;
}


ll tot[N];
int dp[N][N][2];
ll fat[N], ifat[N];
short vis[N][N][2], cs = 1;
int n, last;
int solve(int pos, int qt, int did)
{
    if(pos == last){
        // cout << qt << "<<\n";
        return qt == 0 && did == 1;
    }
    int &ans = dp[pos][qt][did];
    if(vis[pos][qt][did] == cs)
        return ans;
    vis[pos][qt][did] = cs;
    ans = solve(pos+1, qt + tot[pos], did)*ifat[tot[pos]]%mod;
    if(did)
    {
        if(tot[pos] >= 1 && qt >= 1)
        {
            ll at = qt;
            at = at*solve(pos+1, qt + tot[pos]-2, did)%mod;
            at = at*ifat[tot[pos]-1]%mod;
            ans = (ans+at)%mod;
        }
    }else
    {
        ll at = qt+tot[pos];
        if(tot[pos] >= 1)
        {
            at = solve(pos+1, at-1, 1)*ifat[tot[pos]-1]%mod;
            ans = (ans+at)%mod;
        }
    }
    return ans;
}


void test(){
    cin >> n;
    rep(i, 0, n+1)
        tot[i] = 0;
    int ini = n;
    last = 0;
    rep(i, 0, n)
    {
        int x;
        cin >> x;
        last = max(last, x);
        ini = min(ini, x);
        tot[x]++;
    } 
    if(tot[last] != 1)
    {
        cout << "0\n";
        return;
    }
    // cout << ini << '\n';
    cs++;
    cout << solve(ini, 0, 0) << '\n';
}

int main(){
    fat[0] = ifat[0] = 1;
    rep(i, 1LL, N)
    {
        fat[i] = fat[i-1]*i%mod;
        ifat[i] = inv(fat[i]);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;


    cin >> t;
    while(t--){
        test();
    }
    
}