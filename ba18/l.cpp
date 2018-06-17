#include <bits/stdc++.h>
#define FOR(a) for(int i=0;i<a;i++)
#define C(a) cin>>a

using namespace std;

int main(){

string a,b;
int s=0;
cin>>a>>b;
FOR(a.size()){
	if(a[i]!=b[i])	s++;	
}
printf("%d\n",s);
return 0;
}
