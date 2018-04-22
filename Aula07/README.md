# Matemática

## Resposta Módulo

Diversos problemas em juízes online (e competições) costumam pedir a resposta módulo algum primo alto (bastante comum 10^9 + 7). O motivo disso é evitar overflow. Por exemplo: finja que você tem o seguinte problema: 

Imprimir o resultado de 3^`x` (0 <= `x` <= 100), por exemplo. Esse resultado claramente excede 2^64 (limite de long long), então não faz muito sentido pedir o resultado por si só (na verdade, alguns problemas realmente pedem coisas do tipo, nesses casos, o recomendado é usar python, que não tem overflow). 

Então pedem o resultado módulo 10^9 + 7, ou algum primo muito alto, para que não force as pessoas a usarem uma linguagem ou outra.

O motivo de ser um número alto é minimizar a chance de seu programa a computar a resposta errada (e por sorte ser igual em módulo a resposta correta) e o juíz aceitá-la.

O motivo de ser um número primo é que adicionam algumas propriedades a mais que podemos usar para calcular a resposta, como o inverso multiplicativo, mas não abordaremos isso aqui.

As seguintes propriedades valem no cálculo do módulo: 

`(a + b) % c = ((a % c) + (b % c)) % c`

`(a * b) % c = ((a % c) * (b % c)) % c`

O que isso quer dizer é que se a resposta está sendo computada por meio de adições e multiplicações, e no final você precisa tirar o módulo dela, você pode tirar módulo em todas as operações intermediárias que isso não afetará a resposta.

Então, por exemplo:

```cpp
long long exp(int p){
  if(p == 0)
    return 1;
  return 3ll * exp(p-1);
}

int main(){
  int mod = 1e9+7;
  int n;
  scanf("%d",&n);
  printf("%lld\n", exp(n) % mod);
}

```

O código acima gera overflow, a resposta vai estourar o limite de long long (já terá se tornado negativa) quando tirarmos o mod. No entanto, conceitualmente, ele está correto.

Então, usando as propriedades vistas em cima, podemos fazer:

```cpp
int mod = 1e9+7;

long long exp(int p){
  if(p == 0)
    return 1;
  return (3ll * exp(p-1)) % mod;
}

int main(){
  int n;
  scanf("%d",&n);
  printf("%lld\n", exp(n));
}

```

De forma que o código acima imprime (3^n) % (1000000007), sem causar overflow.


## Divisores

Um problema recorrente é o de encontrar divisores de um número positivo. A maneira mais simples de resolvê-lo seria passar por todos os números e testar se o resto da divisão é 0, ou seja, se é divisível.

```c++
vector<long long> all_divisors(long long n){
  vector<long long> ans;
  for(long long i = 1; i <= n; i++)
    if(n % i == 0)
      ans.push_back(i);
  return ans;
}
```

é fácil ver que a complexidade do código acima é `O(n)`, podemos fazer melhor que isso com algumas observações.

Se `a` é um divisor `n` então o resto da divisão de `n` por `a` é 0 assim `b = n/a` é um inteiro. Sabemos então que `a*b = n`, ou seja, `a = n/b` e assim `b` também é um divisor de `n`. Se fixarmos que `a <= b`, qual o valor máximo de `a`? Como `a` é no máximo `b`, consideremos o caso em que `a = b` temos que `a*a = n`, ou seja, `a = sqrt(n)`.

Agora é possivel modificar o código passando por todos os valores possíveis de `a` e computar o respectivo `b` para encontrar todos os divisores.

```c++
vector<long long> all_divisors(long long n){
  vector<long long> ans;
  for(long long a = 1; a*a <= n; a++){ // comparação que evita o uso de doubles, a <= sqrt(n) é o mesmo que a*a <= n, ja que a e n sao positivos
    if(n % a == 0){
      long long b = n / a;
      ans.push_back(a);
      ans.push_back(b);
    }
  }
  sort(ans.begin(), ans.end()); // frescura para retornar os divisores ordenados como na primeira implementação
  return ans;
}
```

Só há um problema com a implementação acima. Assumimos que `a <= b`, caso `a = b` inserimos o divisor 2 vezes na resposta, por exemplo, para 36 podemos ter `a = 6` e `b = 6`. Assim a versão final do código fica:

