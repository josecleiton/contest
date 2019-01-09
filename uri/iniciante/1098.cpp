#include <bits/stdc++.h>
using namespace std;

int main(){
    for(double i=0.0; i<=2.0; i+=0.2){
        for(double j=1.0+i; j<=3+i; j++){
            if(((int)(i*10))%10 == 0)
                printf("I=%.0f J=%.0f\n", i,j);
            else
                printf("I=%.1f J=%.1f\n", i, j);
        }
    }
    return 0;
}
