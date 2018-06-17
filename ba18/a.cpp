#include <bits/stdc++.h>
#define FOR(a) for(int i=0;i<a;i++)
#define C(a) cin>>a

using namespace std;

int main(){

int n, a, b, s=0;
C(n);
FOR(n){
	cin>>a>>b;
	s=s+a*b;
}
printf("%d\n",s);
return 0;
}
