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
typedef vector<string> vs;
typedef vector<double> vd;
typedef vector<long> vl;
typedef vector<ll> vll;

int main(){
    int n,c;
    string d,s,av;
    while(cin>>c>>n){
        cin.ignore(1);
        getline(cin,d);
        getline(cin,s);
        FOR(n){
            getline(cin,av);
            FOR(av.size()){
                for(int j=0; j<c; j++){
                    if(av[i]==s[j]){
                        if(isalpha(av[i]))av[i]=d[j];
                        else av[i]=tolower(d[j]);
                        break;
                    }
                    else{
                        if (av[i] == tolower(s[j])){
                            av[i] = tolower(d[j]);
                            break;
                        }
                    }
                    if(av[i]==d[j]){
                        if(isalpha(av[i]))av[i]=s[j];
                        else av[i]=tolower(s[j]);
                        break;
                    }
                    else{
                        if(av[i]==tolower(d[j])){
                            av[i]=tolower(s[j]);
                            break;
                        }
                    }
                }
            }
            cout<<av<<endl;
        }
        cout<<endl;
    }
    return 0;
}
