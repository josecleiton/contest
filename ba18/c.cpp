#include <bits/stdc++.h>
#define FOR(a) for(int i=0;i<a;i++)
#define C(a) cin>>a
using namespace std;

int main(){
long long int s=0,n,t=0;
long long int ac=0,x;
cin>>n;
int v[n];
FOR(n){
	C(v[i]);
	ac+=v[i];	
}x=0;
FOR(n){
	ac-=v[i];
	t+=v[i]*(x+ac);
	x+=v[i];
}
printf("%d\n", t);
return 0;
}
