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


int main(){
    short t,b,a1,d1,l1,a2,d2,l2;
    int v1,v2;
    while(cin>>t){
        FOR(t){
            cin>>b;
            cin>>a1>>d1>>l1>>a2>>d2>>l2;
            v1=(a1+d1)/2;
            v2=(a2+d2)/2;
            if(!(l1&1)) v1+=b;
            if(!(l2&1)) v2+=b;
            if((v1-v2)>0)
                cout<<"Dabriel"<<endl;
            else if((v1-v2)<0) 
                cout<<"Guarte"<<endl;
            else
                cout<<"Empate"<<endl;
        }
    }
    return 0;
}
