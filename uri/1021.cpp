//TEMPLATE COM MACROS PARA OS CONTESTS
//compile usando: g++ -std=c++11 -lm -O3 1010.cpp
#include <bits/stdc++.h>

using namespace std;

int main(){
int n, m;
double a;
while (cin>>a){
    n=(int) a;
    m=a*100;
    cout<<"NOTAS:"<<endl;
    cout<<n/100<<" nota(s) de R$ 100.00"<<endl;
    n%=100;
    cout<<n/50<<" nota(s) de R$ 50.00"<<endl;
    n%=50;
    cout<<n/20<<" nota(s) de R$ 20.00"<<endl;
    n%=20;
    cout<<n/10<<" nota(s) de R$ 10.00"<<endl;
    n%=10;
    cout<<n/5<<" nota(s) de R$ 5.00"<<endl;
    n%=5;
    cout<<n/2<<" nota(s) de R$ 2.00"<<endl;
    n%=2;
    puts("MOEDAS:");
    m%=100;
    cout<<n<<" moeda(s) de R$ 1.00"<<endl;
    cout<<m/50<<" moeda(s) de R$ 0.50"<<endl;
    m%=50;
    cout<<m/25<<" moeda(s) de R$ 0.25"<<endl;
    m%=25;
    cout<<m/10<<" moeda(s) de R$ 0.10"<<endl;
    m%=10;
    cout<<m/5<<" moeda(s) de R$ 0.05"<<endl;
    m%=5;
    cout<<m<<" moeda(s) de R$ 0.01"<<endl;
}


return 0;
}