```c++
vector<long long> all_divisors(long long n){
  vector<long long> ans;
  for(long long a = 1; a*a <= n; a++){ // comparação que evita o uso de doubles, a <= sqrt(n) é o mesmo que a*a <= n
    if(n % a == 0){
      long long b = n / a;
      ans.push_back(a);
      if(a != b) ans.push_back(b);
    }
  }
  sort(ans.begin(), ans.end()); // frescura para retornar os divisores ordenados como na primeira implementação
  return ans;
}
```

com complexidade `O(sqrt(n))`.

### Observações
Um número primo tem somente dois divisores positivos, assim podemos checar se um numero `x` é primo usando `all_divisors(x).size() == 2` ou modificando um pouco a rotina e ter uma melhor constante na complexidade
```c++
vector<long long> is_prime(long long n){
  if(n == 1) return 0;
  for(long long a = 2; a*a <= n; a++){ // comparação que evita o uso de doubles, a <= sqrt(n) é o mesmo que a*a <= n
    if(n % a == 0){
      return 0;
    }
  }
  return 1;
}
```

## Passar por todos os múltiplos de x até N
Consideramos multiplos de `x` os números: `x, 2*x, 3*x, 4*x, ...` ou, escrevendo de outra forma, `x, x+x, x+x+x, x+x+x+x, ...`

Caso queiramos fazer algo com todos os múltiplos de `x` até um limite `N` podemos usar a simples rotina
```c++
for(int m = x; m < N; m += x){ // m é sempre multiplo de x
  // code
}
```
Que é executada em `O(N/x)`.

## Passar por todos os múltiplos de todos os números até N

Se passarmos por todos os números `x` entre 1 e `N` e para cada um deles achar todos os múltiplos `m`.

O código ficaria algo como

```c++
for(int x = 1; x < N; x++){
  for(int m = x; m < N; m += x){ // m é sempre multiplo de x
    // code
  }
}
```

O código acima parece ser executado em `O(N^2)`, mas podemos definir uma cota bem menor, com algumas observações. O código é executado em `N/1 + N/2 + ... + N/(N-1) + N/N` passos. Podemos botar o `N` em evidencia `N*(1/1 + 1/2 + 1/3 + ... + 1/(N-1) + 1/N)`. A soma dentro dos parenteses é menor que a área abaixo da curva da função `1/x`, a integral é `ln(x)`(mas relaxa que não precisa lembrar das coisas de cálculo 1). Portanto `O(N*(1/1 + 1/2 + 1/3 + ... + 1/(N-1) + 1/N)) = O(N*lg N)`.

Podemos resolver vários problemas usando isso pois `x` será divisor de `m` e assim para todo `m` também passaremos por todos os divisores deles. 

## Contando os divisores de vários números

Por exemplo, usando essa abordagem, poderíamos usar esses 2 laços aninhados para gerar um vetor `div` que informa quantos divisores todos os números até `n` tem.

Perceba que esses dois laços executam em `O(n * log n)`, enquanto repetir o algoritmo de contar os divisores de cada número individualmente teria complexidade `sqrt(1) + sqrt(2) + ... + sqrt(n)` = O(n * sqrt(n)), ou seja, tem complexidade melhor.

A abordagem abaixo funciona porque sempre que chegamos em um número `m` no laço mais interno, significa que temos um divisor a mais. 

Na primeira iteração passamos por todos os números, já que começamos e 1 e estamos incrementando de 1 em 1, todos os números são divisíveis por 1, então todos ganham um divisor a mais no vetor.

Na segunda iteração, passamos apenas pelos números múltiplos de 2, em todos os números que chegarmos, significa que esse número é divisível por 2 (ou seja, sabemos que ele tem um divisor a mais). E repetimos esse raciocínio para todos os números. 


```c++
vector<int> computa_divisores(int N){
vector<int> qnt_div(N, 0);
  for(int x = 1; x < N; x++){
    for(int m = x; m < N; m += x){
      qnt_div[m]++; // aqui descobrimos que x é divisor de m
    }
  }
  return qnt_div;
}
```

## Pegando todos os números primos até `N`

Em particular, sabendo a quantidade de divisores de cada número, podemos varrer esse vetor vendo quais números são primos (tem 2 divisores).

```cpp
vector<int> primos_ate_n(int N){
  vector<int> primos;
  for(int x = 1; x < N; x++){
    if(qnt_div[x] == 2)
      primos.push_back(x);
  }
  return primos;
}
```

## Crivo de erastótenes

A abordagem acima tem uma complexidade aceitável, e passaria no tempo para a maioria dos problemas. No entanto, existe um algoritmo com uma ideia semelhante, mas que com algumas observações baixa essa complexidade de `O(n * log n)` para `O(n * log( log n))`. O log já abaixa muito um número, se aplicamos ele novamente, abaixamos mais ainda, ou seja, isso é quase linear.

