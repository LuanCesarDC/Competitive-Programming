/**
 *    author:  tourist
 *    created: 24.06.2023 11:19:27       
**/
#undef _GLIBCXX_DEBUG

#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

static struct FastInput {
  static constexpr int BUF_SIZE = 1 << 20;
  char buf[BUF_SIZE];
  size_t chars_read = 0;
  size_t buf_pos = 0;
  FILE *in = stdin;
  char cur = 0;

  inline char get_char() {
    if (buf_pos >= chars_read) {
      chars_read = fread(buf, 1, BUF_SIZE, in);
      buf_pos = 0;
      buf[0] = (chars_read == 0 ? -1 : buf[0]);
    }
    return cur = buf[buf_pos++];
  }
 
  inline void tie(int) {}

  inline explicit operator bool() {
    return cur != -1;
  }

  inline static bool is_blank(char c) {
    return c <= ' ';
  }

  inline bool skip_blanks() {
    while (is_blank(cur) && cur != -1) {
      get_char();
    }
    return cur != -1;
  }
 
  inline FastInput& operator>>(char& c) {
    skip_blanks();
    c = cur;
    return *this;
  }
  
  inline FastInput& operator>>(string& s) {
    if (skip_blanks()) {
      s.clear();
      do {
        s += cur;
      } while (!is_blank(get_char()));
    }
    return *this;
  }
 
  template <typename T>
  inline FastInput& read_integer(T& n) {
    // unsafe, doesn't check that characters are actually digits
    n = 0;
    if (skip_blanks()) {
      int sign = +1;
      if (cur == '-') {
        sign = -1;
        get_char();
      }
      do {
        n += n + (n << 3) + cur - '0';
      } while (!is_blank(get_char()));
      n *= sign;
    }
    return *this;
  }

  template <typename T>
  inline typename enable_if<is_integral<T>::value, FastInput&>::type operator>>(T& n) {
    return read_integer(n);
  }
  
  #if !defined(_WIN32) || defined(_WIN64)
  inline FastInput& operator>>(__int128& n) {
    return read_integer(n);
  }
  #endif

  template <typename T>
  inline typename enable_if<is_floating_point<T>::value, FastInput&>::type operator>>(T& n) {
    // not sure if really fast, for compatibility only
    n = 0;
    if (skip_blanks()) {
      string s;
      (*this) >> s;
      sscanf(s.c_str(), "%lf", &n);
    }
    return *this;
  }
} fast_input;

#define cin fast_input

const long long inf = (long long) 1e18;

struct segtree {
  vector<long long> a;
  int n;
  segtree(int _n) : a(2 * _n, inf), n(_n) {}
  
  void modify(int pos, long long val) {
    for (a[pos += n] = val; pos > 1; pos /= 2)
      a[pos >> 1] = min(a[pos], a[pos ^ 1]);
  }
  
  long long get(int b, int e) {
    long long res = inf;
    for (b += n, e += n; b < e; b >>= 1, e >>= 1) {
      if (b & 1) res = min(res, a[b++]);
      if (e & 1) res = min(res, a[--e]);
    }
    return res;
  }
};

struct segtree_ind {
  vector<pair<long long, int>> a;
  int n;
  segtree_ind(int _n) : a(2 * _n, make_pair(-inf, -1)), n(_n) {}
  
  void modify(int pos, long long val) {
    for (a[pos += n] = make_pair(val, pos); pos > 1; pos /= 2)
      a[pos >> 1] = max(a[pos], a[pos ^ 1]);
  }
  
  pair<long long, int> get(int b, int e) {
    pair<long long, int> res = make_pair(-inf, -1);
    for (b += n, e += n; b < e; b >>= 1, e >>= 1) {
      if (b & 1) res = max(res, a[b++]);
      if (e & 1) res = max(res, a[--e]);
    }
    return res;
  }
};

template <typename T>
class MinQueue {
 public:
  vector<T> val;
  int b = 0;
  vector<int> st;
  int ptr = 0;

  void push(T t) {
    while ((int) st.size() > ptr && val[st.back()] >= t) {
      st.pop_back();
    }
    st.push_back((int) val.size());
    val.push_back(t);
  }

  void pop() {
    assert(b < (int) val.size());
    if (ptr < (int) st.size() && st[ptr] == b) {
      ptr += 1;
    }
    b += 1;
  }

  bool empty() {
    return (b == (int) val.size());
  }

  int size() {
    return (int) val.size() - b;
  }

  T get_min() {
    assert(ptr < (int) st.size());
    return val[st[ptr]];
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, k;
    cin >> n >> k;
    assert(1 <= k && k < n && n <= 500000);
    vector<int> a(n + k);
    for (int i = 0; i < n; i++) {
      cin >> a[i];                         
      assert(1 <= a[i] && a[i] <= (int) 1e9);
    }
    for (int i = n; i < n + k; i++) {
      a[i] = a[i - n];
    }
    vector<long long> dp(n + k);
    MinQueue<long long> que;
    que.push(0);
    for (int i = 1; i < n + k; i++) {
      if (i - k - 1 >= 0) {
        que.pop();
      }
      dp[i] = que.get_min() + a[i];
      que.push(dp[i]);
    }
    segtree_ind s0(n + k);
    segtree s1(n + k);
    for (int i = 1; i < n + k; i++) {
      s0.modify(i, dp[i] - a[i]);
      s1.modify(i, dp[i]);
    }
    long long ans = inf;
    long long Q = 0;
    priority_queue<int, vector<int>, greater<int>> s;
    for (int pos = 0; pos < k; pos++) {
      if (pos > 0) {
        dp[pos] = 0;
        s1.modify(pos, 0);
        s.push(pos + k);
        while (!s.empty()) {
          int i = s.top();
          s.pop();
          dp[i] = s1.get(i - k, i) + a[i];
          s0.modify(i, dp[i] - a[i]);
          s1.modify(i, dp[i]);
          if (i == n + k - 1) {
            break;
          }
          while (true) {
            auto got = s0.get(i + 1, min(n + k, i + k + 1));
            if (got.first > dp[i]) {
              int j = got.second;
              s.push(j);
              s0.modify(j, -inf);
              Q += 1;
            } else {
              break;
            }
          }
        }
        if (Q > n * 10) {
          break;
        }
      }
      ans = min(ans, dp[pos + n]);
    }
    debug(Q);
    cout << ans << '\n';
  }
  return 0;
}
