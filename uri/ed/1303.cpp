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

struct team{
    ull ptsM, ptsR, insc, v, d, pts;
    team(){
        memset(this, 0 , sizeof(team));
    }
};

bool compare(const team& a, const team& b){
    if(a.pts > b.pts) return true;
    else if(a.pts == b.pts){
        if((a.ptsM/(double)a.ptsR) > (b.ptsM/(double)b.ptsR)) return true;
        else if((a.ptsM/(double)a.ptsR) == (b.ptsM/(double)b.ptsR)){
            if(a.ptsM > b.ptsM) return true;
            else if(a.ptsM == b.ptsM) return a.insc > b.insc;
        }
    }
    return false;
}

int main(){
    int n,m=0,l,x,y,z,w;
    while(cin>>n and n){
        vector<team> times(n);
        if(m) cout<<endl;
        cout<<"Instancia "<<++m<<endl;
        FOR((n*(n-1))/2){
            cin>>x>>y>>z>>w;
            times[x-1].insc=x;
            times[x-1].ptsM+=y;
            times[x-1].ptsR+=w;

            times[z-1].insc=z;
            times[z-1].ptsM+=w;
            times[z-1].ptsR+=y;
            if(y>w){
                times[x-1].v++;
                times[x-1].pts+=2;
                if(times[x-1].ptsR==0) times[x-1].ptsR=times[x-1].pts;
                times[z-1].d++;
                times[z-1].pts++;
            }
            else{
                times[x-1].d++;
                times[x-1].pts++;
                times[z-1].v++;
                times[z-1].pts+=2;
                if(times[z-1].ptsR==0) times[z-1].ptsR=times[z-1].pts;
            }
        }
        sort(times.begin(), times.end(), compare);
        FOR(n){
            cout<<times[i].insc;
            if(i!=n-1) cout<<' ';
        }
        cout<<endl;
    }
    return 0;
}
