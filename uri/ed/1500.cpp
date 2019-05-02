// TEMPLATE COM MACROS PARA OS CONTESTS
// compile usando: g++ -std=c++11 -lm -O3 arquivo.cpp
#include <bits/stdc++.h>
#define SET(a, b) cout.precision(a); cout << fixed << b << endl
#define PCS(a) cout.precision(a)
#define FX(a) fixed << a
#define FOR(i, a) for (int i = 0; i < a; i++)
#define PARA(i, k, n) for (int i = k; i < n; i++)
#define ROF(i, a) for (int i = a - 1; i >= 0; i--)
#define FORIT(it, c) for (auto it = c.begin(); it != c.end(); it++)
#define pb emplace_back
#define pf emplace_front
#define pob pop_back
#define pof pop_front
#define MAP(t1, t2, ord) map<t1, t2, ord<t1>>
#define UMAP(t1, t2) unordered_map<t1, t2>
#define MATRIX(name, type, n, m) vector<vector<type>> name(n, vector<type>(m))
#define PQ( type, ord) priority_queue<type, deque<type>, ord<type>>
#define mkp(a, b) make_pair(a, b)
#define TAM 100010

using namespace std;
typedef vector<int> vi;
typedef int64_t ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vii;
typedef vector<ll> vll;
typedef vector<bool> vbit;
typedef vector<string> vstr;
typedef vector<double> vd;
typedef unordered_map<int, unordered_map<int, bool>> _graph;
typedef unordered_map<int, unordered_map<int, int>> _wgraph;

constexpr ll combine(ll left_val, ll right_val) { 
  return left_val + right_val;
}
constexpr int left(int p) { return p << 1; }
constexpr int right(int p) { return (p << 1) | 1; }

class SegmentTree {
private:
  vll st, lazy;
  long long n;
  void build(int p, int L, int R) { 
    st[p] = lazy[p] = 0LL;
    if(L == R){
      return;
    }
    int mid = (L+R)>>1;
    build(left(p), L, mid);
    build(right(p), mid+1, R);
  }

  void propagate(int p, int L, int R) {
    st[p] += (R-L+1)*lazy[p];
    if(L != R) {
      lazy[left(p)] += lazy[p];
      lazy[right(p)] += lazy[p];
    }
    lazy[p] = 0LL;
  }

  void update(int p, int L, int R, int startRange, int endRange, const ll& val) {
    if(lazy[p]) propagate(p, L, R);
	  if(startRange > R or endRange < L) return; // não há sobreposição
	  if(startRange <= L and endRange >= R) { // sobreposição total
    	st[p] += (R-L+1)*val;
      if(L != R) {
        lazy[left(p)] += val;
        lazy[right(p)] += val;
      }
	  } else {
    	int mid = (L+R)>>1;
    	update(left(p), L, mid, startRange, endRange, val);
    	update(right(p), mid+1, R, startRange, endRange, val);
    	st[p] = combine(st[left(p)], st[right(p)]);
    }
  }

  ll query(int p, int L, int R, int i, int j) {
    if(lazy[p]) propagate(p, L, R);
    if(i > R or j < L) return 0;
    if(i <= L and j >= R)  return st[p];
    int mid = (L+R)>>1;
    auto left_val = query(left(p), L, mid, i, j);
    auto right_val = query(right(p), mid+1, R, i, j);
    if(!left_val) return right_val;
    if(!right_val) return left_val;
    return combine(left_val, right_val);
  }

public:
  SegmentTree() {
  	lazy.resize(TAM<<2);
  	st.resize(TAM<<2);
  }
  void reset(const int& _n) {
    n = _n;
    build(1, 0, n-1);
  }
  ll query(int i, int j) { return query(1, 0, n-1, i, j); }
  void update(int i, int j, ll val) { return update(1, 0, n-1, i, j, val); }
};

int main() {
  int ct,n,c,op,p,q,v;
  SegmentTree st;
  scanf("%d", &ct);
  while(ct--) {
    scanf("%d%d", &n,&c);
    st.reset(n);
    while(c--) {
      scanf("%d", &op);
      if(op) {
        scanf("%d%d", &p,&q);
        printf("%lld\n", st.query(p-1, q-1));
      } else {
        scanf("%d%d%d", &p, &q, &v);
        st.update(p-1, q-1, v);
      }
    }
  }
  return 0;
}
