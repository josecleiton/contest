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

bool compare(const string& a, const string& b){
    return a.size() > b.size();
}

void count(vector<string>& array){
    int tam = array.size();
    vector<string> result(tam);
    const int BUCKETSIZE = 50;
    vector<vector<string> > buckets(BUCKETSIZE);
    int kdigit;
    for(int i=0; i<tam; i++){
        kdigit = array[i].size();
        buckets[kdigit-1].push_back(array[i]);
    }
    int k=0;
    FORJ(BUCKETSIZE)
        ROF(buckets[j].size())
            result[k++] = buckets[j][i];

    ROF(tam){
        cout<<result[i];
        if(i>0) cout<<' ';
    }
    cout<<endl;
}

int main(){
    int n;
    cin>>n;
    cin.ignore();
    stringstream ss;
    string h;
    FOR(n){
        vector<string> vst;
        getline(cin, h);
        ss.str(h);
        while(ss.good()){
            ss >> h;
            vst.push_back(h);
        }
        ss.clear();
        count(vst);
    }
    return 0;
}
