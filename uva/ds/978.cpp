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
#define PQ(type, ord) priority_queue<type, deque<type>, ord<type>>
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
  int ct;
  //char c;
  //ll n, m, l;
  //int n, m, l;
  //string s;
  int sg,sb,b,gc,bc,lem;
  scanf("%d", &ct);
  FOR(t, ct) {
  	if(t) putchar('\n');
  	PQ(int, less) green, blue;
  	scanf("%d%d%d", &b, &sg,&sb);
  	while(sg--) {
  		scanf("%d", &lem);
  		green.push(lem);
  	}
  	while(sb--) {
  		scanf("%d", &lem);
  		blue.push(lem);
  	}

  	do{
  		queue<int> bwinners, gwinners;
  		for(int i=0; (green.size() and blue.size()) and i<b; i++){
  			gc = green.top();
  			bc = blue.top();
  			green.pop();
  			blue.pop();
  			if(gc > bc) {
  				gwinners.push(gc-bc);
  			} else if(bc > gc) {
  				bwinners.push(bc-gc);
  			}
  		}
  		while(gwinners.size()) {
  			green.push(gwinners.front());
  			gwinners.pop();
  		}
  		while(bwinners.size()) {
  			blue.push(bwinners.front());
  			bwinners.pop();
  		}
	} while(blue.size() and green.size());
  	
  	if(green.size()){
  		puts("green wins");
  		while(green.size()) {
  			printf("%d\n", green.top());
  			green.pop();
  		}
  	} else if(blue.size()) {
  		puts("blue wins");
  		while(blue.size()){
  			printf("%d\n", blue.top());
  			blue.pop();
  		}
  	} else {
  		puts("green and blue died");
  	}
  	
  }
  return 0;
}
