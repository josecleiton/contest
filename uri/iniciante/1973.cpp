//TEMPLATE COM MACROS PARA OS CONTESTS
//compile usando: g++ -std=c++11 -lm -O3 arquivo.cpp
#include <bits/stdc++.h>
#define FOR(x) for(int i=0;i<x;i++)
#define ROF(x) for(int i=x-1;i>=0;i--)
#define FORJ(x) for(int j=0;j<x;j++)
#define FORQ(Q) for(int i=0;Q;i++)
#define FORM(x,y) for(int i=0;i<x;i++) for(int j=0;j<y;j++)
#define FORT(x,y) for(int i=x;i<y;i++)
#define ROFT(x,y) for(int i=x-1;i>=y;i--)
#define WHILE(n,x) while((n--)&&cin>>x)
#define M(x,y) max(x, y)
#define m(x,y) min(x, y)
#define c(x) cout<<x<<endl
#define C(x) cin>>x
#define set(a,b) cout.precision(a); cout<<fixed<<b<<endl
#define pcs(a) cout.precision(a)
#define fx(a) fixed<<a
#define gl(s) getline(cin,s)
#define pb(a) push_back(a)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int main(){
  int n; cin >> n;
  vector<long long> a(n);
  for (auto &i : a) cin >> i;
  int i = 0;
  unordered_set<int> s;
  while (i >= 0 && i < n) {
    s.insert(i);
    if (a[i] & 1) {
      if (a[i])
        a[i]--;
      ++i;
    } 
    else {
      if (a[i])
        a[i]--;
      --i;
    }
  }
  long long total = accumulate(a.begin(), a.end(), 0LL);
  cout << s.size() << " " << total << endl;

}
