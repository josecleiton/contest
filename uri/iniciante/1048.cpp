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

using namespace std;
int main(){
double s,r,p;
C(s);
if(s>=0 and s<=400){
    p=15/(double)100;
    r=s*p;
    s+=r;
}
else if(s>400 and s<=800){
    p=12/(double)100;
    r=s*p;
    s+=r;
}
else if(s>800 and s<=1200){
    p=10/(double)100;
    r=s*p;
    s+=r;
}
else if(s>1200 and s<=2000){
    p=7/(double)100;
    r=s*p;
    s+=r;
}
else{
    p=4/(double)100;
    r=s*p;
    s+=r;
}
p*=100;
cout.precision(2);
cout<<"Novo salario: "<<fx(s)<<endl<<"Reajuste ganho: "<<fx(r)<<endl;
pcs(0);
cout<<"Em percentual: "<<fx(p)<<" %"<<endl;
return 0;
}
