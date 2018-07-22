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
    int K = 1;
    while(cin>>t){
        int el = 0;
        string s;
        for(int i=0; i<t+1; i++){
            if(i<2){
                s.pb(i+'0');
                if(i!=t)s.pb(' ');
                el++;
            }
            else{
                for(int j=0; j<i; j++){
                    stringstream temp;
                    temp<<i;
                    s+=temp.str();
                    s.pb(' ');
                    el++; 
                }
            }
        }
        if(!isdigit(s.back())) s.back()='\n';
        else s.pb('\n');
        cout<<"Caso "<<K++<<": "<<el<<" numero";
        if(el>1)cout<<"s";
        cout<<endl;
        cout<<s<<endl;
    }
    return 0;
}
