//TEMPLATE COM MACROS PARA OS CONTESTS
//compile usando: g++ -std=c++11 -lm -O3 1010.cpp
#include <bits/stdc++.h>

int maior (int a, int b){
    return (a>b)*a + (b>a)*b;
}

using namespace std;

int main(){
double a,b,c;
cin>>a>>b>>c;
if(!a){
    cout<<"Impossivel calcular"<<endl;
    return -1;
}
double delta = b*b-4*a*c;
if(delta<0){
    cout<<"Impossivel calcular"<<endl;
    return -1;
}
cout.precision(5);
cout<<"R1 = "<<fixed<<(-b+sqrt(delta))/(2*a)<<endl<<"R2 = "<<fixed<<(-b-sqrt(delta))/(2*a)<<endl;

 

return 0;
}