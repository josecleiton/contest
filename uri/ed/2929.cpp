#include <bits/stdc++.h>
#define SET(a, b)                                                              \
  cout.precision(a);                                                           \
  cout << fixed << b << endl
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
#define PQ(type, ord) priority_queue<type, deque<type>, ord<type>>
#define mkp(a, b) make_pair(a, b)
#define TAM

using namespace std;
using vi = vector<int>;
using ll = int64_t;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vii = vector<pii>;
using vll = vector<ll>;
using vbit = vector<bool>;
using vstr = vector<string>;
using vd = vector<double>;
using _graph = unordered_map<int, unordered_map<int, bool>>;
using _wgraph = unordered_map<int, unordered_map<int, int>>;

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

int main() {
   ios::sync_with_stdio(0);
   cin.tie(0);
  int ct;
  // char c;
  ll n, m, l;
  // int n, m, l;
  string s;

 const unordered_map<string, int>& command = {{"MIN", 1}, {"POP", 2}, {"PUSH", 3}};

  while (cin >> n) {
    stack<int> nums;
    
    stack<int> mins;

    FOR(i, n) {
      cin >> s;

      if(command.at(s) == 1) {
        if(mins.size() + nums.size()) {
          cout << (mins.size() ? mins.top() : nums.size()) << '\n';
          continue;
        }

        cout << "EMPTY\n";
        continue;
      } 

      if(command.at(s) == 2) {
        if(nums.empty()) {
          cout << "EMPTY\n";
          continue;
        }

        if(mins.size() && nums.top() == mins.top()) {
          mins.pop();
        }

        nums.pop();

        continue;
      }

      cin >> ct;
      nums.push(ct);

      if(mins.empty() ||ct <= mins.top()) {
       mins.push(ct);
      }
      
    }
  }
  return 0;
}