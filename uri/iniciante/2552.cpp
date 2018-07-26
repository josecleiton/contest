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
typedef vector<string> vs;
typedef vector<double> vd;
typedef vector<long> vl;
typedef vector<ll> vll;


/*
    PS: ESSA BAGUNÇA FOI ACEITA PELO JUDGE
*/

int main(){
    int n,m;
    int b;
    int sum;
    while(cin>>n>>m){
        matrixM(n,m);
        FORM(n,m){
            cin>>b;
            M[i][j] = b;
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!M[i][j]){
                    if(i!=0 and j!=0 and i!=n-1 and j!=m-1) // posso somar as quatro pos.
                        sum=M[i+1][j]+M[i-1][j]+M[i][j+1]+M[i][j-1];
                    else{   
                        if(!i and i!=n-1){ // não posso somar para cima
                            if(!j and j!=m-1){ // não posso somar para esquerda
                                sum=M[i+1][j]+M[i][j+1];
                            }
                            else if(j==m-1){ // não posso somar para direita
                                sum=M[i+1][j]+M[i][j-1];
                            }
                            else{
                                sum = M[i+1][j]+M[i][j+1]+M[i][j-1];
                            }
                        }
                        if(i and i==n-1){ //não posso somar para baixo
                            if(!j and j!=m-1){ // não posso somar para esquerda
                                sum=M[i-1][j]+M[i][j+1];
                            }
                            else if(j==m-1){ // não posso somar para direita
                                sum=M[i-1][j]+M[i][j-1];
                            } 
                            else{
                                sum = M[i-1][j]+M[i][j+1]+M[i][j-1];
                            }
                        }
                        else if (i){
                            if(!j and j!=m-1){ // não posso somar para esquerda
                                sum=M[i-1][j]+M[i][j+1]+M[i+1][j];
                            }
                            else if(j==m-1){ // não posso somar para direita
                                sum=M[i-1][j]+M[i][j-1]+M[i+1][j];
                            } 
                        }
                        else if (!i and i==n-1){ // so posso somar para os lados
                            if(!j and j!=m-1){ // não posso somar para esquerda
                                sum=M[i][j+1];
                            }
                            else if(j==m-1){ // não posso somar para direita
                                sum=M[i][j-1];
                            } 
                            else{
                                sum = M[i][j+1]+M[i][j-1];
                            }
                        }
                    }

                    cout<<sum;
                }
                else cout<<'9';
            }
            cout<<endl;
        }
    }
    return 0;
}
