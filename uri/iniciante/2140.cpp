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
    int n,m;
    bool p;
    vector<int> v={2,5,10,20,50,100};
    vector<string> r={"impossible","possible"};
    while(cin>>n>>m){
        if(!n&&!m) break;
        p=false;
        int z = abs(n-m);
        for(int i = 0; i<v.size(); i++){
            for(int j=0; j<v.size(); j++){
                if(v[i]+v[j]==z){ p = true; break; }
            }
            if(p) break;
        }
        cout<<r[p]<<endl;
    }
    return 0;
}
