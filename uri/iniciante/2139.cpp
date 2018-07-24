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
    int m,d;
    vector<int> a = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 25};
    int r = accumulate(a.begin(),a.end(),0);
    while(cin>>m>>d){
        if(m==12){
            if(d==25)cout<<"E natal!"<<endl;
            if(d==24)cout<<"E vespera de natal!"<<endl;
            if(d>25)cout<<"Ja passou!"<<endl;
        }
        else{
            int x=a[m-1]-d;
            for(int i=m; i<a.size(); i++)
                x+=a[i];
            cout<<"Faltam "<<x<<" dias para o natal!"<<endl;
        }
    }
    return 0;
}
