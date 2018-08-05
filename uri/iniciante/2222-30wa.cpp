#include <bits/stdc++.h>
#define FOR(x) for(int i=0;i<x;i++)

using namespace std;

typedef unsigned long ul;

int intuni (ul a, ul b, int op){
    int i = 0;
    ul c=0L;
    if(op==1) c=a&b;
    else c=a|b;
    while(c){
        i+=c&1;
        c>>=1;
    }
    return i;
}

int main(){
    int n,m,l,op,a,b,c;
    vector<ul> v;
    ul k;
    cin>>n;
    FOR(n){
        cin>>m;
        v.resize(m);
        FOR(m){
            cin>>l;
            for(int j=0; j<l; j++){
                cin>>k;
                k=1<<(k-1);
                v[i]|=k;
            }
        }
        cin>>c;
        FOR(c){
            cin>>op>>a>>b;
            cout<<intuni(v[a-1],v[b-1],op)<<endl;
        }
    }
    return 0;
}