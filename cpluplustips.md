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

### Soma de todos os elementos

`accumulate(v.begin(),v.end(),0)` // 0 é o valor inicial da soma

## Genericos

Troca entre dois objetos `swap(a,b)`
Number of digits in N = `floor(log10(N)) + 1;`

## Matrizes
diagonal `i==j`
acima da diagonal `j>i`
abaixo da diagonal `i>j`
acima da diagonal sec `i+j<N-1`
abaixo da diagonal sec `i+j>N-1`