//TEMPLATE COM MACROS PARA OS CONTESTS
//compile usando: g++ -std=c++11 -lm -O3 1010.cpp
#include <bits/stdc++.h>

using namespace std;

int main(){
    double a;
    cin>>a;
    if(a>=0 and a<=25) cout<<"Intervalo [0,25]"<<endl;
    else if (a>25 and a<=50) cout<<"Intervalo (25,50]"<<endl;
    else if (a>50 and a<=75) cout<<"Intervalo (50,75]"<<endl;
    else if (a>75 and a<=100) cout<<"Intervalo (75,100]"<<endl;
    else cout<<"Fora de intervalo"<<endl;
return 0;
}