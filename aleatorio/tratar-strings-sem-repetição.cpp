/*
O professor Jorge Farias me propôs certo problema:
ler n strings e dividi-las em palavras, no fim printar essas palavras e quantas vezes elas apareceram
SEM REPETIÇÃO!
Solução: recursão + BST(melhora a busca)
*/
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
#define pb(a) push_back(a)
#define TAM 800

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

typedef struct plv{
    char n[TAM];
    int count;
    struct plv *left;
    struct plv *right;
} Plv;

Plv* raiz;

void palavra (char* s);
void lerstrings(char* s);
Plv* inserir (char* info, Plv* root);
void print (Plv* root);

int main(){
    char* s = NULL;
    raiz = NULL;
    lerstrings(s);
    print(raiz);
    return 0;
}

void lerstrings(char* s){
    if(!s){
        s = (char*) malloc(TAM);
        if(!s) return;
	    memset(s, 0, TAM);
        scanf("%[^\n]", s);
        if(!strlen(s)) return;
        scanf("%*c");
        palavra(s);
        free(s);
        s=NULL;
        lerstrings(s);
    }
}

void palavra (char* s){
    if(*s){
        char* tmp = strchr(s, ' ');
        if(tmp) *tmp = '\0';
        //puts(s);
        raiz = inserir(s, raiz);
        if(tmp) palavra(++tmp);
    }
}

Plv* inserir (char* info, Plv* root){
    if(!root){
        root = (Plv*) malloc(sizeof(Plv));
        strcpy(root->n, info);
        root->count = 1;
        root->left = root->right = NULL;
        return root;
    }
    else{
        if (strcmp(info, root->n) < 0) root->left = inserir(info, root->left);
        else if (strcmp(info, root->n) > 0) root->right = inserir(info, root->right);
        else (root->count)++;
    }
}

void print (Plv* root){
    if(!root) return;
    print(root->left);
    printf("%s = %d\n", root->n, root->count);
    print(root->right);
}
