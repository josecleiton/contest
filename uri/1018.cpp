//TEMPLATE COM MACROS PARA OS CONTESTS
//compile usando: g++ -std=c++11 -lm -O3 1010.cpp
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
int n;
cin>>n;
cout<<n<<endl;
cout<<n/100<<" nota(s) de R$ 100,00"<<endl;
n%=100;
cout<<n/50<<" nota(s) de R$ 50,00"<<endl;
n%=50;
cout<<n/20<<" nota(s) de R$ 20,00"<<endl;
n%=20;
cout<<n/10<<" nota(s) de R$ 10,00"<<endl;
n%=10;
cout<<n/5<<" nota(s) de R$ 5,00"<<endl;
n%=5;
cout<<n/2<<" nota(s) de R$ 2,00"<<endl;
n%=2;
cout<<n<<" nota(s) de R$ 1,00"<<endl;



return 0;
}