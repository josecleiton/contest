//TEMPLATE COM MACROS PARA OS CONTESTS
//compile usando: g++ -std=c++11 -lm -O3 arquivo.cpp
#include <bits/stdc++.h>
#define FOR(x) for(int i=0;i<x;i++)
using namespace std;
int main(){
    int n,m;
    unsigned long sp;
    string arr[55];
    m=0;
    while(cin>>n and n){
        if(m++) cout<<endl;
        sp=0ul;
        FOR(n){
            cin>>arr[i];
            sp=max(arr[i].size(), sp);
        }
        FOR(n){
            m=sp-arr[i].size();
            while(m--) cout<<' ';
            cout<<arr[i]<<endl;
        }
    }
    return 0;
}
