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
#define M(x,y) max(x, y)
#define m(x,y) min(x, y)
#define c(x) cout<<x<<endl
#define C(x) cin>>x
#define set(a,b) cout.precision(a); cout<<fixed<<b<<endl
#define pcs(a) cout.precision(a)
#define fx(a) fixed<<a
#define gl(s) getline(cin,s)
#define pb(a) push_back(a)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int main(){
    int t;
    vector<vector<long>> v(50, vector<long>(3));
    vector<bool> r(4);
    long a,b,c;
    char h;
    string s;
    while(cin>>t){
        FOR(t){
            cin>>a>>b;
            v[i][0]=a;
            v[i][1]=b;
            cin.ignore(1);
            cin>>c;
            v[i][2]=c;
        }
        vector<string> resp;
        FOR(t){
            FOR(4) r[i]=false;
            cin>>s>>a;
            cin.ignore(1);
            cin>>h;

            if(v[a-1][0]+v[a-1][1] == v[a-1][2]) r[0]=true;
            else if (v[a-1][0]-v[a-1][1] == v[a-1][2]) r[1]=true;
            else if (v[a-1][0]*v[a-1][1] == v[a-1][2]) r[2] = true;
            else r[3] = true;

            if(h=='+' and !r[0])resp.pb(s);
            else if (h=='-' and !r[1])resp.pb(s);
            else if (h=='*' and !r[2])resp.pb(s);
            else if (h=='I' and !r[3]) resp.pb(s);
        }
        if(resp.size()==t) cout<<"None Shall Pass!"<<endl;
        else if(!resp.size()) cout<<"You Shall All Pass!"<<endl;
        else{
            sort(resp.begin(),resp.end());
            FOR(resp.size()){
                cout<<resp[i];
                if(i!=resp.size()-1) cout<<' ';
            }
            cout<<endl;
        }
    }
    return 0;
}
