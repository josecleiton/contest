// TEMPLATE COM MACROS PARA OS CONTESTS
// compile usando: g++ -std=c++11 -lm -O3 arquivo.cpp
#include <bits/stdc++.h>
#define M (ll)1000000007
#define LEN 100005
using namespace std;
typedef vector<int> vi;
typedef int64_t ll;
typedef vector<ll> vll;
typedef vector<string> vstr;
typedef vector<bool> vbit;
typedef pair<ll, ll> pii;
typedef vector<double> vd;

vll memo(LEN);

ll exp_mod(ll x, ll y, const ll m) {
  ll res = 1;
  x = x % m;
  while (y > 0) {
    if (y & 1)
      res = (res * x) % m;
    y = y >> 1;
    x = (x * x) % m;
  }
  return res;
}

ll fat(const ll n) {
  for (ll i = 2; i <= n; i++)
    memo[i] = (memo[i - 1] * i) % M;
  return memo[n];
}

/*

SERÁ APLICADA A FORMULA DE ANAGRAMA: N!/(n1!...nk!)
SO QUE A ENTRADA PODE TER UM N = 10005, QUE OBVIAMENTE NÃO CABE NUM INT64_T
*/
ll anagram(const string &s) {
  vll freq(26);
  ll num = fat(s.size()), den = 1;

  for (auto c : s)
    freq[c - 'a']++;
  for (auto it : freq)
    den = ((den % M) * memo[it]) % M;

  // aplique o pequeno teorema de fermat para conseguir o inverso multiplicativo
  // e multiplique o resultado pela resposta
  return ((num % M) * exp_mod(den, M - 2, M)) % M;
}

int main() {
  memo[0] = memo[1] = 1;
  string s;
  while (cin >> s)
    cout << anagram(s) << endl;
  return 0;
}
