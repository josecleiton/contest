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

void bfs(char root, UMAP(char, UMAP(char, bool))& graph, vi& used, int& ans_t, int& ans_ac) {
	if(graph[root].empty()) {
		ans_ac++;
		return;
	}
	queue<char> q;
	vbit vis(26);
	q.push(root);
	vis[root-'A'] = true;
	int res = 0;
	ans_t++;
	char front;
	while(q.size()) {
		front = q.front();
		q.pop();
		used[front-'A'] = 2;
		res++;
		for(const auto& e: graph[front]) {
			if(!vis[e.first-'A']){
				q.push(e.first);
				vis[e.first-'A'] = true;
			}
		}
	}
}

int main() {
  //ios::sync_with_stdio(0);
  //cin.tie(0);
  int ct;
  //char c;
  //ll n, m, l;
  //int n, m, l;
  //string s;
  char line[80];
  scanf("%d%*c", &ct);
  char v1, v2;
  vi used(26);
  while(ct--) {
  	UMAP(char, UMAP(char, bool)) graph;
  	fill(used.begin(), used.end(), 0);
  	while(fgets(line, 80, stdin)) {
  		if(line[0] == '(') {
  			sscanf(line, "(%c,%c)", &v1, &v2);
  			graph[v1][v2] = true;
				graph[v2][v1] = true;
  		} else {
  			if(line[0] == '*') continue;
  			for(int i=0; line[i]; i++) {
  				if(isalpha(line[i])){
						used[line[i]-'A'] = 1;
					}
  			}
  			break;
  		}
  		
  	}
  	int ans_tree=0, ans_acorn=0;
		FOR(i, 26) {
			if(used[i] == 1)
  			bfs('A'+i, graph, used, ans_tree, ans_acorn);
  	}
  	printf("There are %d tree(s) and %d acorn(s).\n", ans_tree, ans_acorn);
  	
  }
  return 0;
}
