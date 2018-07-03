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
int main(){
vector<string> a;
a.pb("Brasilia"); //0
a.pb("Salvador");
a.pb("Sao Paulo");
a.pb("Rio de Janeiro");
a.pb("Juiz de Fora");
a.pb("Campinas");
a.pb("Vitoria");
a.pb("Belo Horizonte"); //7

int d;
C(d);
if(d==61) d=0;
else if(d==71) d=1;
else if(d==11) d=2;
else if(d==21) d=3;
else if(d==32) d=4;
else if(d==19) d=5;
else if(d==27) d=6;
else if(d==31) d=7;
else {
    d=-1;
    c("DDD nao cadastrado");
}

if(d!=-1) c(a[d]);

return 0;
}
