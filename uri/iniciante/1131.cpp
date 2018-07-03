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
int n,m,r;
vector<int> v;
v.resize(3);
do{
    cin>>n>>m;
    if(n>m) v[0]++;
    else if(n<m) v[1]++;
    else v[2]++;
    puts("Novo grenal (1-sim 2-nao)");
    C(r);
} while(r!=2);
cout<<accumulate(v.begin(),v.end(),0)<<" grenais"<<endl<<"Inter:"<<v[0]<<endl<<"Gremio:"<<v[1]<<endl<<"Empates:"<<v[2]<<endl;
if(v[0]>v[1]) puts("Inter venceu mais");
else if(v[0]<v[1]) puts("Gremio venceu mais");
return 0;
}
