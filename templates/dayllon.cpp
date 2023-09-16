#include <bits/stdc++.h>
using namespace std;

//template
#pragma region
//#include <ext/pb_ds/assoc_container.hpp> // Common file
//#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
//using namespace __gnu_pbds;
// #pragma GCC optimize("O3", "unroll-loops") // for fast N^2
// #pragma GCC target("avx2", "popcnt") // for fast popcount
// some macros
#define all(x) x.begin(), x.end()
#define lef(x) (x<<1)
#define rig(x) (lef(x)|1)
#define ft first
#define sd second
#define mt make_tuple
#define mp make_pair
#define eb emplace_back
#define pb push_back
// loop that goes (begin,..,end]
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
 
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef pair<double,double> pdb;

// template<class T> using ordset = tree<
// T,
// null_type,
// less<T>,
// rb_tree_tag,
// tree_order_statistics_node_update>;
//read and print pair
template<typename T>
ostream& operator<<(ostream& os, pair<T, T> p) {
    os << "(" << p.first << ", " << p.second << ")";
    return os;
}
template<typename T>
istream& operator>>(istream& is, pair<T, T> &p) {
    is >> p.first >> p.second;
    return is;
}
 
//error debug
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
 
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
    cerr << *it << " = " << a << endl;
    err(++it, args...);
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#pragma endregion

const int K = 26;

struct Vertex {
    int next[K];
    bool output = false;
    int p = -1;
    char pch;
    int link = -1;
    int exitLink = -1;
    int go[K];
    int k = -1;
    int ans = -1;
    int length;
    set<int> pos;

    Vertex(int p=-1, char ch='$') : p(p), pch(ch) {
        fill(begin(next), end(next), -1);
        fill(begin(go), end(go), -1);
    }
};

vector<Vertex> t(1);

int add_string(string const& s, int k) {
    int v = 0;
    for (char ch : s) {
        int c = ch - 'a';
        if (t[v].next[c] == -1) {
            t[v].next[c] = t.size();
            t.emplace_back(v, ch);
        }
        v = t[v].next[c];
    }
    t[v].output = true;
    t[v].k = k;
    t[v].length = s.size();
    return v;
}

int go(int v, char ch);

int get_link(int v) {
    if (t[v].link == -1) {
        if (v == 0 || t[v].p == 0)
            t[v].link = 0;
        else
            t[v].link = go(get_link(t[v].p), t[v].pch);
    }
    return t[v].link;
}

int go(int v, char ch) {
    int c = ch - 'a';
    if (t[v].go[c] == -1) {
        if (t[v].next[c] != -1)
            t[v].go[c] = t[v].next[c];
        else
            t[v].go[c] = v == 0 ? 0 : go(get_link(v), ch);
    }
    return t[v].go[c];
} 

int exitLink(int u){
    if(u == 0 || get_link(u) == 0)
        return 0;
    if (t[u].exitLink == -1)
        t[u].exitLink = t[get_link(u)].output ? get_link(u) : exitLink(get_link(u));
    return t[u].exitLink;
}

void dfs(int curr){
    rep(i, 0, (int)K){
        if (t[curr].next[i] != -1){
            dfs(t[curr].next[i]);
        }
    }
    int minAns = 1e9, aux;
    if (t[curr].output){
        //cout << curr << " --- " << t[curr].pos.size() << " " << t[curr].k << endl;
        //cout << "\t\t-->";
        //for(int x : t[curr].pos) cout << x << " "; cout << endl;
        if (t[curr].pos.size() >= t[curr].k){
            queue<int> Q;
            auto it = t[curr].pos.begin();
            rep(i, 0, t[curr].k-1){
                Q.push(*it);
                it++;
            }
            for (; it != t[curr].pos.end(); it++){
                Q.push(*it);
                minAns = min(minAns, (*it) - Q.front());
                Q.pop();
            }
        }

        if (minAns == 1e9) t[curr].ans = -1;
        else t[curr].ans = minAns + t[curr].length;

        if (exitLink(curr) != -1){
            int pai = exitLink(curr);
            if (t[pai].pos.size() < t[curr].pos.size())
                swap(t[pai].pos, t[curr].pos);
            for (int x : t[curr].pos)
                t[pai].pos.insert(x);
        }
    }
}

void test(){
    string s, s2;
    vector<pii> ansIds;
    vector<pair<pii, pair<int, string>>> vet;
    int m, k;
    cin >> s;
    cin >> m;
    rep(i, 0, m){
        cin >> k >> s2;
        vet.pb({{s2.size(), i}, {k, s2}});
    }
    sort(all(vet));
    
    rep(i, 0, vet.size())
        ansIds.pb({vet[i].ft.sd, add_string(vet[i].sd.sd, vet[i].sd.ft)});

    sort(all(ansIds));
    int curr = 0;
    rep(i, 0, s.size()){
        curr = go(curr, s[i]);
        if (t[curr].output){
            t[curr].pos.insert(i);
        }
    }

    dfs(0);

    for (auto [idx, id] : ansIds){
        cout << t[id].ans << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    //cin >> t;
    while(t--){
        test();
    }
    return 0;
}
