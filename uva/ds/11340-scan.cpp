// TEMPLATE COM MACROS PARA OS CONTESTS
// compile usando: g++ -std=c++11 -lm -O3 arquivo.cpp
#include <bits/stdc++.h>
#define FORM(x, y) for (int i = 0; i < x; i++) for (int j = 0; j < y; j++)
#define set(a, b) cout.precision(a); cout << fixed << b << endl
#define pcs(a) cout.precision(a)
#define fx(a) fixed << a
#define FOR(i, a) for (int i = 0; i < a; i++)
#define PARA(i, a, k, n) for (int i = k; i < n; i++)
#define FORIT(it, c) for (auto it = c.begin(); it != c.end(); it++)
#define pb push_back
#define MAP(t1, t2, ord) map<t1, t2, ord<t1>>
#define UMAP(t1, t2) unordered_map<t1, t2>
#define matrix(name, type, n, m) vector<vector<type>> name(n, vector<type>(m))
#define PQ(name, type, ord) priority_queue<type, deque<type>, ord<type>> name
#define ROF(i, a) for (int i = a - 1; i >= 0; i--)
using namespace std;
typedef vector<int> vi;
typedef int64_t ll;
typedef unsigned long long ull;
typedef vector<ll> vll;
typedef vector<string> vstr;
typedef vector<bool> vbit;
typedef pair<ll, ll> pii;
typedef vector<double> vd;

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
  ll n, m, lines;
  string s;
  int c;
  double f;
  char str[11000];
  while (scanf("%d", &ct) == 1) {
    while(ct--) {
      unordered_map<char, double> M;
      double ans = 0.0;
      scanf("%lld", &n);
      while(n--){
        scanf("%d%lf", &c, &f);
        M[c] = f/100.0;
      }
      scanf("%lld", lines);
      while(lines--) {
        scanf("%[^\n]%*c", str);
        for(int i=0; str[i]; i++){
          ans += M[str[i]];
        }
      }

      printf("%.2lf$\n", ans);
    }
  }
  return 0;
}
