// TEMPLATE COM MACROS PARA OS CONTESTS
// compile usando: g++ -std=c++11 -lm -O3 arquivo.cpp
#include <bits/stdc++.h>
#define SET(a, b) cout.precision(a); cout << fixed << b << endl
#define PCS(a) cout.precision(a)
#define FX(a) fixed << a
#define FOR(i, a) for (int i = 0; i < a; i++)
#define PARA(i, k, n) for (int i = k; i < n; i++)
#define ROF(i, a) for (int i = a - 1; i >= 0; i--)
#define FORIT(it, c) for (auto it = c.begin(); it != c.end(); it++)
#define pb emplace_back
#define pf emplace_front
#define pob pop_back
#define pof pop_front
#define MAP(t1, t2, ord) map<t1, t2, ord<t1>>
#define UMAP(t1, t2) unordered_map<t1, t2>
#define MATRIX(name, type, n, m) vector<vector<type>> name(n, vector<type>(m))
#define PQ( type, ord) priority_queue<type, deque<type>, ord<type>>
#define mkp(a, b) make_pair(a, b)
#define TAM

using namespace std;
typedef vector<int> vi;
typedef int64_t ll;
typedef unsigned long long ull;
typedef vector<ll> vll;
typedef vector<string> vstr;
typedef vector<bool> vbit;
typedef pair<ll, ll> pii;
typedef vector<double> vd;
typedef unordered_map<int, unordered_map<int, bool>> _graph;
typedef unordered_map<int, unordered_map<int, int>> _wgraph;

struct player {
	int id;
	map<int, map<char, int, greater<char>>, greater<int>> mao;
	pair<int, char> jogar_carta(const pair<int, char>& descarte) {
		map<char, int, greater<char> >::iterator tmp;
		auto rm = mao.begin();
		bool achou = false;
		pair<int, char> ans;
		FORIT(card_value, mao) {
			if(card_value->first == descarte.first) { // achou por valor
				tmp = card_value->second.begin();
				rm = card_value;
				ans = mkp(descarte.first, tmp->first);
				achou = true;
				if(!(--tmp->second))
          card_value->second.erase(tmp);
				break;
			}
			if((tmp = card_value->second.find(descarte.second)) != card_value->second.end()) {
				// achou por naipe
				ans = mkp(card_value->first, descarte.second);
				rm = card_value;
				achou = true;
				if(!(--tmp->second))
          card_value->second.erase(tmp);
				break;
			}
		}
		if(achou and rm->second.empty()) {
			mao.erase(rm);
		}
		return ans;
	}
};

bool punish(const pair<int,char>& descarte, int& des, bool& jog, bool& tentar, bool& direcao) {
	switch(descarte.first) {
		case 12:
			direcao = !direcao;
		break;
		case 7:
			des = 2;
			tentar = jog = 0;
		break;
		case 1:
			des = 1;
			tentar = jog = 0;
		break;
		case 11:
			tentar = des = jog = 0;
		break;
		default: return false;
	}
  return true;
}

void reset_punish(pair<int,char>& tmp, int& des, bool& jog, bool& tentar) {
	tmp.first = des = 0;
	jog = tentar = 1;
}

enum { HORARIO, ANTIHORARIO };

int main() {
  int p, m, n;
  pair<int, char> descarte, tmp;
  player curr;
  list<player>::iterator atual;
  char naipe;
  int val, des;
  bool direcao, tentar, jog;
  while (scanf("%d%d%d", &p, &m, &n) != EOF and p+m+n) {
  	list<player> game;
  	queue<pair<int, char>> saque;

  	FOR(i, p) {
      curr.id = i+1;
      curr.mao.clear();
  		FOR(j, m) {
  			scanf("%d %c", &tmp.first, &tmp.second);
  			curr.mao[tmp.first][tmp.second]++;
  			n--;
  		}
  		game.pb(curr);
  	}
  	scanf("%d %c", &descarte.first, &descarte.second);
  	n--;
  	while(n--) {
  		scanf("%d %c", &tmp.first, &tmp.second);
  		saque.push(tmp);
  	}
  	// AQUI O JOGO COMEÇA
    direcao = HORARIO;
    reset_punish(tmp, des, jog, tentar);
  	punish(descarte, des, jog, tentar, direcao);
  	atual = game.begin();
  	while(true) {
  		if(jog) {
  			tmp = atual->jogar_carta(descarte);
  		}
      if(tmp.first) {
	  		if(atual->mao.empty()){
	  			printf("%d\n", atual->id);
	  			break;
	  		}
  			descarte = tmp;
  			if(!punish(descarte, des, jog, tentar, direcao)) {
          reset_punish(tmp, des, jog, tentar);
        } else tmp.first = 0;
  		} else {
  			if(tentar) {
  				tmp = saque.front();
  				saque.pop();
  				if(tmp.first == descarte.first or tmp.second == descarte.second) {
  					descarte = tmp;
            if(!punish(descarte, des, jog, tentar, direcao)) {
              reset_punish(tmp, des, jog, tentar);
            } else tmp.first = 0;
  				} else {
  					atual->mao[tmp.first][tmp.second]++;
            reset_punish(tmp, des, jog, tentar);
  				}
  			} else {
  				while(des--) {
  					tmp = saque.front();
  					saque.pop();
  					atual->mao[tmp.first][tmp.second]++;
  				}
          reset_punish(tmp, des, jog, tentar);
  			}
  			
  		}
  		
  		if(direcao == HORARIO) {
  			atual++;
  			if(atual == game.end()) atual++;
  		} else {
  			atual--;
  			if(atual == game.end()) atual--;
  		}
  	}
  	
  }
  return 0;
}
