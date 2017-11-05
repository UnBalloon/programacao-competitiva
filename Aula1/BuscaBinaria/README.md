Busca Binaria
=============

Busca Binária na resposta
-------------------------
Vamos começar com um exemplo:


Suponha que você tenha que resolver o seguinte problema, você tem que encontrar a raiz quadrada de um número, mas não pode usar a função sqrt().

Esse é um problema que pode ser solucionado por meio de busca binária.

O exemplo de busca binária está implementado nesse diretório.

A ideia é a seguinte:

Se X é positivo, sua raiz quadrada tem que estar entre 0 e x+1 (x+1 porque no caso de números entre 0 e 1, a raiz é maior que o próprio número)



```

0                 meio               x+1

O------------------|------------------O

```






verificamos se meio^2 é maior que x, caso seja, como a função é crescente, significa que a raiz quadrada está abaixo do meio, caso contrário está acima do meio. Dessa forma, em cada iteração da busca, conseguimos reduzir o espaço aonde a raiz está contida por 2.


Então suponha que queremos encontrar a raiz de 9.

```

0                 meio               9+1

O------------------|------------------O
```

meio = (0 + 10) / 2 = 5

5^2 = 25, que é maior que 9, então a raiz de 9 é menor que 5, portanto cortamos todo o intervalo acima de meio fora do espaço de busca, e meio se torna o novo limite superior.

```
0                 meio                5

O------------------|------------------O
```

meio = (0 + 5) / 2 = 2.5

2.5 ^ 2 = 6.25, que é menor que 9. Então descarta-se tudo abaixo do meio.

```
2.5                 meio              5

O------------------|------------------O
```

meio = (2.5 + 5) / 2 = 3.75

3.75^2 = 14.06, que é maior que 9.

```
2.5                 meio             3.75

O------------------|------------------O
```

```
.
.
.
```

Após umas 50 iterações, o intervalo já será pequeno o suficiente para termos a raiz de 9 com uma boa precisão. e é possível ver que a resposta convergirá para 3.



Busca Binária em vetores
------------------------

Imagine que você tem vários inteiros em um vetor V, e é necessário frequentemente verificar uma informação do tipo

X está em V?

Qual o primeiro inteiro maior que X presente em V?

Suponha que quero saber se Y está em V.

Uma solução possível para esse problema é:
```
int esta_em_v(int y){
    for(int i = 0; i < n; i++){
        if(v[i] == y)
            return 1; // retorna verdadeiro
    }
    return 0; // retorna falso
}
```

Que funciona em complexidade O(n), para cada consulta, aonde n é o tamanho do vetor.

Mas uma outra abordagem possível é a seguinte.

Ordene o vetor, (Ordenação será abordada na aula 2, porém, saiba que é possíver ordenar um vetor de tamanho n em O(n * log(n)), é necessário que o vetor esteja ordenado para realizar a busca. 

Dessa forma, ao acessar um indice do vetor e ver seu valor, saberemos que caso o número esteja no vetor, estará a esquerda ou a direita daquele índice. Para o proximo exemplo suponha que v já está ordenado.

```
int esta_em_v(int y)
{
    int l = 0;
    int r = n-1;
    int mid;
    while(r > l){
        mid = (l + r)/2;
        if(v[mid] == y) // encontramos y
            return 1;
        else if(v[mid] > y) // y esta a esquerda de mid
            r = mid-1;
        else // y esta a direita de y
            l = mid+1;
    }
    // é necessária essa ultima verificação pois
    // pode ser que na ultima iteração, quando l se 
    //igualou a r e o loop quebrou, o mid seja o que queremos
    if(v[mid] == y)
        return 1;
    else
      return 0; // nao encontramos y 
}
```

Complexidade
------------
Para valores inteiros:

Seja k o menor número tal que ``` 2^k > n ``` , aonde n é o tamanho do intervalo aonde a resposta pode estar.

Se em cada iteração o intervalo de busca é dividido por 2, sabemos que  para um intervalo de tamanho 2^k se transformar em um intervalo de tamanho 1, precisamos dividir por 2 exatamente k vezes.

então a complexidade em funcão de k seria ``` 2^k = n ```, se colocarmos em função do tamanho do intervalo n, aplicando log2 de ambos os lados, 

``` 
log2(2^k) = log2(n)
k = log(n)
```


Para valores em ponto flutuante:

Analogo ao caso inteiro, a complexidade também é logarítmica, mas por exemplo, se é necessário uma busca binária com precisão 10^-6, serão necessárias mais iterações que pra precisão de 10^-3, por isso, formalmente, seja p a precisao desejada, a complexidade será log2(2^(-p)). Em termos de implementação, cerca de 100 repetições já é suficiente para obter uma precisão da ordem de 10^-9, então, assim como no exemplo da raiz quadrada, basta iterar 100 vezes e o valor de l ou de r será bastante preciso. 









