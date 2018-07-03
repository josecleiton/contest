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
#define set(a,b) cout.precision(a); cout<<fixed<<b<<endl
#define pcs(a) cout.precision(a)
#define fx(a) fixed<<a
#define gl(s) getline(cin,s)

using namespace std;
int main(){
string a,b,c;
gl(a);
gl(b);
gl(c);
if(a=="vertebrado"){
    if(b=="ave"){
        if(c=="carnivoro") c("aguia");
        else if(c=="onivoro") c("pomba");
    }
    else if(b=="mamifero"){
        if(c=="onivoro") c("homem");
        else if(c=="herbivoro") c("vaca");
    }
}
else if(a=="invertebrado"){
    if(b=="inseto"){
        if(c=="hematofago") c("pulga");
        else if(c=="herbivoro") c("lagarta");
    }
    else if(b=="anelideo"){
        if(c=="hematofago") c("sanguessuga");
        else if(c=="onivoro") c("minhoca");
    }
}



return 0;
}
