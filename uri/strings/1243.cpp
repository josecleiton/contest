#include <bits/stdc++.h>
#define pb push_back
using namespace std;

int main() {
	int j,k;
	int p,d,tam;
	string s;
	while(getline(cin, s)){
		list<int> cm;
		p=d=j=0;
		for(int i=0; i<=s.size(); i++){
			if(s[i]=='.'){
				p++;
			}
			else if(isdigit(s[i])) d=1;
			else if(s[i]==' ' or !s[i]){
				if(i-j){
					if(p==1 and s[i-1]=='.' and i-j>1){
						p=0;
						j++;
					}
					if(!(p+d)) cm.pb(i-j);
				}
				j=i+1;
				p=d=0;
			}
		}
		tam=cm.size();
		if(tam==0) tam=1;
		k=accumulate(cm.begin(), cm.end(), 0)/tam;
		if(k<=3) cout<<"250";
		else if(k<=5) cout<<"500";
		else cout<<"1000";
		cout<<endl;
	}
	return 0;
}