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
    vector<int> a;
    cin>>n>>q;
    a.resize(n);
    FOR(n){
        cin>>a[i];  
    }
    sort(a.begin(), a.end());
    for(int i=1; i<n; i++){
        a[i] += a[i-1];
    }
    FOR(q){
        cin>>ax;
        auto it=lower_bound(a.begin(), a.end(), ax);
        int index=it-a.begin();
        //int index=distance(a.begin(),it);
        if(a[index]>ax) c(index);
        else c(index+1);
    }
    return 0;
}

