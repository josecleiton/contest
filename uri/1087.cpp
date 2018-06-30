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

int modulo (int a){

    return (a>=0) ? a : -a;
}

int main(){

int a,b,c,d;
a=b=c=d=-1;
while(a||b||c||d){
    cin>>a>>b>>c>>d;
    if (a||b||c||d){
        if (a==c && b==d) c(0);
        else if ((a==c || b==d) || (a+b==c+d) || (modulo(a-c)==modulo(b-d))) c(1);
        else c(2);
    }
}
return 0;

}
