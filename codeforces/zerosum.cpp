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
#define matrixM(n,m) vector<vector<char>> M (n, vector<char> (m))
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

void subarray(vector<ll>& arr, ll n){ 
    unordered_map<ll, int> imap;
    map<int, int> summap;
    ll sum = 0ll; 
    FOR(n){ 
        sum+=arr[i];
        if(!arr[i]){
            cout<<i+1<<" 1"<<endl;
            return;
        }
        else if(imap.find(sum) != imap.end())
            summap[i+1-imap[sum]] = (imap[sum]+1);
        else if(!sum)
            summap[i+1] = 1;
        imap[sum] = i+1;
    }
    if(!summap.empty()){
        auto it = summap.begin();
        cout<<it->second<<' '<<it->first<<endl;
    }
    else cout<<-1<<endl;
} 

int main(){
    int n,m;
    vector<ll> arr(200050);
    while(cin>>n){
        FOR(n) cin>>arr[i];
        subarray(arr, n);
    }
}