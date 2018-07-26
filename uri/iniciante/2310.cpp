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
#define c(x) cout<<x<<endl
#define C(x) cin>>x
#define set(a,b) cout.precision(a); cout<<fixed<<b
#define pcs(a) cout.precision(a)
#define fx(a) fixed<<a
#define gl(s) getline(cin,s)
#define pb(a) push_back(a)
#define matrixM(n,m) vector<vector<int>> M (n, vector<int> (m))
#define matrixN(n,m) vector<vector<int>> N (n, vector<int> (m))

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<double> vd;
typedef vector<long> vl;
typedef vector<ll> vll;

int main(){
    int n,h;
    string s;
    vd res(3);
    vs x = {
        "Pontos de Saque: ",
        "Pontos de Bloqueio: ",
        "Pontos de Ataque: "
    };
    cout.precision(2);
    while(cin>>n){
        vi v(n);
        vi z(n);
        for(int i=0; i<n*2; i++){
            if(!(i&1)){
                cin>>s;
                for(int j=0; j<3; j++){
                    cin>>h;
                    v[j] += h;
                }
            }
            else{
                for(int j=0; j<3; j++){
                    cin>>h;
                    z[j] += h;
                }
            }
        }
        FOR(3){
            res[i] = (z[i]*100)/(double)v[i];
            cout<<x[i]<<fixed<<res[i]<<" %."<<endl;
        }
        /*
        *   v[j] - 100
        *   z[j] - x
        *   x*v[j] = 100*z[j]
        *   x = (z[j]*100)/v[j]
        */

    }
    return 0;
}
