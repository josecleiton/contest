//TEMPLATE COM MACROS PARA OS CONTESTS
//compile usando: g++ -std=c++11 -lm -O3 arquivo.cpp
//https://www.urionlinejudge.com.br/judge/pt/problems/view/1091
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

int main(){

int n,m,k=-1,x,y;
while(k){
    C(k);
    if (k){
        cin>>n>>m;
        FOR(k){
            cin>>x>>y;
            if (x==n || y==m) c("divisa");
            else if (n-x>0){
                if(m-y<0) c("NO");
                else c("SO");
            }
            else if(n-x<0){
                if(m-y<0) c("NE");
                else c("SE");
            }
        }
    }
}
return 0;
}
