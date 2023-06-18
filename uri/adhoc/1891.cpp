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
  int ct;
  char c;
  ll n;
  int result[100005];

  map<int,bool> canflip;
  unordered_map<int, bool> cannotflip;

  scanf("%d", &ct);

  FOR(k, ct) {
    int result_idx = 0;
    canflip.clear();
    cannotflip.clear();

    scanf("%ld", &n);

    getc(stdin);

    FOR(i, n) {
      c = getc(stdin);

      if(c == 'D') {
        canflip.insert({i, true});
      } else {
        cannotflip.insert({i, true});
      }
    }

    if(canflip.empty()) {
      puts("N");
      continue;
    }

    while(canflip.size()) {
      const auto& iit = canflip.begin(); // 1
      const auto i = iit->first;
      const auto& jit = canflip.find(i+1); // logn
      const auto& kit = canflip.find(i-1); // logn

      if(jit != canflip.end()) { // 1
        canflip.erase(jit); // 1 amortized
        cannotflip.insert({i+1, true}); // 1 amortized
      } else if(const auto& xit = cannotflip.find(i+1); xit != cannotflip.end()) { // 1 amortized
        canflip.insert({i+1, true}); // logn
        cannotflip.erase(xit); // 1 amortized
      }

      if(kit != canflip.end()) { // 1
        canflip.erase(kit); // 1
        cannotflip.insert({i-1, true}); // 1 amortized
      } else if(const auto& xit = cannotflip.find(i-1); xit != cannotflip.end()) { // 1 amortized
        canflip.insert({i-1, true}); // logn
        cannotflip.erase(xit); // 1 amortized
      }

      result[result_idx++] = i; // 1

      canflip.erase(iit); // 1 amortized
    }  // O(n(4logn+7))

    if(canflip.size() + cannotflip.size()) {
      puts("N");
      continue;
    }

    puts("Y");
    printf("%d", result[0] +1);
    PARA(i, 1, result_idx) {
      printf(" %d", result[i] + 1);
    }
    putchar('\n');
  }
  return 0;
}