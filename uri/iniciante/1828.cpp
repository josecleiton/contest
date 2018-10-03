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

bool game(string a, string b) {
  if ("tesoura" == a && "papel" == b) return 1;
  if ("papel" == a && "pedra" == b) return 1;
  if ("pedra" == a && "lagarto" == b) return 1;
  if ("lagarto" == a && "Spock" == b) return 1;
  if ("Spock" == a && "tesoura" == b) return 1;
  if ("tesoura" == a && "lagarto" == b) return 1;
  if ("lagarto" == a && "papel" == b) return 1;
  if ("papel" == a && "Spock" == b) return 1;
  if ("Spock" == a && "pedra" == b) return 1;
  if ("pedra" == a && "tesoura" == b) return 1;
  return 0;
}

int main() {
  int n; cin >> n;
  string a, b;
  for (int k = 0; k < n; ++k) {
    cout << "Caso #" << (k + 1) << ": ";
    cin >> a >> b;
    if (a == b)
      cout << "De novo!" << endl;
    else if (game(a, b))
      cout << "Bazinga!" << endl;
    else
      cout << "Raj trapaceou!" << endl;

  }
  return 0;
}