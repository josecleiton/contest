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
double a,b,c,d,m;
cin>>a>>b>>c>>d;
cout.precision(1);
m=(a*2+b*3+c*4+d)/10;
cout<<"Media: "<<fixed<<m<<endl;
if(m>=7) cout<<"Aluno aprovado."<<endl;
else if(m<5) cout<<"Aluno reprovado."<<endl;
else{
    cout<<"Aluno em exame."<<endl;
    cin>>a;
    cout<<"Nota do exame: "<<fixed<<a<<endl;
    m=(m+a)/2;
    if(m>=5) cout<<"Aluno aprovado."<<endl;
    else cout<<"Aluno reprovado."<<endl;
    cout<<"Media final: "<<fixed<<m<<endl;

}


return 0;
}
