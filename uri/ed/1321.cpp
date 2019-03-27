//TEMPLATE COM MACROS PARA OS CONTESTS
//compile usando: g++ -std=c++11 -lm -O3 arquivo.cpp
#include <bits/stdc++.h>
#define FORM(x,y) for(int i=0;i<x;i++) for(int j=0;j<y;j++)
#define SORT(v) sort(v.begin(), v.end())
#define SORTC(v, comp) sort(v.begin(), v.end(), comp)
#define set(a,b) cout.precision(a); cout<<fixed<<b<<endl
#define pcs(a) cout.precision(a)
#define fx(a) fixed<<a
#define FOR(i,a) for(int i=0; i<a; i++)
#define FORIT(it, c) for(auto it = c.begin(); it != c.end(); it++)
#define pb push_back
#define MAP(t1, t2, ord) map<t1, t2, ord<t1>>
#define UMAP(t1, t2) unordered_map<t1, t2>
#define matrix(name, type, n, m) vector<vector<type>> name (n, vector<type> (m))
#define PQ(name, type, ord) priority_queu<type, deque<type>, ord<type>> name
using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<string> vstr;
typedef vector<bool> vbit;
typedef pair<ll, ll> pii;
typedef vector<double> vd;

int jollo(vector<bool>& a, vector<bool>& o) {

}

int main(){
    ll t,n,m,l;
    vector<bool> p_a(52), p_e(52);
    while(true){
        n=0;

        FOR(i, 3) {
            cin>>t;
            p_a[t-1] = 1;
            n+=t;
        }
        
        FOR(i, 2) {
            cin>>t;
            p_e[t-1] = 1;
            n+=t;
        }

        if(n) cout<<jollo(p_a, p_e)<<endl;
        else break;
    }
    return 0;
}
