// TEMPLATE COM MACROS PARA OS CONTESTS
// compile usando: g++ -std=c++11 -lm -O3 arquivo.cpp
#include <bits/stdc++.h>
#define set(a, b) cout.precision(a); cout << fixed << b << endl
#define pcs(a) cout.precision(a)
#define fx(a) fixed << a
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
#define matrix(name, type, n, m) vector<vector<type>> name(n, vector<type>(m))
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

class UnionFind {
private:
  vi p, rank;
public:
  void reset(int N) {
    rank.assign(2*N, 0);
    p.resize(2*N);
    FOR(i, 2*N) p[i] = i;
  }
  int findSet(int i) {
    if(p[i] == i) {
      return i;
    } else {
      p[i] = findSet(p[i]);
      return p[i];
    }
    // return (p[i] == i) ? i : (p[i] = findSet(p[i]));
  }
  bool isSameSet(int i, int j) {
    return findSet(i) == findSet(j);
  }
  void unionSet(int i, int j) {
    if(!isSameSet(i, j)) {
      int x = findSet(i) , y = findSet(j);
      if(rank[x] > rank[y]) p[y] = x;
      else {
        p[x] = y;
        if(rank[x] == rank[y]) rank[y]++;
      }
    }
  }

};

int main() {
  //ios::sync_with_stdio(0);
  //cin.tie(0);
  int ct,n,a,b,suc,unsuc;
  //char c;
  //ll n, m, l;
  //int n, m, l;
  //string s;
  char input[80];
  char op;

  UnionFind ufds;
  scanf("%d", &ct);
  FOR(t, ct) {
    suc = unsuc = 0;
    if(t) putchar('\n');
    scanf("%d%*c", &n);
    ufds.reset(n);
    while(scanf("%c", &op) != EOF and op!='\n') {
      scanf("%d%d%*c", &a, &b);
      if(op == 'c') {
        ufds.unionSet(a, b);

      } else {
        ufds.isSameSet(a,b) ? suc++ : unsuc++;
      }
    }
    printf("%d,%d\n", suc, unsuc);

  }
  return 0;
}
