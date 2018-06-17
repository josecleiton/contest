#include <bits/stdc++.h>
#define FOR(a,b) for(int i=a; i<b; i++)
#define FOR2(a,b) for(int i=a-1; i>=b; i--)
#define C(a) cin>>a
using namespace std;
int main(){

int n,m,t;
string s;
C(n);
cin.ignore(1);
FOR(0, n){
    getline(cin,s);
    m=s.length();
    FOR(0, m){
        if(isalpha(s[i])) 
            s[i]+=3;
    }
    FOR(0, m/2){
      t=s[i];
      s[i]=s[m-i-1];
      s[m-1-i]=t;
    }
    FOR(m/2, m)
        s[i]-=1;
    cout<<s<<endl;
}


return 0;
}
