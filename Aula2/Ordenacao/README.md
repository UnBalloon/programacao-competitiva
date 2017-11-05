Ordenacao
=========

É facil ordenar usando c++. basta chamar a função sort().

Essa função recebe 2 argumentos, o primeiro é o endereço de memória do primeiro elemento do vetor, 
o segundo é o endereço de memória logo após o ultimo elemento do vetor.

Então se temos um bloco de memória v dessa forma: 
```
pos = [0,1 , 2,3,4]
v =   [0,15,10,9,4]
```

e chamamos sort(v, v+4), ficamos com: 
```
pos = [0,1,2 , 3,4]
v =   [0,9,10,15,4]
```

então de maneira geral, se temos um vetor v de tamanho n, para ordená-lo basta chamar sort(v,v+n)

Complexidade
-----------

A função sort tem complexidade O(n log n) onde n é o tamanho do intervalo a ordenar.
