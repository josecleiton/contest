//TEMPLATE COM MACROS PARA OS CONTESTS
//compile usando: g++ -std=c++11 -lm -O3 arquivo.cpp
#include <bits/stdc++.h>
#define FOR(x) for(int i=0;i<x;i++)
#define ROF(x) for(int i=x-1;i>=0;i--)
#define ROFJ(x) for(int j=x-1;j>=0;j--)
#define FORJ(x) for(int j=0;j<x;j++)
#define FORQ(Q) for(int i=0;Q;i++)
#define FORM(x,y) for(int i=0;i<x;i++) for(int j=0;j<y;j++)
#define FORT(x,y) for(int i=x;i<y;i++)
#define ROFT(x,y) for(int i=x-1;i>=y;i--)
#define WHILE(n,x) while((n--)&&cin>>x)
#define SORT(v) sort(v.begin(), v.end())
#define SORTC(v, comp) sort(v.begin(), v.end(), comp)
#define FORIT(v) for(auto& it: v)
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
typedef map<int, int> mii;
typedef map<int, bool> mib;
typedef map<char, int> mci;
typedef map<string, int> msi;
typedef pair<int, int> pii;

ll op(ll n, int i){
    switch(i){
        case 1:
            return n*2;
        case 2:
            return n*3;
        case 3:
            return n/2;
        case 4:
            return n/3;
        case 5:
            return n+7;
        case 6:
            return n-7;
    }
}

ll height(const ll n){
    return (ll) ceil(log(n)/log(6)-1);
}

ll bfs(const ll n, const ll m){
    queue<pair<ll, ll>> q;
    q.push(make_pair(-1, n));
    pair<ll, ll> front;
    register ll h, ins=0;
    while(!q.empty()){
        front = q.front();
        if(front.second == m)
            return front.first+1;
        if(front.second <= 200000){
            for(int i=1; i<=6; i++){
                h = height(++ins);
                q.push(make_pair(h, op(front.second, i)));
            }
        }
        else ins+=6;
        q.pop();
    }

    return numeric_limits<ll>::max();

}

int main(){
    ll n,m,l;
    while(cin>>n>>m){
        cout << bfs(n,m) << endl;
    }
    return 0;
}
