//TEMPLATE COM MACROS PARA OS CONTESTS
//compile usando: g++ -std=c++11 -lm -O3 1010.cpp
#include <bits/stdc++.h>

int maior (int a, int b){
    return (a>b)*a + (b>a)*b;
}

using namespace std;

int main(){
int a,b,c,d;
cin>>a>>b>>c>>d;

if((b>c and d>a) and ((c+d)>(a+b)) and (c>=0&&d>=0) and (!(a%2)))
    cout<<"Valores aceitos"<<endl;
else cout<<"Valores nao aceitos"<<endl;


return 0;
}