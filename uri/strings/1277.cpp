#include <bits/stdc++.h>
#define pb push_back
using namespace std;

struct est{
	string name;
	int m, p, t;
};

int main() {
	int t,n,p,j;
	string st;
	vector<est> v(110);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=0; i<n; i++){
			cin>>v[i].name;
		}
		for(int i=0; i<n; i++){
			v[i].m=v[i].p=v[i].t=0;
			cin>>st;
			for(auto c: st){
				if(c=='P') v[i].p++;
				else if(c=='M') v[i].m++;
				v[i].t++;
			}
		}
		j=0;
		for(int i=0; i<n; i++){
			if(!(v[i].t-v[i].m)){
				v[i].p=v[i].t;
				v[i].m=0;
			}
			if(v[i].p/((double)(v[i].t-v[i].m)) < 0.75){
				if(j++) cout<<' ';
				cout<<v[i].name;
			}
		}
		cout<<endl;
	}
	return 0;
}