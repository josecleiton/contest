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
#define TAM 1024010

using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int>> vii;
typedef int64_t ll;
typedef unsigned long long ull;
typedef vector<ll> vll;
typedef vector<string> vstr;
typedef vector<bool> vbit;
typedef pair<ll, ll> pii;
typedef vector<double> vd;
typedef unordered_map<int, unordered_map<int, bool>> _graph;
typedef unordered_map<int, unordered_map<int, int>> _wgraph;

char pirates[TAM];
array<int, 2> neutral, ans;

class SegmentTree {
private:
  vector<array<int, 2> > st;
  vi lazy;
  int n;
  int left(int p) { return p << 1; }
  int right(int p) { return (p << 1) | 1; }

  void build(int p, int L, int R) { 
	lazy[p] = 0;
    if(L == R){
    	int idx = pirates[L]-'0';
    	st[p][idx] = 1;
    	st[p][!idx] = 0;
    }
    else {
      int mid = (L+R)/2;
      build(left(p), L, mid);
      build(right(p), mid+1, R);
      auto left_val = st[left(p)];
      auto right_val = st[right(p)];
      st[p] = combine(left_val, right_val);
    }
  }

	void set_lazy(int p) {
		int prev_val = lazy[left(p)];
		int ans = lazy[p];
		if(prev_val == 1) {
			// INV
			if(lazy[p] == 1) ans = 0;
			else if(lazy[p] == 2) ans = 2;
			else if(lazy[p]) ans = 3;

		} else if(prev_val == 3) {
			 // BUCC
			if(lazy[p] == 1 or lazy[p] == 2) ans = 2;
			// else if(lazy[p] == 3) ans = 0;

		} else if(prev_val){
			// NOT BUCC
			if(lazy[p] == 1 or lazy[p] == 3) ans = 3;
			// else if(lazy[p] == 2) ans = 0;

		}
		lazy[left(p)] = lazy[right(p)] = ans;
	}
	int set_lazy_child(int p, int val) {
		int prev_val = lazy[p];
		int ans = val;
		if(prev_val == 1) {
			// INV
			if(val == 1) ans = 0;
			else if(val == 2) ans = 2;
			else if(val) ans = 3;

		} else if(prev_val == 3) {
			 // BUCC
			if(val == 1 or val == 2) ans = 2;
			// else if(val == 3) ans = 0;

		} else if(prev_val){
			// NOT BUCC
			if(val == 1 or val == 3) ans = 3;
			// else if(val == 2) ans = 0;

		}
		return ans;
	}

  void update(int p, int L, int R, int startRange, int endRange, int val) {
			if(lazy[p]) {
				if(lazy[p] == 1) {
					// inverte
					swap(st[p][0], st[p][1]);
				} else if(lazy[p] == 3) {
					// BUCC
					st[p][1] += st[p][0];
					st[p][0] = 0;
				} else /*if(lazy[p] == 2 or lazy[p] == 5)*/ {
					// NOT BUCC
					st[p][0] += st[p][1];
					st[p][1] = 0;
				}
				if(L != R) {
					set_lazy(p);
				}
				lazy[p] = 0;
			}
  	  /*
  		se houver operações não aplicadas na segunda posição, aplique-as
  	  */
  	  
	  if(startRange > R or endRange < L) return; // não há sobreposição
	  if(startRange <= L and endRange >= R) { // sobreposição total
			if(val == 3) {
				st[p][1] = st[p][0]+st[p][1];
				st[p][0] = 0;
			} else if(val == 2) {
				st[p][0] = st[p][0] + st[p][1];
				st[p][1] = 0;
			} else if(val) {
				swap(st[p][0], st[p][1]);
			}
			if(L != R) {
				auto ans = set_lazy_child(left(p), val);
				lazy[left(p)] = lazy[right(p)] = ans;

			}
			return;
	  } else {
	  	// sobreposição parcial de intervalos
    	int mid = (L+R)/2;
    	update(left(p), L, mid, startRange, endRange, val);
    	update(right(p), mid+1, R, startRange, endRange, val);
    	st[p] = combine(st[left(p)], st[right(p)]);
    }
  }
  // FUNÇÃO QUE ESCOLHERÁ O QUE FICA NO NÓ 
  // ABAIXO TEMOS UMA FUNÇÃO QUE ESCOLHE O MENOR INT
  // OU SEJA ESSA ST RESPONDE A UMA RANGE MINIMUM QUERY (RMQ)
  array<int, 2> combine(array<int, 2>& left_val, array<int, 2>& right_val) { 
    FOR(i, 2)
    	ans[i] = left_val[i] + right_val[i];
    return ans;
  }

  array<int, 2> query(int p, int L, int R, int i, int j) {
	if(lazy[p]) {
		if(lazy[p] == 1) {
			// inverte
			swap(st[p][0], st[p][1]);
		} else if(lazy[p] == 3) {
			// BUCC
			st[p][1] += st[p][0];
			st[p][0] = 0;
		} else /*if(lazy[p] == 2 or lazy[p] == 5)*/ {
			// NOT BUCC
			st[p][0] += st[p][1];
			st[p][1] = 0;
		}
		if(L != R) {
			set_lazy(p);
		}
		lazy[p] = 0;
	}
    if(i > R or j < L) return neutral;
    if(i <= L and j >= R)  return st[p];
    int mid = (L+R)/2;
    auto left_val = query(left(p), L, mid, i, j);
    auto right_val = query(right(p), mid+1, R, i, j);
    if(!(left_val[0]+left_val[1])) return right_val;
    if(!(right_val[0]+right_val[1])) return left_val;
    return combine(left_val, right_val);
  }
public:
  SegmentTree() {
  	lazy.resize(TAM<<2);
  	st.resize(TAM<<2);
  }
  void reset(const int& _n) {
    n = _n;
    //pair<int, int> tmp {0, 0};
    build(1, 0, n-1);
  }
  int query(int i, int j) { return query(1, 0, n-1, i, j)[1]; }
  void update(int i, int j, int val) { return update(1, 0, n-1, i, j, val); }
};

int main() {
  //ios::sync_with_stdio(0);
  //cin.tie(0);
  int ct,n,m,t,final_len,len,curr_in_len,q,lo,hi;
  char c;
  //ll n, m, l;
  //int n, m, l;
  //string s;
  char in[80];
  SegmentTree st;
  while (scanf("%d", &ct) != EOF) {
  	FOR(i, ct) {
  		scanf("%d", &m);
  		final_len = 0;
  		while(m--) {
  			scanf("%d%s", &t, in);
  			len = strlen(in);
  			FOR(i, t) {
  				FOR(j, len) {
  					pirates[final_len++] = in[j];
  				}
  			}
  		}
  		st.reset(final_len);
  		printf("Case %d:\n", i+1);
  		scanf("%d%*c", &q);
  		for(int k=1; q--;) {
  			scanf("%c%d%d%*c", &c, &lo, &hi);
  			switch(c) {
  				case 'F':
  					st.update(lo, hi, 3);
  				break;
  				case 'E':
  					st.update(lo, hi, 2);
  				break;
  				case 'I':
  					st.update(lo, hi, 1);
  				break;
  				default:
  					printf("Q%d: %d\n", k++, st.query(lo, hi));
  				break;
  			}
  		}
  	}
  }
  return 0;
}
