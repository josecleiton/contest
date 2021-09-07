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

vector<int> dijkstra(const vector<vector<pii>> &graph, const int src) {
  auto pq = priority_queue<pii, vector<pii>, greater<pii>>();
  auto dist = vector<int>(graph.size(), INT_MAX);
  pq.push({0, src});
  dist[src] = 0;

  auto result = INT_MIN;

  while (!pq.empty()) {
    auto u = pq.top().second;
    pq.pop();

    for (const auto &[v, weight] : graph[u]) {
      if (dist[v] > dist[u] + weight) {
        dist[v] = dist[u] + weight;
        pq.push({dist[v], v});

        if (result < dist[v]) {
          result = dist[v];
        }
      }
    }
  }

  return dist;
}

int main() {
  int n, m;

  while ((cin >> n >> m) && (n + m)) {
    auto graph = vector<vector<pii>>(m * m + 2, vector<pii>());
    auto maze = vector<string>(n);
    FOR(i, n) {
      cin >> maze[i];
      cin.ignore();
    }

    FOR(i, n) {
      FOR(j, m) {
        if (maze[i][j] != '.') {
          continue;
        }

        const auto node_index = n * i + j;

        if (const auto il = i - 1; il >= 0 and maze[il][j] == '.') {
          graph[node_index].pb(make_pair(il * n + j, 1));
        }

        if (const auto il = i + 1; il < n and maze[il][j] == '.') {
          graph[node_index].pb(make_pair(il * n + j, 1));
        }

        if (const auto jl = j - 1; jl >= 0 and maze[i][jl] == '.') {
          graph[node_index].pb(make_pair(i * n + jl, 1));
        }

        if (const auto jl = j + 1; jl < m and maze[i][jl] == '.') {
          graph[node_index].pb(make_pair(i * n + jl, 1));
        }
      }
    }

    int start;
    for (start = 0; start < graph.size(); start++) {
      if (graph[start].size())
        break;
    }

    auto dist = dijkstra(graph, start);

    int max = INT_MIN;
    for (size_t i = 0; i < dist.size(); i++) {
      if (dist[i] != INT_MAX and dist[i] > max) {
        max = dist[i], start = i;
      }
    }

    dist = dijkstra(graph, start);
    max = INT_MIN;
    for (size_t i = 0; i < dist.size(); i++) {
      if (dist[i] != INT_MAX and dist[i] > max) {
        max = dist[i];
      }
    }
    cout << max << '\n';
  }
  return 0;
}
