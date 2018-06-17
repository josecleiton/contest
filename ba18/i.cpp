#include <bits/stdc++.h>
#define FOR(a) for(int i=0;i<a;i++)
#define C(a) cin>>a

using namespace std;

int main(){
int q,n,a,b;
char c;
string s;
cin>>q>>n;
vector<pair<int,int>> v;
C(s);
FOR(n){
	cin>>a>>b;
	v.push_back(make_pair(a,b));
}
FOR(n){
	swap(s[v[(n-1)-i].first-1], s[v[(n-1)-i].second-1]);
}
cout<<s<<endl;
return 0;
}
