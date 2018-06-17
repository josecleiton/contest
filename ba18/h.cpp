#include <bits/stdc++.h>
#define FOR(a) for(int i=0;i<a;i++)
#define C(a) cin>>a
bool compare(int& x, int&y){return x>y;}
using namespace std;

int main(){
int n,a,b,m,s,ax,t;
vector<int> v;
priority_queue<int> p;
cin>>a>>b;
v.resize(a);
FOR(a){
	cin>>m;
	p.push(m);
}
for(int i=a-1;i>=0;i--){ 
	v[i] = p.top();
	p.pop();
	
}
FOR(b){
	cin>>m;
	s=0;
	t=0;
	for(int j=0;j<a && t<m;j++){
		t += v[j];
		s++;	
	}
	if(t>m) cout<<s-1<<endl;
	else cout<<s<<endl;
}
return 0;
}
