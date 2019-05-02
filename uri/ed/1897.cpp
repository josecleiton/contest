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

int op(const int& n, const int& i) {
	switch (i) {
		case 0: 
			return n*2;
		case 1:
			return n*3;
		case 2:
			return n/2;
		case 3:
			return n/3;
		case 4:
			return n+7;
		case 5:
			return n-7;
	}
}

int resolve(const int& n, const int& m) {
	if(n==m) return 0;
	queue<pair<int, int>> fila;
	pair<int, int> fila_front;
	fila.push(mkp(n, 0));
	while(fila.size()) {
		fila_front = fila.front();
		if(fila_front.first == m) {
			return fila_front.second;
		}
		FOR(i, 6) {
			fila.push(mkp(op(fila_front.first, i), fila_front.second+1));
		}
		fila.pop();
	}
}

int main() {
  //ios::sync_with_stdio(0);
  //cin.tie(0);
  int n,m;
  //char c;
  //ll n, m, l;
  //int n, m, l;
  //string s;
  scanf("%d%d", &n,&m);
  printf("%d\n", resolve(n, m));
  return 0;
}
