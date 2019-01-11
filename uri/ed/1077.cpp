//TEMPLATE COM MACROS PARA OS CONTESTS
//compile usando: g++ -std=c++11 -lm -O3 arquivo.cpp
#include <bits/stdc++.h>
#define FOR(x) for(int i=0;i<x;i++)
#define ROF(x) for(int i=x-1;i>=0;i--)
#define FORJ(x) for(int j=0;j<x;j++)
#define FORQ(Q) for(int i=0;Q;i++)
#define FORM(x,y) for(int i=0;i<x;i++) for(int j=0;j<y;j++)
#define FORT(x,y) for(int i=x;i<y;i++)
#define ROFT(x,y) for(int i=x-1;i>=y;i--)
#define WHILE(n,x) while((n--)&&cin>>x)
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

vector<map<char, int>> priority(2); // PRIORIDADES DOS OPERADORES

void analise(string& exp){

   stack<char> op;
   int count_numbers = 0;
   const int exp_len = exp.size();
   bool parentese = false;
   int count_op = 0;

   FOR(exp_len+1){ // loop em todos os chars da exp
        if(isalnum(exp[i])) // numeros
            cout << exp[i];
        else if(exp[i] == '(') // parenteses
            op.push(exp[i]);
        else if(exp[i] == ')' or !exp[i]){
            while(!op.empty() and op.top() != '('){
                cout << op.top();
                op.pop();
            }
            if(!op.empty()) op.pop();
        }
        else{ // operadores
            while(true){
                if(op.empty() or priority[0][exp[i]] > priority[1][op.top()]){
                    op.push(exp[i]);
                    break;
                }
                else{
                    cout << op.top();
                    op.pop();
                }
            }
        }
   }
    cout << endl;
}

int main(){

    priority[0]['('] = 4;
    priority[0]['+'] = priority[0]['-'] = 1;
    priority[0]['*'] = priority[0]['/'] = 2;
    priority[0]['^'] = 4;
    
    priority[1]['('] = 0;
    priority[1]['+'] = priority[1]['-'] = 1;
    priority[1]['^'] = 3;
    priority[1]['*'] = priority[1]['/'] = 2;

    int n;
    string in;
    while(cin>>n){
        FOR(n){
            cin>>in;
            analise(in);
        }
    }
    return 0;
}
