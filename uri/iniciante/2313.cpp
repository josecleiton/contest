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
typedef long long ll;
typedef unsigned long long ull;

bool vale (int a,int b, int c){
    return (abs(b-c)<a && a<b+c);
}

bool ret (int a,int b,int c){
    return (a*a==b*b+c*c);
}

int main(){
    long long a,b,c;
    bool v=false;
    while(cin>>a>>b>>c){
        if(vale(a,b,c) && vale(b,a,c) && vale(c,a,b)){
            v=true;
            cout<<"Valido-";
            if(a==b and b==c) cout<<"Equilatero";
            else if (a==b or b==c or c==a) cout<<"Isoceles";
            else cout<<"Escaleno";
            cout<<endl;
            if(ret(a,b,c) or ret(b,a,c) or ret(c,a,b)) cout<<"Retangulo: S"<<endl;
            else cout<<"Retangulo: N"<<endl;
        }
        else cout<<"Invalido"<<endl;
    }
    return 0;
}
