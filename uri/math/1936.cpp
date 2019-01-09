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
#define set(a,b) cout.precision(a); cout<<fixed<<b<<endl
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
typedef vector<string> vstr;
typedef vector<double> vd;
typedef vector<long> vl;
typedef vector<ll> vll;

static vector<long> v(12, 0);
static vector<long> value(100100, 0);

long fat(long a){
    if(v[a] == 0)
        v[a] = a * fat(a-1);
    return v[a];
}

long resolve(long n){
    if(value[n]) return value[n];
    for(int i = 1; i <= n; i++){
        value[i] = INT_MAX;
        for(auto f: v){
            if(i-f >= 0){
                value[i] = min(value[i], value[i-f]+1);
            }
        }
    }
    return value[n];
}

int main(){
    long n;
    v[0] = v[1] = 1;
    value[0] = 0;
    fat(11);
    while(cin>>n){
        cout << resolve(n) << endl;
    }
    return 0;
}
