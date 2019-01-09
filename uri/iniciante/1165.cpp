#include <bits/stdc++.h>
using namespace std;

bool primo(int num){
    if((!(num&1) and num > 2) or num <= 1) return false;
    for(int i=3; i*i<=num; i+=2)
        if(num%i==0) return false;
    return true;
}

int main(){
    int n, k;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>k;
        cout<<k;
        if(primo(k))
            cout<<" eh primo"<<endl;
        else
            cout<<" nao eh primo"<<endl;
    }
    return 0;
}
