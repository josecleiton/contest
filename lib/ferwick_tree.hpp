#include <vector>
#define FOR(i,a) for(int i=0; i<a; i++)
using namespace std;
typedef vector<int> vi;

class FerwickTree {
private:
  vi ft;
public:
  FerwickTree(int n) { ft.assign(n+1, 0); }
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
      ft[k] += v;
  }
};