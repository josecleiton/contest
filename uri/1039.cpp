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

using namespace std;

int main(){
int n,m;
cin>>n>>m;
n=(n>5)?n%5:n;
cout.precision(2);
if(n==1) cout<<"Total: R$ "<<fixed<<(double)(m*4.00)<<endl;
else if(n==2) cout<<"Total: R$ "<<fixed<<(double)(m*4.50)<<endl;
else if(n==3) cout<<"Total: R$ "<<fixed<<(double)(m*5.00)<<endl;
else if(n==4) cout<<"Total: R$ "<<fixed<<(double)(m*2.00)<<endl;
else if(n==5) cout<<"Total: R$ "<<fixed<<(double)(m*1.50)<<endl;

return 0;
}
