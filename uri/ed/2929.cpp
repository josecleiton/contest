// TEMPLATE COM MACROS PARA OS CONTESTS
// compile usando: g++ -std=c++11 -lm -O3 arquivo.cpp
#include <bits/stdc++.h>
#define SET(a, b)                                                              \
  cout.precision(a);                                                           \
  cout << fixed << b << endl
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
#define PQ(type, ord) priority_queue<type, deque<type>, ord<type>>
#define mkp(a, b) make_pair(a, b)
#define TAM

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

int main() {
  // ios::sync_with_stdio(0);
  // cin.tie(0);
  int ct;
  // char c;
  ll n, v;
  // int n, m, l;
  string str;

  cin >> n;
  auto bst = map<ll, bool>();
  auto umap = unordered_map<ll, ll>();
  auto s = stack<ll>();
  FOR(i, n) {
    cin >> str;

    if (str == "PUSH") {
      cin >> v;
      s.emplace(v);
      bst.insert({s.top(), true});
      umap[s.top()]++;
      continue;
    }

    if (str == "MIN") {
      if (!s.empty()) {
        cout << bst.begin()->first << '\n';
      } else {
        cout << "EMPTY\n";
      }
      continue;
    }

    if (str == "POP") {
      if (!s.empty()) {
        if (umap[s.top()] <= 1) {
          umap.erase(s.top());
          bst.erase(s.top());
        } else {
          umap[s.top()]--;
        }
        s.pop();
      } else {
        cout << "EMPTY\n";
      }
      continue;
    }
  }
  return 0;
}
