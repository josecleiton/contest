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

vi input(100000);

ll LSOne(ll s) {
  return s & (-s);
}

class FerwickTree {
private:
  vi ft;
public:
  FerwickTree(int n) { ft.assign(n+1, 1); }
  int LSOne(int S) {
    return S & (-S);
  }
  int rsq(int b) {
    int sum = 0;
    for(; b; b -= LSOne(b)) sum += ft[b];
    return sum;
  }
  int rsq(int a, int b ) {
    return rsq(b) - (a == 1 ? 0 : rsq(a-1));
  }
  void adjust(int k, int v) {
    for(; k < ft.size(); k += LSOne(k))
      ft[k] *= v;
  }
};

int main() {
  //ios::sync_with_stdio(0);
  //cin.tie(0);
  int n,k,low,up;
  char c;
  //ll n, m, l;
  //int n, m, l;
  //string s;
  ll local_ans;
  string ans;

  while (scanf("%d%d", &n, &k) != EOF) {
    FerwickTree ft(n);
    ans = "";
  	FOR(i, n) {
  		scanf("%d", &input[i]);
  		ft.adjust(i+1, input[i]);
  	}
    scanf("%*c");
  	while(k--) {
  		scanf("%c%d%d%*c", &c, &low, &up);
  		if(c == 'C') {
  			ft.adjust(low, up);
  		} else {
  			local_ans = ft.rsq(low, up);
  			ans.push_back((local_ans > 0 ? '+' : (!local_ans ? '0' : '-')));
  		}
  	}
  	puts(ans.c_str());
  }
  return 0;
}
