#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int n,m=0,cnt;
    long long sp;
    char arr[55][55];
    long long len[55];
    while(scanf("%d", &n) && n){
        if(m++) putchar('\n');
        sp=0ll;
        for(int i=0; i<n; i++){
            scanf("%s", arr[i]);
            len[i]=strlen(arr[i]);
            if(len[i]>sp) sp=len[i];
        }
        for(int i=0; i<n; i++){
            cnt=sp-len[i];
            while(cnt--) putchar(' ');
            puts(arr[i]);
        }
    }
    return 0;
}