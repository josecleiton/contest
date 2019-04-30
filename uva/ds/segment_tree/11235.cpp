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
#define TAM

using namespace std;
typedef vector<int> vi;
typedef int64_t ll;
typedef unsigned long long ull;
typedef vector<ll> vll;
typedef vector<string> vstr;
typedef vector<bool> vbit;
typedef pair<ll, ll> pii;
typedef vector<double> vd;
typedef unordered_map<int, unordered_map<int, bool>> _graph;
typedef unordered_map<int, unordered_map<int, int>> _wgraph;

/*
class Comp {
public:
    bool operator() (const type& a, const type& b) { // COMPARADOR ESTRITO PARA
PRIORITY_Q, UMAP ETC return true;
    }
}

MODULAR ARITHMETIC
( a + b) % c = ( ( a % c ) + ( b % c ) ) % c
( a * b) % c = ( ( a % c ) * ( b % c ) ) % c
( a – b) % c = ( ( a % c ) – ( b % c ) ) % c

*/
pair<ll, ll> error;

class SegmentTree {
private:
  vector<pii> st;
  vi A;
  ll n;
  ll left(ll p) { return p << 1; }
  ll right(ll p) { return (p << 1) + 1; }

  void build(ll p, ll L, ll R) { 
    if(L == R ) st[p] = mkp(L, (ll)1);
    else {
      build(left(p), L, (L+R)/2);
      build(right(p), (L+R)/2+1, R);
      auto p1 = st[left(p)], p2 = st[right(p)];
      if(p1.second > p2.second) {
      	st[p] = p1;
      } else {
      	st[p] = p2;
      }
      if(A[p1.first] == A[p2.first]) st[p].second++;
      //st[p] = (A[p1] == A[p2]) ? p1: p2;
    }
  }

  pair<ll, ll> rmfq(ll p, ll L, ll R, ll i, ll j) {
    if(i > R or j < L) return error;
    if(L >= i and R <= j)  return st[p];

    auto p1 = rmfq(left(p), L, (L+R)/2, i, j);
    auto p2 = rmfq(right(p), (L+R)/2+1, R, i, j);
    if(p1 == error) return p2;
    if(p2 == error) return p1;
    return (p1.second >= p2.second) ?  p1 : p2;
    //return (A[p1] <= A[p2]) ? p1: p2;
  }
public:
  SegmentTree(const vi& _A) {
    A = _A;
    n = A.size();
    st.assign(4*n, pair<ll, ll>());
    build(1, 0, n-1);
  }
  ll rmfq(int i, int j) { return rmfq(1, 0, n-1, i, j).second; }
};


int main() {
  //ios::sync_with_stdio(0);
  //cin.tie(0);
  int n, q, low, up;
  //char c;
  //ll n, m, l;
  //int n, m, l;
  //string s;
  error.first = error.second = -1;

  while (scanf("%d", &n) != EOF and n) {
  	scanf("%d",&q);
  	vi arr(n);
  	FOR(i, n) {
  		scanf("%d", &arr[i]);
  	}
  	SegmentTree st(arr);
  	while(q--) {
  		scanf("%d", &low, &up);
  		printf("%lld\n", st.rmfq(low, up));
  	}
  }
  return 0;
}
