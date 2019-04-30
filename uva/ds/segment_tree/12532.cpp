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

constexpr int left(int p) { return p << 1; }
constexpr int right(int p) { return (p << 1) + 1; }

constexpr int combine(int left_val, int right_val) {
  return left_val * right_val;
}

class SegmentTree {
private:
  vector<int> st, A;
  int n;


  void build(int p, int L, int R) { 
    if(L == R ) st[p] = (A[L] > 0) - (A[L] < 0);
    else {
      int mid = (L+R)/2;
      build(left(p), L, mid);
      build(right(p), mid+1, R);
      int left_val = st[left(p)];
      int right_val = st[right(p)];
      st[p] = combine(left_val, right_val);
    }
  }
  void update(int p, int L, int R, int i, int v) {
    if(i < L or i > R) return;
    if(L == R) {
      st[p] = (v > 0) - (v < 0);
      return;
    }
    int mid = (L+R)/2;
    update(left(p), L, mid, i, v);
    update(right(p), mid+1, R, i, v);
    int left_val = st[left(p)];
    int right_val = st[right(p)];
    st[p] = combine(left_val, right_val);
  }

  int rpq(int p, int L, int R, int i, int j) {
    if(i > R or j < L) return 1;
    if(L >= i and R <= j)  return st[p];
    int mid = (L+R)/2;
    int left_val = rpq(left(p), L, mid, i, j);
    int right_val = rpq(right(p), mid+1, R, i, j);
    return combine(left_val, right_val);
  }
public:
  SegmentTree(const vector<int>& _A) {
    A = _A;
    n = A.size();
    st.assign(4*n, 0);
    build(1, 0, n-1);
  }
  int rpq(int i, int j) { return rpq(1, 0, n-1, i-1, j-1); }
  void update(int i, int v) {
    A[i-1] = v;
    update(1, 0, n-1, i-1, v);
  }
};

int main() {
  //ios::sync_with_stdio(0);
  //cin.tie(0);
  int n, q;
  //char c;
  //int n, m, l;
  //int n, m, l;
  //string s;
  int i, v;
  int qans;
  char c;
  char useless[80];
  int k;
  while (scanf("%d%d", &n, &q) != EOF) {
    vector<int> in(n);
    FOR(i, n) {
      scanf("%d", &in[i]);
    }
    fgets(useless, 80, stdin);
    SegmentTree st(in);
    k=0;
    while(q--) {
      scanf("%c%d%d%*c", &c, &i, &v);
      if(c=='C') {
        st.update(i, v);
      } else {
        qans = st.rpq(i, v);
        k++;
        printf("%d", (qans > 0 ? '+' : (qans ? '-' : '0')));
      }
    }
    putchar('\n');
  }
  return 0;
}
