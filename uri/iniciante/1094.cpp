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
#define cfx(a) cout<<fixed<<a<<endl
#define gl(s) getline(cin,s)
#define pb(a) push_back(a)

using namespace std;

int main(){
int n,m;
char c;
C(n);
vector<int> v;
v.resize(3);
v[0]=v[1]=v[2]=0;
FOR(n){
    cin>>m>>c;
    c=(c=='C')?'c':c;
    v[c%3] += m; 
}
cout.precision(2);
cout<<"Total: "<<v[0]+v[1]+v[2]<<" cobaias"<<endl<<"Total de coelhos: "<<v[0]<<endl<<"Total de ratos: "<<v[1]<<endl<<"Total de sapos: "<<v[2]<<endl;
cout<<"Percentual de coelhos: "<<fx((v[0]*100)/(double)(v[0]+v[1]+v[2]))<<" %"<<endl<<"Percentual de ratos: "<<fx((v[1]*100)/(double)(v[0]+v[1]+v[2]))<<" %"<<endl<<"Percentual de sapos: "<<fx((v[2]*100)/(double)(v[0]+v[1]+v[2]))<<" %"<<endl;

return 0;
}
