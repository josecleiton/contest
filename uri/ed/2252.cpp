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
#define PQ(name, type, ord) priority_queue<type, deque<type>, ord<type>> name
using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<string> vstr;
typedef vector<bool> vbit;
typedef pair<ll, ll> pii;
typedef vector<double> vd;

class Cmp {
public:
    bool operator()(const pair<double, int>& a, const pair<double, int>& b) {
        if(a.first > b.first)
            return false;
        else if(a.first == b.first)
            return a.second >= b.second;
        return true;
    }
};

int main(){
    ll t,n=1,l;
    double m;
    while(cin>>t){
        //if(n++) cout<<endl;
        priority_queue<pair<double, int>, vector<pair<double, int>>, Cmp> pq;
        FOR(i, 10) {
            cin>>m;
            pq.push(make_pair(m, i));
        }
        cout<<"Caso "<<n<<": ";
        FOR(i, t){
            cout<<pq.top().second;
            pq.pop();
        }
        cout<<endl;
        n++;
    }
    return 0;
}
