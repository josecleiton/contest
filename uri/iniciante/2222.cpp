#include <bits/stdc++.h>
#define FOR(x) for(int i=0;i<x;i++)

using namespace std;

int intuni (unsigned long long a, unsigned long long b, int op){
    int i = 0;
    unsigned long long c=0ull;
    if(op==1) c=a&b;
    else c=a|b;
    while(c){
        i+=c&1;
        c>>=1;
    }
    return i;
}

int main(){
    int n,m,op,a,b,q,t;
    vector<unsigned long long> v(10000);
    unsigned long long k;
    cin>>t;
    while(t){
        cin>>n;
        FOR(n){
            v[i]=0ull;
            cin>>m;
            for(int j=0; j<m; j++){
                cin>>k;
                k=1ull<<(k-1);
                v[i]|=k;
            }
        }
        cin>>q;
        FOR(q){
            cin>>op>>a>>b;
            cout<<intuni(v[a-1],v[b-1],op)<<endl;
        }
        t--;
    }
    return 0;
}