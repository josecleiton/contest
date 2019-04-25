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
  int n,m;
  //char c;
  //ll n, m, l;
  //int n, m, l;
  //string s;
  int per_row, item;
  while (scanf("%d%d", &n, &m) != EOF) {
  	map<int, vector<pair<int, int> > >graph, graph_r;
  	FOR(i, n) {
  		scanf("%d", &per_row);
  		if(per_row) {
	  		vi indexes(per_row);
	  		FOR(j, per_row) {
	  			scanf("%d", &indexes[j]);
	  		}
	  		for(const auto& ind: indexes) {
	  			scanf("%d", &item);
	  			graph[i+1].pb(mkp(ind, item));
	  			graph_r[ind].pb(mkp(i+1, item));
	  		}
  		} else {
  			graph[i+1];
  		}
  	}
  	printf("%d %d\n", m, n);
  	PARA(i, 1, m+1) {
  		per_row = graph_r[i].size();
  		printf("%d", per_row);
  		if(per_row) {
  			int j=0;
  			putchar(' ');
  			vi itens(per_row);
  			for(const auto& item: graph_r[i]) {
  				printf("%d", item.first);
  				itens[j++] = item.second;
  				if(j != per_row) putchar(' ');
  			}
  			putchar('\n');
  			for(j=0; j<per_row; j++) {
  				printf("%d", itens[j]);
  				if(j+1 < per_row) putchar(' ');
  			}
  			putchar('\n');
  		} else {
  			puts("\n");
  		}
  	}
  }
  return 0;
}