A ideia usada é marcar inicialmente todos os números entre 1 e `N` como possiveis primos. Passando em ordem crescente e quando encontramos um primo marcamos os múltiplos do primo como não primos.

```c++
vector<int> primos_ate_n(int N){
  vector<int> marcacao(N, 1); // 1 = possivel primo, 0 = com certeza não primo
  vector<int> primos;
  for(int x = 2; x < N; x++) if(marcacao[x] == 1){
    primos.push_back(x);
    for(int m = x+x; m < N; m += x){
      marcacao[m] = 0; // aqui descobrimos que m não é primo
    }
  }
  return primos;
}
```


## Decomposição(fatoração) em fatores primos

Aprendemos na escola que todo número é composto por fatores primos, existindo uma única fatoração pra cada número.

Uma primeira abordagem possível seria passar por todos os números e ir dividindo sempre que possível.

```c++
// retorna vetor de pair<primo, expoente> da fatoração
// fatora(36) = [{2, 2}, {3, 2}] ou seja, 36 = 2^2 + 3^2
vector<pair<long long, int>> fatora(long long n){
  vector<pair<long long, int>> ans;
  for(long long p = 2; p <= n; p++){
    if(n % p == 0){
      int expoente = 0;
      while(n % p == 0){
        n /= p;
        expoente++;
      }
      ans.emplace_back(p, expoente);
    }
  }
  return ans;
}
```

A primeira vista,como queremos decompor em fatores primos, parece que temos que testar se `p` é primo. Entretanto passamos por `p` de forma crescente e sempre que podemos dividimos `n` por `p` então a condição `(n % p == 0)` só será verdade para `p` primos.  

Isso ocorre porque todos os fatores primos de um número são menores ou iguais a ele próprio, então quando chegamos em um número, é impossível que ele divida o número e não seja primo, pois se não for, os números primos que o compoem deveriam ter sido contabilizados numa iteração anterior.

Apesar do código acima rodar bem para vários exemplos, no pior caso `n` é primo e o código é executado em `O(n)`.

Podemos melhorar a complexidade com uma simples observação. É possivel ter **apenas** um primo maior que a `sqrt(n)`, por exemplo, 10 tem 5 como fator e `5 > sqrt(10)`, mas é impossível ter dois primos maiores que a raiz. Se tivermos `a > sqrt(n)` e `b > sqrt(n)`, quando multiplicamos temos que `a * b > sqrt(n) * sqrt(n)` e `a * b > n`.

```c++
vector<pair<long long, int>> fatora(long long n){
  vector<pair<long long, int>> ans;
  for(long long p = 2; p*p <= n; p++){ // comparação que evita o uso de doubles, p <= sqrt(n) é o mesmo que p*p <= n
    if(n % p == 0){
      int expoente = 0;
      while(n % p == 0){
        n /= p;
        expoente++;
      }
      ans.emplace_back(a, expoente);
    }
  }
  if(n > 1) ans.emplace_back(n, 1);
  return ans;
}
```

## Fatoração em O(lg n) para números até N

É possível fatorar números ate um limite `N` em `O(lg n)` após preprocessamento `O(n log( log n))`. O que fazemos é uma pequena modificação no código do crivo, para que enquanto fazemos o crivo, preenchamos um vetor auxiliar `lp`, aonde `lp[x]` representa o menor número primo que divide `x`.

```c++
vector<int> lp(N, -1);

for(int x = 2; x < N; x++)
  if(lp[x] == -1){ // se x nao foi marcado antes, é primo
    for(int m = x; m < N; m += x) // todos os multiplos de i
      lp[m] = x;
  }
```

Tendo este vetor podemos fatorar um numero `x` com o seguinte procedimento.

```c++
vector<pair<int, int>> fatora(int x){
  map<int, int> expoentes;
  while(x > 1){
    expoente[ lp[x] ]++; // aumentamos o expoente do primo lp[x] em 1 na resposta
    x /= lp[x];
  }
  vector<pair<int, int>> ans;
  for(pair<int, int> p : expoentes)
    ans.emplace_back(p);
  return ans;
}
```

A complexidade do procedimento acima é `O(quantidade de fatores)`, que é limitado por `O(lg n)`, da para ver que no pior caso todos os fatores são 2(menor primo) e a complexidade é o `k` de `2^k = n`.
