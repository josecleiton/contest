
#include <vector>
#define FOR(i,a) for(int i=0; i<a; i++)
#define TAM 1024000
using namespace std;
typedef vector<int> vi;


vi A;

class SegmentTree {
private:
  vi st, lazy;
  long long n;
  int left(int p) { return p << 1; } // PODEM SER CONSTEXPR OU MACROS 
  int right(int p) { return (p << 1) | 1; } // SE DESEMPENHO FOR UM PROBLEMA

  void build(int p, int L, int R) { 
    lazy[p] = 0;
    if(L == R){
      st[p] = A[L];
    }
    else {
      int mid = (L+R)>>1;
      build(left(p), L, mid);
      build(right(p), mid+1, R);
      st[p] = combine(st[left(p)], st[right(p)]);
    }
  }

  void propagate(int p, int L, int R) {
    st[p] += (R-L+1)*lazy[p];
    if(L != R) {
      lazy[left(p)] += lazy[p];
      lazy[right(p)] += lazy[p];
    }
    lazy[p] = 0;
  }

  void update(int p, int L, int R, int startRange, int endRange, int val) {
    if(lazy[p]) propagate(p, L, R);
	  if(startRange > R or endRange < L) return; // não há sobreposição
	  if(startRange <= L and endRange >= R) { // sobreposição total
      st[p] +=  (R-L+1)*val;
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
  // ABAIXO TEMOS UMA FUNÇÃO DE SOMA 
  // OU SEJA ESSA ST RESPONDE A UMA RANGE SUM
  int combine(int left_val, int right_val) {  // PODE SER UM MACRO OU CONSTEXPR
    return left_val + right_val;               // SE DESEMPENHO FOR UM PROBLEMA
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
    build(1, 0, n-1);
  }
  int query(int i, int j) { return query(1, 0, n-1, i, j); }
  void update(int i, int j, int val) { return update(1, 0, n-1, i, j, val); }
};