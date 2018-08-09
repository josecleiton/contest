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

Podem ser usados se o vetor tiver valores unicos e esse valor precisar ser ordenado.

`set<int> s` Declaração de um conjunto s 
`unordered_set<int> s;` Declaração de um conjunto sem ordem
`s.insert(a)` inserção em s

## Genericos

Troca entre dois objetos `swap(a,b)`
Number of digits in N = `floor(log10(N)) + 1;`
Para inicializar várias variáveis num for, crie uma struct.
`for(struct{vector<int>::iterator it; int i;} k = {v.begin(), 0}; k.it != v.end(); k.it++, k.i++)`
    `cout << k.i << ": " << *k.it << endl;`    

## Matrizes

diagonal `i==j`
acima da diagonal `j>i`
abaixo da diagonal `i>j`
acima da diagonal sec `i+j<N-1`
abaixo da diagonal sec `i+j>N-1`
cria uma matriz nxn a e preenche-na com um valor inteiro b `vector<vector<int>> a(n, vector<int>(n, b));`
coloca toda a diagonal de uma matriz quadrada a como b `FOR(n) {a[i][i] = b}` 
coloca toda a diagonal secundária de uma matriz quadrada a como b `FOR(n) {a[i][n-i-1] = b;}` 


## Structs

Adicionar o pré-processador `#pragma (push, 1)` e `#pragma (pop)` entre structs elimita o "arredondamento" que o compilador aplica à essas estruturas de dados.


## List

Não há index, todo elemento deve ser acessado pelo iterator (list<type>::iterator it = list.begin())
list.insert(it, 100) <- insere o elemento 100 antes do iterator em questão
list.erase(it) <- popa o elemento da lista, e retorna um iterator para o elemento anterior
list.push_front(102) <- coloca o elemento 102 no inicio da lista
list.pop_front() <- retira o elemento 102 da lista

## Maps

Acessa um elemento com complexidade O1 a partir de sua chave (map["Cleiton"], sendo "Cleiton" a chave) ou por um iterator (complexidade diferente).
A função make_pair("Ah", 100) cria um par string, int sem a necessidade de digitar: pair<string, int>("Ah", 100)
A função make_pair pode ser usada com o método insert. map.insert(make_par("Ah", 100)) ou map.insert(pair<string, int>("Ah", 100))
O método map.find(key) retorna um iterator para o par, se o par estiver no map, senão retorna um iterator para o final do map (map.end())

