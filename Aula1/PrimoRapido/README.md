Verificando Primalidade
-----------------------


Esse é um ótimo exemplo para mostrar como a complexidade impacta no tempo de execução de um algoritmo.

Quando se pensa em verificar se um número é primo ou não, a primeira ideia que vem a cabeça é verificar se 
nenhum número a baixo dele o divide, e funciona. Porém tem complexidade O(n). Mas é possível fazer melhor


Observe o seguinte exemplo, o numero 36.
Seus divisores são 1,2,3,4,6,9,12,18 e 36, de forma que

```
1 * 36 = 36
2 * 18 = 36
3 * 12 = 36
4 * 9  = 36
6 * 6  = 36
```

Com isso, dá pra perceber pra todos os divisores, caso ele esteja antes da raiz,
ele tem um par após a raiz (exceto pela raiz que é seu próprio par)

Isso pode ser demonstrado da seguinte forma.

Suponha que há 2 divisores d1 e d2 de um número n tais que d1*d2 = n, e que ambos sejam maiores que a raiz


n = sqrt(n) * sqrt(n), mas d1,d2 > sqrt(n), então

d1 * d2 > n, ou seja, a existencia de tais divisores é contraditória, portanto no podem existir.

Então, se um número tem um divisor diferente de 1, é necessário que haja um divisor menor ou igual a sua raiz.

Então, podemos sair verificando apenas os números a baixo da raiz de n, em O(sqrt(n)).

Execute os exemplos primo lento e primo rápido para ver a diferença.


