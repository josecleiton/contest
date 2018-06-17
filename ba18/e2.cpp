#include <bits/stdc++.h>
#define FOR(a) for(int i=0;i<a;i++)
#define C(a) cin>>a
#define PI 3.141592
using namespace std;

int main(){
int n,a,b,c,r,ret;
int s=0;
double vol=0.0f,q;
double cub=0.0f;
cin>>n>>a>>b>>c;
ret=a*b;
ret=ret*c;
printf("ret %d\n\n",ret);
FOR(n){
	cin>>r;
	cub=pow(r,3)*((double)4/(double)3)*3.141592;
	vol+=cub;
	if(vol>=ret){
	s+=vol/ret;
	vol=vol-ret*s;	
	}
}
	cout<<s<<endl;

return 0;
}
