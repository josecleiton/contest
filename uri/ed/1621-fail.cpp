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

struct maze_result {
  const int i;
  const int j;
  const int steps;
};

int solve(const vector<string> &maze, const int m) {
  const auto n = maze.size();
  auto visited = vector<bool>(n * m);
  auto q = queue<maze_result>();
  auto pq = priority_queue<int>();

  const auto check = [n, m, &maze, &visited](const int i, const int j) -> bool {
    return !visited[i * n + j] && maze[i][j] == '.';
  };

  q.push({});

  while (!q.empty()) {
    const auto &[i, j, steps] = q.front();
    visited[i * n + j] = true;

    if (i + 1 < n && check(i + 1, j)) {
      q.push({i + 1, j, steps + 1});
    }
    if (i - 1 >= 0 && check(i - 1, j)) {
      q.push({i - 1, j, steps + 1});
    }
    if (j + 1 < m && check(i, j + 1)) {
      q.push({i, j + 1, steps + 1});
    }
    if (j - 1 >= 0 && check(i, j - 1)) {
      q.push({i, j - 1, steps + 1});
    }

    pq.push(steps);
    q.pop();
  }

  return pq.top();
}

int main() {
  int n, m;

  while ((cin >> n >> m) && (n && m)) {
    auto maze = vector<string>(n);
    FOR(i, n) {
      cin >> maze[i];
      cin.ignore();
    }

    cout << solve(maze, n) << '\n';
  }
  return 0;
}
