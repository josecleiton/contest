// TEMPLATE COM MACROS PARA OS CONTESTS
// compile usando: g++ -std=c++11 -lm -O3 arquivo.cpp
#include <bits/stdc++.h>
#define set(a, b) cout.precision(a); cout << fixed << b << endl
#define pcs(a) cout.precision(a)
#define fx(a) fixed << a
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
#define matrix(name, type, n, m) vector<vector<type>> name(n, vector<type>(m))
#define PQ(name, type, ord) priority_queue<type, deque<type>, ord<type>> name
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

/*
class Comp {
public:
    bool operator() (const type& a, const type& b) { // COMPARADOR ESTRITO PARA
PRIORITY_Q, UMAP ETC return true;
    }
}

MODULAR ARITHMETIC
( a + b) % c = ( ( a % c ) + ( b % c ) ) % c
( a * b) % c = ( ( a % c ) * ( b % c ) ) % c
( a – b) % c = ( ( a % c ) – ( b % c ) ) % c

*/

struct team {
	int id, penalty, solved;
	array<pair<bool, int>, 9> unsolved {};
  pair<bool, int> problem_status;
	team(int i = INT32_MAX, int p = 0, int s = 0): id(i), penalty(p), solved(s) {
    //fill(problems.begin(), problems.end(), 0);
  }
	void att(const int& problem, const int& _time, const char& L) {
    problem_status = unsolved[problem-1];
    if(!problem_status.first) {
      if(L == 'C') {
        solved++;
        penalty += _time + problem_status.second*20;
        unsolved[problem-1].first = true;
      } else {
        unsolved[problem-1].second++;
      }
    }
	}
};

bool comp(const team& a, const team& b){
	if(a.solved > b.solved) return true;
	else if(a.solved == b.solved) {
		if(a.penalty < b.penalty) return true;
		else if(a.penalty == b.penalty) return a.id < b.id;
	}
	return false;
}

int main() {
  int ct, contestant, problem, _time;
  char L;
  //char c;
  //ll n, m, l;
  //int n, m, l;
  //string s;
  scanf("%d%*c%*c", &ct);
  char input[80] = {'\0'};
  char aux[20] = {'\0'};
  FOR(i, ct) {
    if(i) putchar('\n');
    array<team, 100> board;
  	while(fgets(input, 80, stdin) and (input[0] != '\0' and input[0] != '\n')) {
      sscanf(input, "%d %d %d %s", &contestant, &problem, &_time, aux);
      L = aux[0];
  		//printf("%d %d %d %c\n", contestant, problem, _time, L);
      board[contestant-1].id = contestant;
	  	if(L == 'C' or L == 'I'){
	  		board[contestant-1].att(problem, _time, L);
	  		//auto debug = board[contestant-1];
	  		//printf("%d %d %d %d\n", debug.id, debug.solved, debug.penalty, debug.problems[problem-1]);
	  	}
      input[0] = '\0';
  	}
    sort(board.begin(), board.end(), comp);
    for(const team& t: board) {
      if(t.id != INT32_MAX) {
        printf("%d %d %d\n", t.id, t.solved, t.penalty);
      } else break;
    }
  }

  return 0;
}
