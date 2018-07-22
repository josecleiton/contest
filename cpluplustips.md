# TIPS PARA A MARATONA

## Entrada e Saída

`getline(cin,s)` pega toda a linha e coloca em s

`cout.precision(a)` determina a precisão dos números em ponto fluente para toda a saída por cout. Atentar para o uso do operador "fixed" para que a saída seja efetiva


## Vector

### Operadores de comparação

`a = b` copia todo o vetor b para um vetor a

### Ordenamento

Crescente:  `sort(v.begin(),v.end())`

Decrescente: `sort(v.rbegin(),v.rend())`

### Preenchimento
`for (auto &i : a) cin >> i;` preenche um vetor a com i até o tamanho do vetor


### Soma de todos os elementos

`accumulate(v.begin(),v.end(),0)` // 0 é o valor inicial da soma

### Reverter um vetor/string

`reverse(s.begin(), s.end());` 

### Retorna o i-ésimo caractere da string s
`s.at(i)`

### converte um inteiro i para uma string e concatena em s
`stringstream temp;`
`temp<<i;`
`s+=temp.str();`

## Conjuntos

### Conjunto sem ordem

`unordered_set<int> s;` Declaração
`s.insert(a)` inserção em s

## Genericos

Troca entre dois objetos `swap(a,b)`
Number of digits in N = `floor(log10(N)) + 1;`

## Matrizes
diagonal `i==j`
acima da diagonal `j>i`
abaixo da diagonal `i>j`
acima da diagonal sec `i+j<N-1`
abaixo da diagonal sec `i+j>N-1`
cria uma matriz nxn a e preenche-na com um valor inteiro b `vector<vector<int>> a(n, vector<int>(n, b));`
coloca toda a diagonal de uma matriz quadrada a como b `FOR(n) {a[i][i] = b}` 
coloca toda a diagonal secundária de uma matriz quadrada a como b `FOR(n) {a[i][n-i-1] = b;}` 
