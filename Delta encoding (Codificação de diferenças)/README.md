# Problemas de atualização em intervalos

Suponha que você se depare com um problema do seguinte tipo:

Você recebe um vetor `v` , inicialmente com todos seus números zerados, e `q` queries. cada query virá representada por 3 inteiros (l,r,x). Ao receber cada query, a mudança esperada é: "Para cada número no vetor, seja `i` o seu índice. Se `l <= i <= r`, v[i] deve ter x adicionado ao seu valor. Ao final do programa, deve-se imprimir o vetor todo com seus valores atualizados.

A primeira solução que já vem a cabeça é a seguinte:

```cpp
int n,q;
	
scanf("%d %d",&n,&q);
vi v(n,0);

for (int i = 0; i < q; ++i){
    int l,r,x;
    scanf("%d %d %d",&l,&r,&x);

    for (int j = l; j <= r; ++j){
        v[j] += x;
    }
}
```

Nessa solução, para cada uma das `q` queries, o pior caso seria `l = 0` e `r = n-1`, que faz o laço interno iterar `n` vezes, o que nos dá uma complexidade `O(n*q)`. Precisamos ser mais rápidos.

# Delta encoding

Delta encoding é uma técnica para resolver problemas desse tipo. Precisamos fazer atualizações em intervalos, mas como o vetor só precisa ser visualizado no final, o que fazemos é fazer todas de uma vez só no final. A ideia por trás dessa solução funciona da seguinte forma: Vamos criar um vetor auxiliar `delta`, que é o vetor que vai acumular as atualizações. 


## Atualização do intervalo (l,r)

Dessa forma, quando estivermos lendo uma query (l,r,x), faremos o seguinte:

```cpp
vector<int> delta(n,0);
for(int i = 0; i < q; i++){
    int l,r,x;
    scanf("%d %d %d",&l,&r,&x);
    delta[l] += x;
    delta[r+1] -= x;
}
```

O trecho de código acima é o delta encoding por si só, o nome é esse porque estamos codificando a informação de que precisamos atualizar aquele intervalo. A parte interessante, é que nesse laço, nossa atualização funciona em `O(1)`.


## Obtendo os valores após várias atualizações

Tendo as informações organizadas dessa forma, isso nos permite percorrer o vetor `delta` da esquerda pra direita obtendo os valores finais do vetor, em `O(n)`.

 Isso é feito criando uma variável `atual`, inicializada com 0. Então, enquanto percorremos o vetor, na i-ésima iteração, sempre somamos a essa variável `delta[i]`, após isso, a configuração final de `v[i]` será o valor de `atual`. 

Então, é por esse motivo que guardamos a informação daquela forma no vetor. Como vamos percorrer da esquerda pra direita, quando fazemos `v[l] += x`, estamos dizendo, quando você passar no índice `l`, você deve adicionar mais `x` a resposta. E quando fazemos `v[r+1] -= x`, dizemos: quando seu índice for maior que `r`, pare de considerar x no resultado.

Dessa forma, a versão final: 

```cpp
vector<int> delta(n+5,0);
vector<int> v(n);

for(int i = 0; i < q; i++){
    int l,r,x;
    scanf("%d %d %d",&l,&r,&x);
    delta[l] += x;
    delta[r+1] -= x;
}

int atual = 0;

for(int i = 0; i < n; i++){
    atual += delta[i];
    v[i] = atual;
}

for(int i = 0; i < n; i++){
    printf("%d ",v[i]);
}
printf("\n");

```

## Ressalvas

Análogo as somas prefixas, mas de forma inversa, essa ED processa atualizações em intervalo muito rapidamente `O(1)`, porém, quando é necessário saber os valores do vetor, e há atualizações pendentes, é necessário percorrer novamente o vetor todo `O(n)`, então essa ED funciona melhor com muitas atualizações e poucas consultas.
