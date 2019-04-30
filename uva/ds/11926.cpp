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
#define TAM 1000000
 
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
  int ct = 0;
  //char c;
  //ll n, m, l;
  int n, m, l,r,f;
  //string s;
  char bitmap[TAM+5];
  bool ans;
  array<string, 2> resp {"CONFLICT", "NO CONFLICT"};
  while (scanf("%d%d", &n, &m) and n+m) {
  	memset(bitmap, 0, TAM);
  	ans = true;
  	FOR(i, n) {
  		scanf("%d%d", &l, &r);
  		if(!ans) continue;
  		if(i) {
				for(int j=l; j<TAM and j<=r; j++){
  				if(bitmap[j]) {
  					ans = false;
  					break;
  				}
  			}
  		}
  		if(ans) memset(bitmap+l, 1, r-l);
  	}
  	while(m--) {
  		scanf("%d%d%d", &l, &r, &f);
			printf("FACTOR = %d\nL = %d | R = %d\n", f, l, r);
  		if(!ans) continue;
  		int k=0;
  		FOR(j, f) {
				int lim = (r+f*j <= TAM) ? r+f*j : TAM, start = l+f*j;
  			for(k=start; k<lim; k++) {
  				if(bitmap[k]){
  					ans = false;
  					break;
  				}
  			}
				//printf("%d\n", k);
				//putchar('\n');
				
  			if(k==TAM or !ans) break;
  			if(ans) memset(bitmap+start, 1, lim - start);
  		}
  	}
  	printf("%s\n", resp[ans].c_str());
  }
  return 0;
}