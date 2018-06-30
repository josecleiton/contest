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
#define PI 3.14159

using namespace std;

int main(){
double a,b,c;
cin>>a>>b>>c;
double v[5];
v[0] = (a*c)/2;
v[1] = (PI*c*c);
v[2] = (c*(a+b))/2;
v[3] = b*b;
v[4] = a*b;
cout.precision(3);
cout<<"TRIANGULO: "<<fixed<<v[0]<<endl<<"CIRCULO: "<<fixed<<v[1]<<endl<<"TRAPEZIO: "<<fixed<<v[2]<<endl<<"QUADRADO: "<<fixed<<v[3]<<endl<<"RETANGULO: "<<fixed<<v[4]<<endl;


return 0;
}