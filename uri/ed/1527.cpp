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

int main(){
    int n,m,l,p,q,a,b,ans;
    unordered_map<int, unordered_map<int, int>>::iterator gr[2],r;
    while(cin>>n>>m and n+m){
        ans=0;
        unordered_map<int, unordered_map<int, int>> guildas;
        FOR(n){
            cin>>p;
            guildas[i+1][i+1]=p;
        }
        while(m--){
            cin>>q>>a>>b;
            int j=0;
            gr[0]=gr[1]=r=guildas.end();
            for(auto g=guildas.begin(); g!=guildas.end() and gr[1]==guildas.end(); g++){
                for(auto it: g->second){
                    if(it.first==1) r=g;
                    if(it.first==a or it.first==b){
                        gr[j++]=g;
                    }
                }
            }
            if(q==1){
                for(auto it: gr[1]->second){
                    gr[0]->second[it.first]=it.second;
                }
                guildas.erase(gr[1]);
            }
            else{
                int ac[2];
                ac[0]=ac[1]=0;
                FOR(2){
                    for(auto it: gr[i]->second){
                        ac[i]+=it.second;
                    }
                }
                if(ac[0]>ac[1] and gr[0]==r) ans++;
                else if(ac[1]>ac[0] and gr[1]==r) ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
