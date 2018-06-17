#include <bits/stdc++.h>
#define FOR(a) for(int i=0;i<a;i++)
#define C(a) cin>>a
using namespace std;

int main(){
int n, a, b, g, f=0;
cin>>n>>a>>b;
FOR (n){
	cin>>g;
	if (g < 45)
		printf("%d %d\n", g,1);
	
	else if (g>=45&&g<45+a)
		printf("-1\n");
		else printf("%d 2\n", g-45);
}

return 0;
}
