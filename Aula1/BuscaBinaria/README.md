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










