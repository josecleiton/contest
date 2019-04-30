// TEMPLATE COM MACROS PARA OS CONTESTS
// compile usando: g++ -std=c++11 -lm -O3 arquivo.cpp
#include <bits/stdc++.h>
#define FORM(x, y)                                                             \
    for (int i = 0; i < x; i++)                                                  \
    for (int j = 0; j < y; j++)
#define set(a, b)                                                              \
  cout.precision(a);                                                           \
  cout << fixed << b << endl
#define pcs(a) cout.precision(a)
#define fx(a) fixed << a
#define FOR(i, a) for (int i = 0; i < a; i++)
#define PARA(i, k, n) for (int i = k; i < n; i++)
#define PARAR(i, k, n) for (int i = n - 1; i >= k; i--)
#define FORIT(it, c) for (auto it = c.begin(); it != c.end(); it++)
#define pb emplace_back
#define pf emplace_front
#define MAP(t1, t2, ord) map<t1, t2, ord<t1>>
#define UMAP(t1, t2) unordered_map<t1, t2>
#define matrix(name, type, n, m) vector<vector<type>> name(n, vector<type>(m))
#define PQ(name, type, ord) priority_queue<type, deque<type>, ord<type>> name
#define ROF(i, a) for (int i = a - 1; i >= 0; i--)
#define mkp(a, b) make_pair(a, b)
using namespace std;
typedef vector<int> vi;
typedef int64_t ll;
typedef unsigned long long ull;
typedef vector<ll> vll;
typedef vector<string> vstr;
typedef vector<bool> vbit;
typedef pair<ll, ll> pii;
typedef vector<double> vd;
typedef pair<int, char> car;

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
  /*
ios::sync_with_stdio(0);
cin.tie(0);
*/
  int ct;
  char s[80];
  int capacity, n, k, ans;
  bool l;
  car tmp;

  while (scanf("%d", &ct) != EOF) {
    while (ct--) {
      queue<car> left, right;
      deque<car> ferry;
      scanf("%d%d", &capacity, &n);
      capacity *= 100;
      l = 1;
      while (n--) {
        scanf("%d%s", &k, s);
        if (!strcmp(s, "left")) {
          left.push(mkp(k, 'l'));
          if (!l) {
            right.push(mkp(0, 0));
            l = 1;
          }
        } else {
          right.push(mkp(k, 'r'));
          if (l) {
            left.push(mkp(0, 0));
            l = 0;
          }
        }
      }
      // FIM DA ENTRADA
      ans = 0;
      while (ferry.size() or left.size() or right.size()) {
        if (!(ans & 1)) {
          // RETIRA OS QUE ENTRARAM PELA DIREITA
          while (ferry.size() and ferry.back().second == 'r') {
            capacity += ferry.back().first;
            ferry.pop_back();
          }
          // COLOCA CARROS À ESQUERDA
          while (left.size()) {
            tmp = left.front();
            if (!tmp.first) {
              left.pop();
              break;
            }
            if (capacity - tmp.first >= 0) { // CARRO COUBE
              ferry.pf(tmp);
              capacity -= tmp.first;
              left.pop();
            } else
              break;
          }
        } else { // FERRY ESTÁ NA DIREITA
          // RETIRA OS QUE ENTRARAM PELA ESQUERDA
          while (ferry.size() and ferry.front().second == 'l') {
            capacity += ferry.front().first;
            ferry.pop_front();
          }
          // COLOCA CARROS À DIREITA
          while (right.size()) {
            tmp = right.front();
            if (!tmp.first) {
              right.pop();
              break;
            }
            if (capacity - tmp.first >= 0) { // CARRO COUBE
              ferry.pb(tmp);
              capacity -= tmp.first;
              right.pop();
            } else
              break;
          }
        }
        ans++;
      }
      printf("%d\n", --ans);
    }
  }
  return 0;
}
