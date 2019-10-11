# Busca binária

Busca binária é um algoritmo de divisão e conquista usado em sua maior parte para minimizar o tempo de uma busca linear. Na busca binária sempre estamos procurando o "o maior `x` valor que satisfaz uma condição `c(x)`" ou "o menor `x` valor que satisfaz uma condição `c(x)`", retornaremos nesse ponto depois no texto.

Imagine você com um livro de 1000 páginas em mãos no momento em que o professor pede para que o abra no começo do capitulo 6 seção 4. Existem várias maneiras de se alcançar a página certa. Uma delas é ir de uma em uma até que se alcance a página desejada. Outra maneira é ir pulando alguns blocos de páginas, se você está numa página depois do começo do capitulo 6 seção 4 pula algumas páginas para tras, se você está numa página antes, pula algumas páginas para frente.

Perceba que no exemplo acima uma busca linear (passar de página em página) demoraria muito mais do que ir pulando algumas partes do livro. E fazendo da segunda maneira involuntariamente você acaba aplicando uma versão primitiva do que chamamos de busca binária.

## O algortimo

Usando a mesma ideia do livro porém agora em uma linguagem mais computacional. No lugar de 1000 páginas podemos ter um vetor de 1000 posições onde a i-ésima tem um pair <capitulo, seção> da pagina i, por exemplo, se a página 125 faz parte do capítulo 4 seção 2 então `v[125] = make_pair(4, 2);`. E digamos que o capítulo 6 seção 4 está na página 375(que não sabemos no começo da busca).

Primeiro podemos, por exemplo, para a página 400. A partir do pair daquela posição aprendemos que o que procuramos está antes de 400, então agora não precisamos procurar a resposta no intervalo [1, 1000] e sim no intervalo [1, 399]. Podemos fazer um segundo chute na posicao 300, por exemplo pois podemos chutar em qualquer posição do intervalo, e depois de olhar v[300] aprendemos que a resposta está no intervalo [301, 399]. Podemos então chutar na página 375 e encontrar que esta é a resposta que procuramos.

O único problema do que foi descrito acima é determinar como chutar o elemento dentro do intervalo já que os chutes foram meio aleatórios. O primeiro chute foi no elemento 400 num intervalo [1, 1000], depois de olhar o elemento poderíamos passar a ter que olhar o intervalo \[1, 399\](se o que procuramos está antes) ou \[401, 1000\](se o que procuramos está depois), tivemos sorte e caimos no primeiro caso mas no pior caso poderíamos cair no intervalo maior. O jeito de garantirmos de no pior caso sempre irmos para um intervalo de menor tamanho possivel é chutar de uma forma a dividir o intervalo em 2 intervalos de tamanhos (aproximadamente) iguais. Podemos fazer isso só chutando na metade do intervalo, assim é melhor fazer o primeiro chuta na posição 500 e nao 400.

## Condições para aplicar busca binária

Nem sempre é possível aplicar busca binária para encontrar uma resposta: um exemplo seria um livro cujos capitulos e seçoes nao estão em ordem crescente. Nessa situação, não poderiamos mais ter certeza que um capitulo ou seção maior estaria a direita. 

Como mencionamos acima, na busca binária estamos procurando o maior ou menor valor que satisfaz uma propriedade.  Então por exemplo, no exemplo acima, estamos buscando pelo menor índice(página) do vetor(livro) que satisfaz a condição "estar num (capítulo, seção) maior ou igual a (6,4)", porque a primeira página que satisfazer essa propriedade será o início do capítulo 6 seção 4. Considere agora o outro exemplo de aplicarmos busca binaria no vetor para descobrir se um elemento `x` esta lá ou não. Uma maneira de fazer isso seria procurar pelo menor elemento `y`  que seja maior ou igual `x`, se y for igual a x, então x está no vetor, caso contrário x não está no vetor. 

Dizemos que é possível aplicar busca binária em um problema quando a checagem se um valor satisfaz as condições apresenta **monotonicidade**. Formalmente, monotonicidade pode ser definida da seguinte forma. Seja `check(x)` uma função que verifica uma propriedade de `x` Se para todo  `x`, `check(x) = true` implica `check(x+1) = true`, ou para todo x, `check(x) = false` implica `check(x+1) = false`, então a função `check` é monótona. 

Então, se `x = 11` e o vetor `v = [1,2,3,5, 8, 11, 12, 14, 16]` observe o que acontece com o comportamento de uma função `check` que checa se um elemento é maior ou igual a x.
```
bool check(int val) {
    return val >= x;
}

[1,2,3,5,8,11,12,14,16]
[0,0,0,0,0,1,1,1,1,1]
```
Então se colocarmos graficamente os resultados de uma função `check` monotona, veremos exatamente isso, ou um monte de valores `0`s e a partir de certo ponto todos são `1`s, ou o contrário, um monte de `1`s e a partir de certo ponto todos são `0`s. No exemplo a cima é a primeira possibilidade.

