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
#define PQ(name, type, ord) priority_queue<type, deque<type>, ord<type>> name
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
  //ios::sync_with_stdio(0);
  //cin.tie(0);
  int day, ind;
  double h,d,f,s,u,jaiminho;
  char c;
  while (scanf("%lf%lf%lf%lf", &h, &u, &d, &f) and h) {
  	day = 1;
  	s = 0.0;
		jaiminho = (f/100.0)*u;
  	while(true) {
  		// DIA
  		if(!signbit(u))
  			s += u; // SALTO
  		if(s > h) {
				printf("success on day %d\n", day);
  			break;
  		}
  		// NOITE
  		s -= d;
  		if(signbit(s)) {
				printf("failure on day %d\n", day);
  			break;
  		}
  		// DIA TERMINOU = APLICA FADIGA
  		u -= jaiminho;
  		day++;
  	}
  }
  return 0;
}
