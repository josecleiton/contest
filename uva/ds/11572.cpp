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
  int ct,n,sf;
  //char c;
  //ll n, m, l;
  //int n, m, l;
  //string s;
  scanf("%d", &ct);
  while(ct--) {
  	scanf("%d", &n);
  	UMAP(int, int) vis;
  	int cur_tam=0, max_tam=0, prev_ind;
  	if(n) {
  		cur_tam=max_tam=1;
  		scanf("%d", &sf);
  		vis[sf] = 1;
  		PARA(i, 1, n) {
  			scanf("%d", &sf);
  			prev_ind = vis[sf]-1;
  			if(prev_ind == -1 or i - cur_tam > prev_ind) {
  				cur_tam++;
  			} else {
  				max_tam = max(max_tam, cur_tam);
  				cur_tam = i - prev_ind;
  			}
  			vis[sf] = i+1;
  		}
  		
  		printf("%d\n", max(max_tam, cur_tam));
  		
  	} else {
  		puts("0");
  	}
  	//f("%d\n", freq_ind.begin()->first);
  	
  }
  return 0;
}
