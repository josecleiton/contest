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

struct _gene {
	int gene;
	vector<string> parents;
};

int resolve(map<string, _gene>& tree, const string key ){
  if(!tree[key].parents.empty()) {
    if(!tree[key].gene) {
      int gene_p1 = resolve(tree,  tree[key].parents[0]);
      int gene_p2 = resolve(tree, tree[key].parents[1]);
      int gene = gene_p1*gene_p2;
      if(!gene and max(gene_p1, gene_p2) == 2) {
        gene = 1;
      } else if(gene == 4) {
        gene = 2;
      }
      tree[key].gene = gene;
    }
    return tree[key].gene;

  } 
  return tree[key].gene;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int ct;
  //char c;
  //ll n, m, l;
  //int n, m, l;
  //string s;
  MAP(string, _gene, less) tree;
  UMAP(int, string) dict = {
  	{0, "non-existent"},
  	{1, "recessive"},
  	{2, "dominant"},
  };
  UMAP(string, int) tcid = {
  	{"non-existent", 1},
  	{"recessive", 2},
  	{"dominant", 3},
  };
  string s1,s2,ult;
  vector<string> childs;
  int gene;

  cin>>ct;
  while(ct--) {
	cin>>s1>>s2;

	if((gene = tcid[s2])) {
		tree[s1].gene = gene-1;
	} else {
		tree[s2].parents.pb(s1);
		if(tree[s2].parents.size() == 2)
			childs.pb(s2);

	}
  }
  
  for(const auto& child: childs){
    resolve(tree, child);
  }
  
  for(const auto& no: tree) {
  	cout<<no.first<<' '<<dict[no.second.gene]<<endl;
  }
  
  return 0;
}
