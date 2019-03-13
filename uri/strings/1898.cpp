//TEMPLATE COM MACROS PARA OS CONTESTS
//compile usando: g++ -std=c++11 -lm -O3 arquivo.cpp
#include <bits/stdc++.h>
#define FOR(x) for(int i=0;i<x;i++)
#define ROF(x) for(int i=x-1;i>=0;i--)
#define ROFJ(x) for(int j=x-1;j>=0;j--)
#define FORJ(x) for(int j=0;j<x;j++)
#define FORQ(Q) for(int i=0;Q;i++)
#define FORM(x,y) for(int i=0;i<x;i++) for(int j=0;j<y;j++)
#define FORT(x,y) for(int i=x;i<y;i++)
#define ROFT(x,y) for(int i=x-1;i>=y;i--)
#define WHILE(n,x) while((n--)&&cin>>x)
#define SORT(v) sort(v.begin(), v.end())
#define SORTC(v, comp) sort(v.begin(), v.end(), comp)
#define FORIT(v) for(auto& it: v)
#define c(x) cout<<x<<endl
#define C(x) cin>>x
#define set(a,b) cout.precision(a); cout<<fixed<<b<<endl
#define pcs(a) cout.precision(a)
#define fx(a) fixed<<a
#define gl(s) getline(cin,s)
#define pb(a) push_back(a)
#define matrixM(n,m) vector<vector<int>> M (n, vector<int> (m))
#define matrixN(n,m) vector<vector<int>> N (n, vector<int> (m))

using namespace std;

#define MAX 100

void soma(char* a, char* b, int lenA, int lenB, int* pA, int* pB){
    char res[MAX];
    memset(res, '0', MAX-1);
    res[MAX-1] = '\0';
    int ponto=0;
    if(pA[0] or pB[0]){
        if(!pA[0]){
            FOR(pB[1]) a[lenA++] = '0';
            ponto=pB[1];
        }
        else if(!pB[0]){
            FOR(pA[1]) b[lenB++] = '0';
            ponto=pA[1];
        }
        else{
            if(pA[1] > pB[1]){
                FOR(pA[1]-pB[1]) b[lenB++] = '0';
                ponto=pA[1];
            }
            else{
                FOR(pB[1]-pA[1]) a[lenA++] = '0';
                ponto=pB[1];
            }
        }
    }
    int carry=0, i,j,k=max(lenA, lenB)+2;
    res[k+1]=res[k]='\0';
    char *op1, *op2;
    if(lenA > lenB){
        op1 = a;
        i=lenA-1;
        op2 = b;
        j=lenB-1;
    }
    else{
        op1 = b;
        i=lenB-1;
        op2 = a;
        j=lenA-1;
    }

    while(i>=0 and j>=0){
        res[k] = (op1[i]-'0')+(op2[j]-'0')+carry;
        if(res[k] >= 10){
            carry = 1;
            res[k] %= 10;
        }
        else carry = 0;
        res[k] += '0';
        k--;
        i--; j--;
    }
    while(i>=0){
        res[k] = (op1[i]-'0')+carry;
        if(res[k] >= 10){
            carry = 1;
            res[k] %= 10;
        }
        else carry = 0;
        res[k] += '0';
        k--; i--;
    }
    res[k]+=carry;
    int tam = strlen(res);
    if(ponto){
        strcpy(res+tam-ponto, res+tam-1-ponto);
        res[tam-ponto]='.';
    }
    else strcpy(res+tam, ".00");
    k=0;
    while(res[k]=='0') k++;
    puts(res+k);
}

int main(){
    string a,b;
    char cpf[12], op1[MAX], op2[MAX];
    int j,k,m;
    int p1[2], p2[2];
    while(cin>>a>>b){
        memset(op1, 0, MAX);
        memset(op2, 0, MAX);
        p1[1]=p2[1]= -1000;   
        p1[0]=p2[0]=j=k=m=0;     
        FOR(a.size()){
            if(isdigit(a[i])){
                if(m < 11) cpf[m++] = a[i];
                else op1[j++] = a[i];
                p1[1]++;
            }
            else if(a[i]=='.'){
                op1[j++]='.';
                p1[0]=j;
                p1[1]=0;
            }
            if(p1[1]==2) break;
        }
        FOR(b.size()){
            if(isdigit(b[i])){
                op2[k++] = b[i];
                p2[1]++;
            }
            else if(b[i]=='.'){
                op2[k++]='.';
                p2[0]=k;
                p2[1]=0;
            }
            if(p2[1]==2) break;
        }
        cpf[m]='\0';
        printf("cpf %s\n%.2lf\n", cpf, stod(op1)+stod(op2));
    }
    
    return 0;
}
    