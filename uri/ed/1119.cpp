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

int ndigit(int N){ return floor(log10(N)) + 1; }

int main(){
    int n,m,k, count;
    list<int> lista;
    list<int>::iterator antihorario, horario, temph, tempah, nexth, nextah;
    while(cin>>n>>k>>m and n+k+m){
        FOR(n) lista.insert(lista.end(), i+1);
        horario = lista.begin();
        antihorario = lista.end();
        count = 0;
        while(!lista.empty()){
            if(count) cout<<',';
            FOR(k-1){
                if(horario == lista.end()) horario++;
                horario++;
            }
            FOR(m-1){
                if(antihorario == lista.end()) antihorario--;
                antihorario--;
            }
            if(horario == lista.end()) horario++;
            if(antihorario == lista.end()) antihorario--;
            if(horario != antihorario){
                FOR(3-ndigit(*horario)) cout<<' ';
                cout<<*horario;
                FOR(3-ndigit(*antihorario)) cout<<' ';
                cout<<*antihorario;
                temph = nexth = horario;
                tempah = nextah = antihorario;
                if(++nexth == tempah) horario = ++nexth;
                else horario = nexth;
                if(--nextah == temph) antihorario = --nextah;
                else antihorario = nextah;
                lista.erase(temph);
                lista.erase(tempah);
            }
            else{
                FOR(3-ndigit(*horario)) cout<<' ';
                cout<<*horario;
                temph=horario++;
                lista.erase(temph);
                antihorario--;
            }
            count++;
        }
        cout<<endl;
    }
    return 0;
}
