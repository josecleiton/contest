#include <bits/stdc++.h>
#define FOR(i, k, a) for(int i=k; i<a; i++)
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
	int n,b,c,d;
	bool flag;
	while(cin>>n) {
		flag = 1;
		vector<bool> vet(n-1);
		cin>>b;
		FOR(i, 1, n) {
			cin>>c;
			if(!flag) continue;
			d = abs(b-c);
			if((d > 0 and d < n) and !vet[d-1]){
				vet[d-1] = 1;
			}
			else flag = 0;
			b = c;
		}
		if(flag and accumulate(vet.begin(), vet.end(), 0) == n-1) {
			puts("Jolly");
		}
		else puts("Not jolly");
	}
	return 0;
}
