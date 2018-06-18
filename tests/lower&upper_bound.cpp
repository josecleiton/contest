#include <bits/stdc++.h>
#define FOR(x) for(int i=0;i<x;i++)
#define FORJ(x) for(int j=0;j<x;j++)
#define FORQ(Q) for(int i=0;Q;i++)
#define FORM(x,y) for(int i=0;i<x;i++) for(int j=0;j<y;j++)
#define FORT(x,y) for(int i=x;i<y;i++)
#define WHILE(n,x) while((n--)&&cin>>x)
#define M(x,y) max(x, y)
#define m(x,y) min(x, y)
#define c(x) cout<<x<<endl

using namespace std;

int main()
{
    long long int n, q, b=0, ax=0, s=0;
    vector<int> a = {1,2,4,5,7,10,11};
    auto i = lower_bound(a.begin(), a.end(), 7); //iterator para o igual ou maior mais proximo
    c((*i));
    i = upper_bound(a.begin(), a.end(), 7);//iterator para o maior mais proximo
    c((*i));
    return 0;
}

