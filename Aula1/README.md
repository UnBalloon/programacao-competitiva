Complexidade
============

O tema da primeira aula é Complexidade de algoritmos.

O que é Complexidade?
---------------------

Em linhas gerais, a complexidade de um algoritmo é o quanto as variáveis de entrada impactam no seu tempo de execução.

Para se referir a complexidade de um algoritmo, se usa a notação O(complexidade). A quantidade de operações que os computadores atuais executam em um segundo é por volta de 10^8, portanto podemos estimar o tempo de execução de um programa usando análise de complexidade. Basta fazer o cálculo de complexidade e dividir por 10^8, e a resposta será aproximadamente o tempo de execução em segundos.


Exemplos:


```cpp
  printf("Hello World\n");
```

Esse código tem complexidade O(1) (também chamado de complexidade constante), porque nenhuma variável de entrada impacta no seu tempo de execução.

```cpp
int n;
scanf("%d",&n);
for(int i = 0; i < 10*n; i++){
    printf("%d\n",i);
}
```


Esse código tem complexidade O(n), pois o seu tempo tempo de execução cresce linearmente dependendo da variável n.


Multiplicação de Matrizes
---------------------
Se você não ~~sabe~~ lembra como multiplicar matrizes visite [aqui](http://www.somatematica.com.br/emedio/matrizes/matrizes4.php) e [aqui](https://www.youtube.com/watch?v=4cgHNvfMICg).

O código abaixo computa C = A * B, onde A é uma matriz n por p e B é uma matriz p por m.

```cpp
for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
        C[i][j] = 0;
        for(int k = 0; k < p; k++){
            C[i][j] += A[i][k] * B[k][j];
        }
    }
}
```
Como os fors estão aninhados a complexidade do código é a multiplicação das complexidades de cada for, sendo então, O(n\*m\*p).

Ordenação
---------------------
Um problema bastante estudado é o de ordenação. Existem vários algoritmos resolvem o problema eficientemente, não será mostrado um desses. O código a seguir ordena um vetor ```v``` de tamanho ```n```.

```cpp
for(int i = 0; i < n; i++){
    for(int j = i; j < n; j++){
        if(v[i] > v[j]){
            tmp = v[i];
            v[i] = v[j];
            v[j] = tmp;
        }
    }
}
```
A quantidade de vezes que o segundo loop executa depende do i, então é um pouco mais difícil de analisar a complexidade.

Ao longo das iterações do primeiro loop, a quantidade de iterações do segundo é ```n + (n-1) + (n-2) + (n-3) + ... + 1```, ou seja, é soma de [PA](https://educacao.uol.com.br/disciplinas/matematica/progressao-artimetica-pa-formula-da-soma-e-do-termo-geral.htm) e podemos resolver para O(```(n+1)*n/2```). Em análise de complexidade só nos importamos com quando as variáveis são muito grandes(tendem a infinito), de um modo bem bruto infinito e infinito/2 dá no mesmo, então podemos escrever a complexidade como O(```(n+1)*n```). Novamente quando pensamos em números bem altos ```n``` e ```n+1``` se tornam praticamente a mesma coisa e podemos concluir que a complexidade é O(```n^2```).

Portanto podemos dizer que a complexidade do código acima é O(```(n+1)*n/2```), O(```(n+1)*n```) ou O(```n^2```). Mas geralmente optamos pela forma mais simples que é O(```n^2```).


Fibonacci
---------
(Se você ainda não aprendeu recursão, talvez não entenda esse exemplo)
```cpp
int fibonacci(int n){
    if(n == 0)
        return 0;
    if(n == 1)
        return 1;
    return fibonacci(n-1) + fibonacci(n-2);
}
```

A famosa função de fibonacci. Essa função recursiva é bem bonita de se ver declarada, mas tem uma complexidade horrível.

Pense que queremos Calcular Fibonacci(4)

                               
                                      4   
                                   /    \
                                  3      2
                                 / \    / \
                                2   1  1   0 
                               / \
                              1   0
                              
Essa a árvore formada pelas chamadas recursivas, olhe quantas vezes recomputamos as mesmas coisas. A complexidade dessa função é O(```2^n```), pois para cada chamada de fibonacci recursiva, fazemos outras duas, e acabamos recomputando várias vezes as mesmas coisas. Implemente essa função em sua máquina e faça uma chamada de fibonacci(35), já deve ser possível sentir o tempo que o programa leva para processar isso. 
