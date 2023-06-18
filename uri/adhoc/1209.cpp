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
#define TAM 1100

using namespace std;
using vi = vector<int>;
using ll = int64_t;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vii = vector<pii>;
using vll = vector<ll>;
using vbit = vector<bool>;
using vstr = vector<string>;
using vd = vector<double>;
using _graph = map<int, unordered_map<int, bool>>;
using _wgraph = unordered_map<int, unordered_map<int, int>>;

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
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  int n, m, k, currentGrau, u,v, printed, max;
  bool visited[TAM];
  int grau[TAM];
  auto net = _graph();

  while(cin >> n >> m >> k) {
    memset(visited, 0, sizeof(bool) * n);
    memset(grau, 0, sizeof(int) * n);
    
    FOR(i, n) {
      v = i+1;
      grau[v] = visited[v] = false;
      net[v] = unordered_map<int, bool>();
    }
    
    FOR(i, m) {
      cin >> u >> v; 
      net[u][v] = true;
      net[v][u] = true;

      grau[u]++;
      grau[v]++;
    }

    FOR(q, net.size()) {
      v = -1;
      max = n + 20;

      FORIT(vit, net) {
        if(visited[vit->first]) {
          continue;
        }

        currentGrau = grau[vit->first];
        if(currentGrau < max) {
          max = currentGrau;
          v = vit->first;
        }
      }

      visited[v] = true;

      if(max >= k) {
        break;
      }

      FORIT(uit, net[v]) {
        grau[uit->first]--;
      }
    }

    printed = 0;
    FOR(i, n) {
      v = i + 1;
      
      if(grau[v] < k) {
        continue;
      }

      if(printed++) {
        cout << ' ';
      }

      cout << v;
    }

    if(printed) {
      cout << '\n';
    } else {
      cout << "0\n";
    }
  }

  return 0;
}