Então a função check para essa situação é monótona, e isso é relevante porque se um valor do vetor satisfizer a condição, todos os valores a direita também vão satisfazê-la, e de forma análoga, todos os valores a esquerda de um índice que não satisfaz a condição, também não vão satisfazer, e é isso que nos permite aplicar busca binária. E a função check só se torna monótona nesse exemplo quando o vetor está ordenado, por isso busca binária só é feita em vetores ordenados : ).

Então o que faremos é chutar intervalo aonde a resposta com certeza estará no começo, fazemos então várias interações checando no meio, e dependendo da resposta, descartamos os elementos a direita ou a esquerda, mas sempre dividimos o tamanho do intervalo por 2, até que o intervalo tenha tamanho 1.

## Complexidade

Tudo muito massa, mas falta a complexidade! Depois de saber isso podemos começar a aplicar esse algoritmo nos problemas por ae :)

por enquanto nosso algoritmo de maneira abstrata é o seguinte
```
while(tamanho do intervalo que a resposta pode estar != 1) {
    chuta no meio e descarta a metade da direita ou da esquerda(dependendo do resultado), dividindo o intervalo por 2;
}
```
Suponha um vetor ordenado de tamanho N onde vamos aplicar o algoritmo de busca binária e o valor procurado não está presente no vetor (pior caso). Na nossa primeira iteração iremos dividir o vetor em 2 partes ou seja teremos N/2 elementos restantes, na segunda iteração iremos dividir do que restou e teremos (N/2)/2 ou seja N/4, seguindo essa lógica na K-ésima iteração vamos dividir o tamanho do vetor K vezes por 2, ou seja, N/(2^K) e como estamos calculando complexidade temos que pensar no pior caso, quando chegarmos no ponto onde teremos um espaço de apenas 1 elemento(e verificamos que o elemento não está no vetor). O que estamos buscando para saber a complexidade é K (quantidade de passos) para o pior caso então temos que N/(2^K) = 1 daí temos que N = 2^K e tirando o log2 dos dois lados temos que K = log2(N). Então no pior caso nosso algortimo demora `O(log2(N))` passos, N sendo o tamanho do intervalo inicial. Se a função de checagem tiver uma complexidade `O(f(x))`, então teremos complexidade no total `O(log2(N) * f(x))*`.

## Código base para busca binária

Há várias maneiras de se implementar busca binária, vamos apresentar várias delas. Vamos usar sempre a função check em separado, os jeitos de implementar diferente são apenas do corpo da busca binária.
```cpp
bool check(int val){
    // nessa função checamos se uma resposta satisfaz as condições para ser uma resposta válida, e retornamos um booleano dependendo disso.
}
```

### Tipo 1

#### Valor mínimo (Menor valor que torna check verdadeiro)
```cpp
int l = a;// sei que a resposta não é menos que a
int r = b;// sei que a resposta não é mais que b (as vezes esse chute tem que ser bom, para evitar overflow)

while(r > l+1){// repita enquanto o intervalo tiver tamanho > 2
    int mid = (l + r)/2;
    if(check(mid)){ // mid é válido
        r = mid; // como queremos minimizar a resposta, e mid é uma resposta válida
                //descartamos tudo a direita de mid (mas não mid)
    }
    else{
        l = mid+1; // Se mid não é válido, descartamos ele e tudo abaixo.
    }
}
// Ao final desse laço, a resposta pode estar em l ou r.
// Queremos minimizar a resposta, então se l for válido, 
// ficaremos com l, e caso contrário,  com r
int ans = r;
if(check(l)){
    ans = l;
}
```

#### Valor máximo (Maior valor que torna check verdadeiro)
```cpp
int l = a;
int r = b;
while(r > l+1){
    int mid = (l + r)/2;
    if(check(mid)){// mid é válido
        l = mid; // como queremos maximizar a resposta, e mid é uma resposta válida
                //descartamos tudo a esquerda de mid (mas não mid)
    }
    else{
        r = mid-1; // Se mid não é válido, descartamos ele e tudo acima.
    }
}
int ans = r;
if(check(l)){
    ans = l;
}
```
### Tipo2

#### Valor mínimo 
```cpp
int l = a;
int r = b;
while (l < r) {
    int mid = (l + r) / 2;
    if (check(mid)) r = mid;
    else l = mid + 1;
}
// a resposta fica em l
```

