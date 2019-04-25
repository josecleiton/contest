// TEMPLATE COM MACROS PARA OS CONTESTS
// compile usando: g++ -std=c++11 -lm -O3 arquivo.cpp
#include <bits/stdc++.h>
//#define set(a, b) cout.precision(a); cout << fixed << b << endl
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
 
typedef unordered_map<int, unordered_map<int, bool>> _graph;
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
  int n,m; char a, b;
  //char c;
  //ll n, m, l;
  //int n, m, l;
  //string s;
  bitset<26> bs;
  _graph graph;
  while (scanf("%d", &n) != EOF) {
  	scanf("%d%*c", &m);
  	graph.clear();
  	bs.reset();
  	FOR(i, 3) {
  		scanf("%c", &a);
  		bs.set(a-'A');
  	}
  	scanf("%*c");
  	while(m--) {
  		scanf("%c%c%*c", &a,&b);
  		a = a-'A';
  		b = b-'A';
  		graph[a][b] = true;
  		graph[b][a] = true;
  	}
  	int areas_ativas = 0, ano = 0;
  	bool fail = false;
  	while(bs.count() < n) {
  		vi acordou;
  		FORIT(edge, graph) {
  			int local_ans {};
  			if(bs[edge->first]) continue;
  			FORIT(vizinho, edge->second) {
  				if(bs[vizinho->first]) local_ans++;
  			}
  			if(local_ans >= 3) acordou.pb(edge->first);
  		}
  		if(acordou.empty()){
  			fail = true;
  			break;
  		}
  		for(const auto& item: acordou){
  			bs.set(item);
  		}
  		ano++;
  	}
  	if(fail) {
  		puts("THIS BRAIN NEVER WAKES UP");
  	} else {
  		printf("WAKE UP IN, %d, YEARS\n", ano);
  	}
  }
  return 0;
}
 