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
#define M(x,y) max(x, y)
#define m(x,y) min(x, y)
#define c(x) cout<<x<<endl
#define C(x) cin>>x

using namespace std;
int main(){

vector<double> v;
double in;
FOR(3){
    cin>>in;
    v.push_back(in);
}
sort(v.rbegin(),v.rend()); //ordena em ordem inversa
if(v[0]>=v[1]+v[2]) c("NAO FORMA TRIANGULO");
else{
    if((v[0]*v[0])==(v[1]*v[1]+v[2]*v[2])) c("TRIANGULO RETANGULO");
    else if(((v[0]*v[0])>(v[1]*v[1]+v[2]*v[2]))) c("TRIANGULO OBTUSANGULO");
    else if((v[0]*v[0])<(v[1]*v[1]+v[2]*v[2])) c("TRIANGULO ACUTANGULO");
    if(v[0]+v[1]+v[2]==(3*v[0])) c("TRIANGULO EQUILATERO");
    else if(v[0]==v[1] || v[1]==v[2] || v[2]==v[0]) c("TRIANGULO ISOSCELES");
}

return 0;
}
