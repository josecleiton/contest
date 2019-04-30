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

char spaces[80];

void print_table(const int& ans, const vi& freq, const int& ct) {
  putchar('\n'); // EXCLUA ANTES DE ENVIAR
  printf("|     %d    |        %d       | ", ct, ans);
  int cnt = 0;
  for(int i=0; i<26; i++) {
    if(!freq[i]) {
      cnt++;
      putchar(i+'a');
    }
  }
  spaces[27-cnt] = '\0';
  printf("%s", spaces);
  spaces[27-cnt] = ' ';
  puts(" |");
  puts("+----------+----------------+-----------------------------+");
}

int idx(char k) {
  if(k == 'k' or k == 'K') {
    return k-'a';
  }
  if(k >= 'a' and k <= 'z')
    return k-'a';
  else
    return k-'A';
}

int main() {
  //ios::sync_with_stdio(0);
  //cin.tie(0);
  //char c;
  //ll n, m, l;
  //int n, m, l;
  //string s;
  //auto logger = freopen("keyboard.dat", "r+", stdin);
  char in_restricao[80], input[80];
  strcpy(spaces, "                           ");
  int ans;
  bool broke;
  int ct = 1;
  // record = @luizbacci
  puts("+----------+----------------+-----------------------------+");
  puts("| Keyboard | # of printable | Additionally, the following |");
  puts("|          |      lines     | letter keys can be broken   |");
  puts("+----------+----------------+-----------------------------+");
  vi freq;
  while(fgets(in_restricao, 80, stdin) and strcmp(in_restricao, "finish\n")) {
    freq.assign(26, 0);
    for(int i=0; in_restricao[i]; i++){
      if(isalpha(in_restricao[i])) 
        freq[idx(in_restricao[i])] = -1;
    }
    ans = 0;
    while(fgets(input, 80, stdin)) {
      broke = false;
      for(int i=0; input[i]; i++) {
        if(isalpha(input[i])) {
          int index = idx(input[i]);
          if(freq[index] == -1) {
            broke = true;
            break;
          } else {
            freq[index]++;
          }
        } 
      }
      if(!broke) ans++;
      if(!strcmp(input,"END\n")) {
        print_table(ans, freq, ct++);
        break;
      }
    }
  }

  return 0;
}
