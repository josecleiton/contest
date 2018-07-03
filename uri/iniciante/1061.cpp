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
int d,h,m,s,x,y;
scanf("%*s %d %d %*c %d %*c %d", &d,&h,&m,&s);
//c(d);c(h);c(m);c(s);
x=d*24*60*60+h*60*60+m*60+s;
scanf("%*s %d %d %*c %d %*c %d", &d,&h,&m,&s);
x=(d*24*60*60+h*60*60+m*60+s)-x;
cout<<x/(24*60*60)<<" dia(s)"<<endl;
x%=(24*60*60);
cout<<x/(60*60)<<" hora(s)"<<endl;
x%=(60*60);
cout<<x/60<<" minuto(s)"<<endl;
x%=60;
cout<<x<<" segundo(s)"<<endl;
return 0;
}
