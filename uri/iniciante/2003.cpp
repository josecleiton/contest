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
    string s;
    while(cin>>s){
        if(s.front()>='7'){
            int lim = 8*60;
            int r = 60;
            FOR(s.length()){
                switch (i){
                    case 0:
                        r+=(s.at(i)-'0')*60;
                        break;
                    case 2:
                        r+=(s.at(i)-'0')*10;
                        break;
                    case 3:
                        r+=(s.at(i)-'0');
                        break;
                }
            }
            cout<<"Atraso maximo: "<<abs(lim-r)<<endl;
        }
        else cout<<"Atraso maximo: 0\n";
    }
    return 0;
}
