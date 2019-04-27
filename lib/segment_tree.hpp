#include <vector>
#include <cstdint>
#define FOR(i,a) for(int i=0; i<a; i++)
using namespace std;
typedef vector<int> vi;

class SegmentTree {
private:
  vi st, A;
  int n;
  int left(int p) { return p << 1; }
  int right(int p) { return (p << 1) + 1; }

  void build(int p, int L, int R) { 
    if(L == R ) st[p] = A[L];
    else {
      int mid = (L+R)/2;
      build(left(p), L, mid);
      build(right(p), mid+1, R);
      int left_val = st[left(p)];
      int right_val = st[right(p)];
      st[p] = combine(left_val, right_val);
    }
  }
  void update(int p, int L, int R, int i, int val) {
	  if(i < L or i > R) return;
	  if(L == R && L == i) {
	    st[p] = val;
	  } else {
      int mid = (L+R)/2;
      update(left(p), L, mid, i, val);
      update(right(p), mid+1, R, i, val);
      int left_val = st[left(p)];
      int right_val = st[right(p)];
      st[p] = combine(left_val, right_val);
    }
  }
  // FUNÇÃO QUE ESCOLHERÁ O QUE FICA NO NÓ 
  // ABAIXO TEMOS UMA FUNÇÃO QUE ESCOLHE O MENOR INT
  // OU SEJA ESSA ST RESPONDE A UMA RANGE MINIMUM QUERY (RMQ)
  int combine(int left_val, int right_val) { 
    return (left_val <= right_val) ? left_val : right_val;
  }

  int query(int p, int L, int R, int i, int j) {
    if(i > R or j < L) return INT32_MAX;
    if(L >= i and R <= j)  return st[p];
    int mid = (L+R)/2;
    int left_val = query(left(p), L, mid, i, j);
    int right_val = query(right(p), mid+1, R, i, j);
    if(left_val == INT32_MAX) return right_val;
    if(right_val == INT32_MAX) return left_val;
    return combine(left_val, right_val);
  }
public:
  SegmentTree(const vi& _A) {
    A = _A;
    n = A.size();
    st.assign(4*n, 0);
    build(1, 0, n-1);
  }
  int query(int i, int j) { return query(1, 0, n-1, i, j); }
};