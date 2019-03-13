//TEMPLATE COM MACROS PARA OS CONTESTS
//compile usando: g++ -std=c++11 -lm -O3 arquivo.cpp
#include <bits/stdc++.h>
#define FOR(x) for(int i=0;i<x;i++)
#define ROF(x) for(int i=x-1;i>=0;i--)
#define ROFJ(x) for(int j=x-1;j>=0;j--)
#define FORJ(x) for(int j=0;j<x;j++)
#define FORQ(Q) for(int i=0;Q;i++)
#define FORM(x,y) for(int i=0;i<x;i++) for(int j=0;j<y;j++)
#define FORT(x,y) for(int i=x;i<y;i++)
#define ROFT(x,y) for(int i=x-1;i>=y;i--)
#define WHILE(n,x) while((n--)&&cin>>x)
#define SORT(v) sort(v.begin(), v.end())
#define SORTC(v, comp) sort(v.begin(), v.end(), comp)
#define FORIT(v) for(auto& it: v)
#define c(x) cout<<x<<endl
#define C(x) cin>>x
#define set(a,b) cout.precision(a); cout<<fixed<<b<<endl
#define pcs(a) cout.precision(a)
#define fx(a) fixed<<a
#define gl(s) getline(cin,s)
#define pb(a) push_back(a)
#define matrixM(n,m) vector<vector<int>> M (n, vector<int> (m))
#define matrixN(n,m) vector<vector<int>> N (n, vector<int> (m))

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<string> vstr;
typedef vector<double> vd;
typedef vector<long> vl;
typedef vector<ll> vll;
typedef map<int, int> mii;
typedef map<int, bool> mib;
typedef map<char, int> mci;
typedef map<string, int> msi;
typedef pair<int, int> pii;

struct carta{
	char naipe;
	int v;
};

struct player{
	int id;
	map<int, map<char, char, greater<char>>, greater<int>> mao;
	carta busca(carta& d){
		carta ans;
		ans.v=-1;
		auto buscav = mao.lower_bound(d.v);
		if(buscav != mao.end() and buscav->first == d.v){ // ACHOU POR VALOR
			ans.v=buscav->first;
			ans.naipe=buscav->second.begin()->first;
			buscav->second.erase(buscav->second.begin());
			if(buscav->second.empty()) mao.erase(buscav);
		}
		else{ //BUSCA POR NAIPE
			int exc=-1;
			for(auto it: mao){
				auto buscan = it.second.lower_bound(d.naipe);
				if(buscan != it.second.end() and buscan->first == d.naipe){ //ACHOU O NAIPE
					ans.v=it.first;
					ans.naipe=buscan->first;
					it.second.erase(buscan);
					if(it.second.empty()) exc=it.first;
					break;
				}
			}
			if(exc!=-1) mao.erase(exc);
		}
		return ans;
	}
};

int main(){
    int p,m,n,np,ans;
    carta tmp,d;
    player tmp2;
    list<player>::iterator at, fw, bw;
    bool tentou,ah;
    while(cin>>p>>m>>n and p+m+n){
    	list<player> jogo;
    	queue<carta> cava;
    	carta descarte;
    	FOR(p){
    		tmp2.id=i+1;
    		tmp2.mao.clear();
    		FORJ(m){
    			cin>>tmp.v>>tmp.naipe;
    			tmp2.mao[tmp.v][tmp.naipe];
    			n--;
    		}
    		jogo.pb(tmp2);
    	}
    	cin>>descarte.v>>descarte.naipe;
    	n--;
    	while(n--){
    		cin>>tmp.v>>tmp.naipe;
    		cava.push(tmp);
    	}
    	// cout<<jogo.size()<<endl;
    	//FIM DA ENTRADA
    	//INICIO DO JOGO
    	at=jogo.begin();
    	/*for(auto it: at->mao){
    		cout<<it.first<<endl;
    	}*/
    	tentou=ah=np=0;
    	while(true){
    		if(!np) tmp=at->busca(descarte);
    		else{
				tmp.v=-1;
				if(!(np+tentou)) np=1;
			}
    		if(tmp.v!=-1){ // ACHOU
    		    if(at->mao.empty()){
    				ans=at->id;
    				break;
    			}
    			descarte=tmp;
				// cout<<descarte.v<<' '<<descarte.naipe<<endl;
    			switch(descarte.v){
    				case 12:
    					ah=!ah;
						np=tentou=0;
    					break;
    				case 7:
    					np=2;
    					tentou=1;
    					break;
    				case 1:
    					np=1;
    					tentou=1;
    					break;
    				case 11:
    					np=3;
    					tentou=1;
    					break;
    				default:
						np=tentou=0;
						break;
    			}
    		}
    		else{ // CAVA
    			if(np==3) np=0;
    		    while(np--){
	    		    tmp=cava.front();
	    			cava.pop();
	    			at->mao[tmp.v][tmp.naipe];
    		    }
				np=0;
    			if(!tentou){
    				tentou=1;
    				continue;
    			}
				tentou=0;
    		}
    		if(!ah){
    			at++;
    			if(at==jogo.end()) at++;
    		}
    		else{
    			at--;
    			if(at==jogo.end()) at--;
    		}
    	}
    	cout<<ans<<endl;
    }
    return 0;
}