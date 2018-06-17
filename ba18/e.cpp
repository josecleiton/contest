#include <bits/stdc++.h>
#define FOR(a) for(int i=0;i<a;i++)
#define C(a) cin>>a
#define PI 3.141592
using namespace std;

int main(){
int n,a,b,c,r,ret,s=0;
long double vol=0;
cin>>n>>a>>b>>c;
ret=a*b*c;
FOR(n){
	cin>>r;
	vol=vol+(pow(r,3)*4*3.14159)/3;
	while(vol>=ret){
		s++;
		vol-=ret;
	}
}
cout<<s<<endl;
return 0;
}
