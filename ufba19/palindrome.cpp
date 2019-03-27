//TEMPLATE COM MACROS PARA OS CONTESTS
//compile usando: g++ -std=c++11 -lm -O3 arquivo.cpp
#include <bits/stdc++.h>
#define FORM(x,y) for(int i=0;i<x;i++) for(int j=0;j<y;j++)
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
#define ROF(i, a) for(int i=a-1; i>=0; i--)
using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> vll;
typedef vector<string> vstr;
typedef vector<bool> vbit;
typedef pair<ll, ll> pii;
typedef vector<double> vd;

/*
class Comp {
public:
    bool operator() (const type& a, const type& b) { // COMPARADOR ESTRITO PARA PRIORITY_Q, UMAP ETC
        return true;
    }
}

MODULAR ARITHMETIC
( a + b) % c = ( ( a % c ) + ( b % c ) ) % c
( a * b) % c = ( ( a % c ) * ( b % c ) ) % c
( a – b) % c = ( ( a % c ) – ( b % c ) ) % c

*/

void palin(string& s, ll k) {
    ll resp = 0LL;
    string z;
    for(int i=0; i<s.size(); i+=k) {
        vi freq(10);
        int impar = 0;
        for(int j=i; j<k; j++) {
            freq[s[j]-'0']++;
        }
        for(auto f: freq)
            impar += f&1;
        if(impar > 1)
            continue;
        z = "";
        ll tmp = 0LL;
        FOR(j, freq.size()){
            z+=string(freq[j]>>1, char(i+'0'));
            do {
                tmp++;
            } while(next_permutation(z.begin(), z.end()));
        }
        resp = max(tmp, resp);
    }
    printf("%lld\n", resp);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll t,n,m,l;
    char c;
    cin>>t;
    while(t--) {
        cin>>n;
        string s;
        FOR(i, 10) {
            cin>>c;
            if(c!='0') s.pb(c);
        }
        palin(s, n);
    }
    return 0;
}
