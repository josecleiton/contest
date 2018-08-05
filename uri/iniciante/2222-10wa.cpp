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

int getUnion(const unordered_set<int>& a, const unordered_set<int>& b)
{
  unordered_set<int> result = a;
  result.insert(b.begin(), b.end());
  return result.size();
}

int getInt(const unordered_set<int>& a, const unordered_set<int>& b)
{
    int sum = 0;
    for(unordered_set<int>::const_iterator it=a.begin(); it!=a.end(); it++){
        for(unordered_set<int>::const_iterator jt=b.begin(); jt!=b.end(); jt++){
            if(*it==*jt) sum++;
        }
    }  
    return sum;  
}

int main(){
    vector<unordered_set<int>> a(60);
    int t,n,k,r;
    int c,d,e;
    cin>>t;
    while(t){
        cin>>n;
        FOR(n){
            cin>>k;
            for(int j=0; j<k; j++){
                cin>>r;
                a[i].insert(r);
            }
        }
        cin>>e;
        FOR(e){
            cin>>r>>c>>d;
            int f;
            if(r==2)
                f = getUnion(a[c-1],a[d-1]);
            else if (r==1)// intersecção
                f = getInt(a[c-1], a[d-1]);
            
            cout<<f<<endl;
        }
        t--;
    }
    return 0;
}


