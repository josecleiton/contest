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

int idx(char c){
    if(islower(c)) return c-'a';
    else return c-'A'+26;
}

int main(){
    int n,q,index,needle;
    string s,query;
    map<int, vi>::iterator busca;
    bool res;
    cin>>n;
    while(n--){
        map<int, vi> M;
        cin>>s>>q;
        FOR(s.size()) M[s[i]].pb(i);
        while(q--){
            cin>>query;
            res=true;
            FOR(query.size()){
                busca = M.lower_bound(query[i]);
                if(busca != M.end() and busca->first == query[i]){
                    index = idx(query[i]);
                    if(!i){
                        needle=busca->second[0];
                    }
                    else{
                        auto k = upper_bound(busca->second.begin(), busca->second.end(), needle);
                        if(k!=busca->second.end()){
                            needle=*k;
                        }
                        else{
                            res = false;
                            break;
                        }
                    }
                }
                else{
                    res=false;
                    break;
                }
            }
            if(res) cout<<"Yes";
            else cout<<"No";
            cout<<endl;
        }
    }
    return 0;
}
