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
#define acc(v,k) accumulate(v.begin(), v.end(), k)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<string> vstr;
typedef vector<double> vd;
typedef vector<long> vl;
typedef vector<ll> vll;

int main(){
    vector<int> t1(2), t2(2), p(2);
    char c;
    int n;
    cin>>n;
    FOR(n){
        p[0] = p[1] = 0;
        FORJ(2){
            if(j==0) scanf("%d %*c %d", &t1[j], &t2[j]);
            else scanf("%d %*c %d", &t2[j], &t1[j]);
            if(t1[j] > t2[j])
                p[0]+=3;
            else{
                if(t1[j] == t2[j]){
                    p[0]++;
                    p[1]++;
                }
                else
                    p[1]+=3;
            }
        }
        if(p[0] > p[1])
            cout << "Time 1\n";
        else if(p[0] < p[1])
            cout << "Time 2\n";
        else{
            int s1 = acc(t1,0) - acc(t2,0);
            int s2 = -s1;
            if(s1 > s2)
                cout << "Time 1\n";
            else if(s1 < s2)
                cout << "Time 2\n";
            else{
                if(t1[1] > t2[0])
                    cout << "Time 1\n";
                else if(t1[1] < t2[0])
                    cout << "Time 2\n";
                else
                    cout << "Penaltis\n";
            }
        }
    }
    return 0;
}
