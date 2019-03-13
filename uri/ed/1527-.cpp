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

struct player{
    int p;
    int id;
};

int main(){
    int n,m,q,a,b,ans,tmp;
    player temp;
    unordered_map<int, list<player>>::iterator rafael, search[2];
    unsigned p[2];
    while(cin>>n>>m and n+m){
        unordered_map<int, list<player>> jogo;
        ans=0;
        FOR(n){
            cin>>temp.p;
            temp.id=i+1;
            jogo[i].push_back(temp);
        }
        while(m--){
            cin>>q>>a>>b;
            
            rafael=search[0]=search[1]=jogo.end(); 
            int j=0;
            for(auto key=jogo.begin(); key!=jogo.end() and j!=2; key++){
                for(auto it=key->second.begin(); it!=key->second.end(); it++){
                    if(it->id==1) rafael=key;
                    if(it->id==a or it->id==b){
                        search[j++]=key;
                    }
                }
            }
            if(q==1){
                for(auto& it: search[1]->second)
                    search[0]->second.push_back(it);
                jogo.erase(search[1]);
            }
            else if(search[0]!=jogo.end() and search[1]!=jogo.end()){
                p[0]=p[1]=0;
                FOR(2){
                    for(auto it: search[i]->second){
                        p[i]+=it.p;
                    }
                }
                if((p[0]>p[1] and rafael==search[0]) or (p[1]>p[0] and rafael==search[1])) ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
