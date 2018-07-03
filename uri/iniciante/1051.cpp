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
double s,t=0.0f;
C(s);
if(s>=0 && s<=2000) c("Isento");
else{
    pcs(2);
    double h = s;
    h-=2000;
    if(h<=1000) cout<<"R$ "<<fx(h*0.08)<<endl;
    else if(h<=2500){
        t=1000*0.08;
        t+=(h-1000)*0.18;
        cout<<"R$ "<<fx(t)<<endl;
    }
    else{
        t=1000*0.08;
        t+=1500*0.18;
        h-=2500;
        t+=h*0.28;
        cout<<"R$ "<<fx(t)<<endl;
    }
}
return 0;
}