#### Valor máximo
É fácil alterar o código de valor mínimo para encontrar o valor máximo:
Imagine que uma função de check dê o resultado `[1,1,1,0,0]`. Veja que encontrar o último 1
nesse array é equivalente a encontrar o primeiro 0 e subtrair 1 da posição! Assim, podemos aplicar
a busca binária de valor mínimo **no valor contrário** do checker (`!check(mid)`) e subtrair 1 da resposta ao final.

```cpp
int l = a;
int r = b;
while (l < r) {
    int mid = (l + r) / 2;
    if (!check(mid)) r = mid; // check vira !check
    else l = mid + 1;
}
// a resposta fica em l-1
```

Detalhe: como usamos `l-1` no final, a busca não inclui `b`, ou seja, buscamos no intervalo `[a, b)`.


## Exemplos de aplicação

### Implementação de lower_bound
Consideremos o problema de achar o indice do primeiro elemento maior ou igual um `x` num vetor `v` de tamanho `n`.

```c++
int v[MAXN], n; // vetor global para facilitar o código

// funcao que retorna se id é uma resposta válida pro nosso problema
bool check(int id, int x){
    return v[id] >= x;
}

// retorna o indice do primeiro elemento >= x, considerando que o vetor v está ordenado
// se todos os elementos sao menores que x, retorna -1
int lower_bound(int x){
    int L, R, ans;
    L = 0; // começo do intervalo que consideraremos
    R = n-1; // fim do intervalo que consideraremos
    ans = n; // começamos a resposta com um valor fora do vetor, inválido para marcar se conseguimos achar alguma resposta ou nao
    while(L <= R){ // enquanto tiver algum número no intervalo
        int mid = (L+R)/2;
        if(check(mid, x)){ // se esse mid é uma resposta apropriada
            ans = mid; // achamos uma nova resposta para o problema
            R = mid-1; // se mid é uma resposta temos que tentar procurar uma resposta menor(nesse problema em especifico)
        }
        else{ // se mid nao é uma resposta pro nosso problema
            L = mid+1; // precisamos procurar em indices maiores(neste problema)
        }
    }
    if(ans == n) return -1; // se ans ainda é n depois da busca binária, então nunca achamos resposta
    return ans;
}
```

Perceba que se quisermos achar o indice do último elemento maior ou igual um `x` num vetor `v` de tamanho `n`.

```c++
long long
int v[MAXN], n; // vetor global para facilitar o código

// funcao que retorna se id é uma resposta válida pro nosso problema
bool check(int id, int x){
    return v[id] >= x;
}

// retorna o indice do primeiro elemento >= x, considerando que o vetor v está ordenado
// se todos os elementos sao menores que x, retorna -1
int lower_bound(int x){
    int L, R, ans;
    L = 0; // começo do intervalo que consideraremos
    R = n-1; // fim do intervalo que consideraremos
    ans = n; // começamos a resposta com um valor fora do vetor, inválido para marcar se conseguimos achar alguma resposta ou nao
    while(L <= R){ // enquanto tiver algum número no intervalo
        int mid = (L+R)/2;
        if(check(mid, x)){ // se esse mid é uma resposta apropriada
            ans = mid;  // achamos uma nova resposta para o problema
            L = mid+1; // se mid é uma resposta temos que tentar procurar uma resposta maior(nesse problema em especifico)
        }
        else{ // se mid nao é uma resposta pro nosso problema
            R = mid-1; // precisamos procurar em indices menores(neste problema)
        }
    }
    if(ans == n) return -1; // se ans ainda é n depois da busca binária, então nunca achamos resposta
    return ans;
}
```

Em ambos os exemplos a complexidade de checar se mid é uma resposta válida para o problema é `O(1)`. Portanto a complexidade total é `O(lg n)`.

Muitas pessoas ja viram o exemplo de realizar busca binária em vetores, mas quando se fala em busca binária na resposta, ficam confusas. Na verdade, busca binária em vetores é busca binária na resposta, mas a resposta é um índice.

# Material complementar
# Exercícios recomendados 

Estes exercícios não estão necessariamente em ordem de dificuldade.

 - https://codeforces.com/contest/1234/problem/A - Não é necessário busca binária mas é um exercício legal para aprender
 - https://codeforces.com/problemset/problem/817/C - Bem interessante, (se x é um numero realmente grande entao x+1 é realmente grande)
 - https://codeforces.com/problemset/problem/760/B - Se frodo não consegue ter x de altura então consegue ter x+1 de altura. Cuidado com overflows!
 - https://codeforces.com/gym/102346/problem/M - (Tente minimizar o quanto cada competidor come já que a resposta é em função do competidor que mais come)
