
#include <vector>
#define FOR(i,a) for(int i=0; i<a; i++)
#define TAM 1024000
using namespace std;
typedef vector<int> vi;

class SegmentTree {
private:
  vi st, lazy, A;
  long long n;
  int left(int p) { return p << 1; }
  int right(int p) { return (p << 1) | 1; }

  void build(int p, int L, int R) { 
    lazy[p] = 0;
    if(L == R){
      st[p] = A[L];
    }
    else {
      int mid = (L+R)>>1;
      build(left(p), L, mid);
      build(right(p), mid+1, R);
      auto left_val = st[left(p)];
      auto right_val = st[right(p)];
      st[p] = combine(left_val, right_val);
    }
  }

  void propagate(int p, int L, int R) {
    st[p] += lazy[p];
    if(L != R) {
      lazy[left(p)] = lazy[right(p)] = lazy[p];
    }
    lazy[p] = 0;
  }

  void update(int p, int L, int R, int startRange, int endRange, int val) {
    if(lazy[p]) propagate(p, L, R);
	  if(startRange > R or endRange < L) return; // não há sobreposição
	  if(startRange <= L and endRange >= R) { // sobreposição total
      st[p] = val;
			if(L != R) {
				lazy[left(p)] += val;
        lazy[right(p)] += val;
			}
			return;
	  } else {
	  	// sobreposição parcial de intervalos
    	int mid = (L+R)>>1;
    	update(left(p), L, mid, startRange, endRange, val);
    	update(right(p), mid+1, R, startRange, endRange, val);
    	st[p] = combine(st[left(p)], st[right(p)]);
    }
  }
  // FUNÇÃO QUE ESCOLHERÁ O QUE FICA NO NÓ 
  // ABAIXO TEMOS UMA FUNÇÃO QUE ESCOLHE O MENOR INT
  // OU SEJA ESSA ST RESPONDE A UMA RANGE MINIMUM QUERY (RMQ)
  int combine(int left_val, int right_val) { 
    return left_val + right_val;
  }

  int query(int p, int L, int R, int i, int j) {
    if(lazy[p]) propagate(p, L, R);
    if(i > R or j < L) return 0;
    if(i <= L and j >= R)  return st[p];
    int mid = (L+R)>>1;
    auto left_val = query(left(p), L, mid, i, j);
    auto right_val = query(right(p), mid+1, R, i, j);
    if(!left_val) return right_val;
    if(!right_val) return left_val;
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
  int query(int i, int j) { return query(1, 0, n-1, i, j); }
  void update(int i, int j, int val) { return update(1, 0, n-1, i, j, val); }
};