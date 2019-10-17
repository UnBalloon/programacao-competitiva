# Sparse Table
Nesse tutorial vamos falar sobre uma estrutura de dados chamada Sparse Table, que é uma estrutura de dados poderosa para resolvermos range queries de algumas operações específicas em complexidades superiores as de uma Segment Tree por exemplo. 

Por exemplo, uma Sparse Table conseque resolver range minimum(ou maximum) query em `O(1)`, enquanto numa segment tree precisaríamos de `O(log n)`. Outro exemplo poderia ser range query de gcd, numa Segment Tree podemos resolver range queries de GCD em `O(log^2 n)`, já na sparse table conseguimos isso em `O(log n)`. No geral, quando a operação da range query tem uma propriedade chamada idempotência, podemos tirar um log da complexidade usando a Sparse Table.

## Idempotência

A propriedade que uma operação precisa ter para que possamos ganhar tempo de execução usando a Sparse Table é a idempotência. Na definição que estamos levando em consideração, uma operação `op` (binária) é idempotente quando para todo `x` e todo `y`, `op(x,y) = op(x,op(x,y))`. Poderíamos dar uma definição mais precisa porém o que precisamos saber é que numa operação idempotente, aplicar a operação uma vez é o mesmo que aplicar 2,3,4,... qualquer número de vezes maior que 0.

A operação min possui essa propriedade, para qualquer `x,y`, `min(x,y) = min(x,min(x,y))`. Outro exemplo é o próprio gcd como mencionado acima. para qualquer `x,y`, `gcd(x,y) = gcd(x,gcd(x,y))`. 

Mas essa propriedade não é verdade para a operação de soma, por exemplo, seja `sum(x,y) = x + y`, `sum(3,4) != sum(3,sum(3,4))`, aplicar a operação mais de uma vez com os mesmos argumentos a direita(ou a esquerda) resulta num resultado diferente, então soma não é idempotente. Na verdade as operações mais comuns vão ser GCD e min/max, mas é importante saber a propriedade para entender porque a ideia que vamos usar funciona e também caso haja uma operação meio maluca que seja idempotente saber se consegue montar a Sparse table sobre ela.

## O pulo do gato

Imagine que tenhamos uma função `mágica`, chamada `dp(n,k)`, que retorna basicamente a operação aplicada no intervalo [n, n + (2^k) - 1]. 
```
k = 0, [n, n]
k = 1, [n, n + 1]
k = 2, [n, n + 3]
k = 3, [n, n + 7]
.
.
```

Então se a operação for `min`, vai ser o mínimo dos elementos nesse intervalo, se for `gcd` vai ser o gcd entre todos os número desse intervalo etc. Certo então com essa função, vamos fingir que recebemos uma min query para o intervalo [4, 17] em um vetor.

Como a operação é idempotente, podemos fazer o seguinte. A resposta vai ser min(dp(4,3), dp(10,3)),

```
[0, 1, 2, 3, (4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17)]
[1, 3, 2, 5, (9, 6, 8, 0, 1, 2, 40, 51,  2,  4, 63, 20,  2,  4)]
```
O intervalo que estamos interessados está demarcado com um parêntese. Bem, dp(4, 3) = 0, e dp(10,3) = 2, e min(0,2) = 0, que realmente é o mínimo do intervalo. Se a query fosse no intervalo [4,10] poderíamos fazer `min(dp(4,2), dp(7,2))`, e assim por diante.

Então o que nós estamos fazendo aqui é selecionando uma potencia de dois e duas posições aonde duas chamadas a essa função mágica vão ser suficientes para cobrir exatamente o intervalo que estamos interessados. E a operação precisa ser idempotente porque como estamos selecionando apenas intervalos que tem tamanhos de potências de dois, no caso geral não conseguimos selecionar dois intervalos que não tenham interseção, e caso a operação não seja idempotente, isso fará com que a interseção seja contada duas vezes, fazendo então com que essa ideia não funcione.

Então a complexidade que temos até então para resolver consultas é a seguinte: `O(k + 2*q)` aonde `k` é o custo da operação, e `q` é o custo da nossa função `mágica`. Veremos que conseguimos com programação dinâmica precomputar os valores pra essa função fazendo com que as chamadas a ela tenham tempo constante.

## Recorrência

Esta é a recorrência da programação dinâmica, nessa recorrência, estamos apenas dizendo o seguinte. O resultado da operação em um intervalo é o resultado da primeira metade combinado com o resultado da segunda metade.
```cpp
int dp(int i, int k) {
if(k == 0) {
    return v[i];
}

return op(dp(i,k-1),dp(i + (1 << (k-1)). k-1));
}
```


## Versão recursiva

```cpp
int memo[SIZE][log2(SIZE)+1];
vector<int> v(SIZE);
int dp(int i, int k) {
if(k == 0) {
    return v[i];
}
if(memo[i][k] != -1) return memo[i][k];
return memo[i][k] = min(dp(i,k-1),dp(i + (1 << (k-1)), k-1));
}
```

## Versão iterativa

```cpp
int memo[SIZE][log2(SIZE)+1];
vector<int> v(SIZE);
for(int i = 0; i < SIZE; i++) {
    memo[i][0] = v[i];
}
for(int i = 0; i < SIZE; i++) {
    for(int k = 1; k <= log2(SIZE); k++) {
        memo[i][k] = min(memo[i][k-1], memo[i + (1 << (k-1))][k-1]);
    }
}
```

# Exercícios recomendados