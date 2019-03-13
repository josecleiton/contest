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
    int v;
    char naipe;
};

struct player{
    int id;
    map<int, map<char, char, greater<char>>, greater<int>> mao;
    carta busca_mao(const carta& d){
        carta ans;
        ans.v=-1;
        map<int, map<char, char, greater<char>>>::iterator exc=mao.end();
        map<char, char>::iterator buscan;
        for(auto it=mao.begin(); it!=exc; it++){
            if(it->first != d.v){
                buscan=it->second.lower_bound(d.naipe);
                if(buscan != it->second.end() and buscan->first == d.naipe){ //ACHOU O NAIPE
                    ans.v=it->first;
                    ans.naipe=buscan->first;
                    it->second.erase(buscan);
                    if(it->second.empty())
                        exc=it;
                    break;
                }
            }
            else{
                ans.v=it->first;
                buscan=it->second.begin();
                ans.naipe=buscan->first;
                it->second.erase(buscan);
                if(it->second.empty())
                    exc=it;
                break;
            }
        }
        if(exc!=mao.end())
            mao.erase(exc);
        return ans;
    }
};

void punicao(const int& v, int& np, bool& tentou, bool& ah){
    if(v==12){
        ah=!ah;
        np=tentou=0;
    }
    else if(v==7){
        np=2;
        tentou=1;
    }
    else if(v==1){
        np=tentou=1;
    }
    else if(v==11){
        np=3;
        tentou=0;
    }
    else{
        np=tentou=0;
    }
}

int main(){
    int p,m,n,np,ans;
    carta tmp,descarte;
    player tmp2;
    list<player>::iterator at;
    bool tentou,ah;
    while(cin>>p>>m>>n and p+m+n){
        list<player> jogo;
        queue<carta> cava;
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
        while(n){
            cin>>tmp.v>>tmp.naipe;
            cava.push(tmp);
            n--;
        }
        //FIM DA ENTRADA
        //INICIO DO JOGO
        at=jogo.begin();
        np=tentou=ah=0;
        punicao(descarte.v, np, tentou, ah);
        while(true){
            if(!np){
                tmp=at->busca_mao(descarte);
                tentou=0;
                if(tmp.v==-1) np=1;
            }
            else{
                tmp.v=-1;
                //if(!(np+tentou)) np=1;
            }
            if(tmp.v!=-1){ // ACHOU
                if(at->mao.empty()){
                    ans=at->id;
                    break;
                }
                descarte=tmp;
                punicao(descarte.v, np, tentou, ah);
            }
            else{ // CAVA
                if(np!=3){ // SE NP==3 ELE N CAVA, MAS PERDE A VEZ
	                while(np){
	                    tmp=cava.front();
	                    cava.pop();
                        if(tentou)
                            at->mao[tmp.v][tmp.naipe];
                        np--;
	                }
	                if(!tentou){
	                    if(tmp.v==descarte.v or tmp.naipe==descarte.naipe){
	                        descarte=tmp;
	                        punicao(descarte.v, np, tentou, ah);
	                    }
	                    else at->mao[tmp.v][tmp.naipe];
	                }
                }
                else np=0;
            }
            if(!ah){ // SENTIDO HORARIO
                at++;
                if(at==jogo.end()) at++;
            }
            else{ // SENTIDO ANTIHORARIO
                at--;
                if(at==jogo.end()) at--;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
