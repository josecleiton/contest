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

using namespace std;
typedef vector<int> vi;
typedef int64_t ll;
typedef unsigned long long ull;
typedef vector<ll> vll;
typedef vector<string> vstr;
typedef vector<bool> vbit;
typedef pair<ll, ll> pii;
typedef vector<double> vd;
typedef pair<char, char> carta;


class Comp {
public:
    bool operator() (const string& a, const string& b) { // COMPARADOR ESTRITO PARA PRIORITY_Q, UMAP ETC
      int v[2] = {10, 10};
      if(a[0] >= 2 and a[0] <= 9) v[0] = a[0];
      if(b[0] >= 2 and b[0] <= 9) v[1] = b[0];
      return v[0] > v[1];
    }
};
/*
MODULAR ARITHMETIC
( a + b) % c = ( ( a % c ) + ( b % c ) ) % c
( a * b) % c = ( ( a % c ) * ( b % c ) ) % c
( a – b) % c = ( ( a % c ) – ( b % c ) ) % c

*/


int main() {
  int ct, t=1;
  char c;
  ll n, m, l,y, x,top;
  char s[3];
  string aux;
  array<string, 52> store;
  cin>>ct;
    FOR(t, ct) {
      for(auto& card: store) {
        cin>>card;
      }
      top = 26;
      y = 0;

      FOR(j, 3) {
        x = 10;
        if(store[top][0] >= '2' and store[top][0] <= '9') 
          x = store[top][0] - '0';
        y += x;
        top -= (10-x)+1;
      }

      if(y > top+1) {
        y = 26+(y-top);
      }
      printf("Case %d: %s\n", t+1, store[y-1].c_str());
    }
  return 0;
}