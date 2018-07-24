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
    int t,m;
    long sum;
    string s;
    while(cin>>t){
        if(!t) break;
        sum=0L;
        FOR(t){
            cin>>m;
            cin.ignore(1);
            getline(cin,s);
            if(s=="suco de laranja")
                sum+=(m*120);
            else if (s=="morango fresco" || s=="mamao")
                sum+=(m*85);
            else if (s=="goiaba vermelha")
                sum+=(m*70);
            else if (s=="manga")
                sum+=(m*56);
            else if (s=="laranja")
                sum+=(m*50);
            else if (s=="brocolis")
                sum+=(m*34);
        }
        if(sum>130){
            cout<<"Menos ";
            sum=sum-130;
        }
        else if (sum<110){
            cout<<"Mais ";
            sum=110-sum;
        }
        cout<<sum<<" mg"<<endl;
    }
    return 0;
}
