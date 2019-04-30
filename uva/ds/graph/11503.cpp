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
typedef vector<ll> vll;
typedef vector<string> vstr;
typedef vector<bool> vbit;
typedef pair<ll, ll> pii;
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

class UnionFind {
private:
  map<string, string> p;
  unordered_map<string, int> tam;
  unordered_map<string, int> rank;
public:
  void reset() {
  	rank.clear();
    p.clear();
    tam.clear();
  }
  const string& findSet(const string& i) {
    //return (p[i] == i) ? i : (p[i] = findSet(p[i]));
    if(p.find(i) == p.end()) {
    	p[i] = i;
    	tam[i] = 1;
    	rank[i] = 0;
    	return i;
    }
    return (p[i] == i) ? i : (p[i] = findSet(p[i]));
  }
  bool isSameSet(const string& i, const string& j) {
    return findSet(i) == findSet(j);
  }
  void unionSet(const string& i, const string& j) {
    if(!isSameSet(i, j)) {
      string x = findSet(i) , y = findSet(j);
      if(rank[x] > rank[y]){
      	p[y] = x;
      	tam[x] += tam[y];
      }
      else {
        p[x] = y;
        tam[y] += tam[x];
        if(rank[x] == rank[y]) rank[y]++;
      }
    }
  }
  
  int getTam(const string& s) {
  	return tam[findSet(s)];
  }

};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int ct,n;
  //char c;
  //ll n, m, l;
  //int n, m, l;
  string s1,s2;
  UnionFind ufds;
  while (cin>>ct) {
  	while(ct--) {
  		cin>>n;
  		ufds.reset();
  		while(n--) {
  			cin>>s1>>s2;
  			ufds.unionSet(s1, s2);
  			printf("%d\n", ufds.getTam(s1));
  		}
  	}
  }
  return 0;
}
