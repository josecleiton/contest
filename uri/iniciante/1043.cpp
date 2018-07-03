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

bool triangulo (double a, double b, double c){
    return ((fabs(a-b)<c<a+b) && (fabs(a-c)<b<a+c) && (fabs(c-b)<a<c+b));
}

int main(){

double a,b,c;
cin>>a>>b>>c;
cout.precision(1);
if(a+b>c && b+c>a && a+c>b) cout<<"Perimetro = "<<fixed<<a+b+c<<endl;
else cout<<"Area = "<<fixed<<0.5*(a+b)*c<<endl;
return 0;
}
