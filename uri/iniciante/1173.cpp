#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    for(int i=0; i<10; i++,n<<=1)
        printf("N[%d] = %d\n", i, n);
    return 0;
}
