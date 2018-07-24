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
    while(cin>>n>>m){
        vector<vector<int>> a(n, vector<int>(n, m));
        vector<int> b;
        FORM(n,m){
            int k;
            cin>>k;
            a[i][j]=k;
            if(k==42){
                b.pb(i);
                b.pb(j);
            }
        }
        vector<int> r;
        for(int k=b.size(); k; k=b.size()){
            int lin=b[0], col=b[1];
            if(!lin || !col || lin == n-1 || col == n-1){
                b.erase(b.begin());
                b.erase(b.begin());   
            }
            else{
                if(a[lin][col-1]==7 && a[lin][col+1]==7 && a[lin-1][col]==7 && a[lin+1][col]==7){
                    r.pb(lin);
                    r.pb(col);
                    b=r;
                    break;
                }
                else{
                    b.erase(b.begin());
                    b.erase(b.begin()); 
                }
            }
        }
        cout<<b[0]<<" "<<b[1]<<endl;
    }
    return 0;
}
