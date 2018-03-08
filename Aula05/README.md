# Problemas de consulta em intervalos

Suponha que você se depare com o seguinte problema:

É dado um vetor V, com n números inteiros, em seguida, um número q de consultas que serão feitas nesse vetor. Cada consulta consiste de um par de inteiros (l,r), representando um intervalo, a resposta para cada consulta é a soma dos inteiros nesse intervalo(inclusivo).

Até agora, em qual complexidade sabemos resolver esse problema?

A solução simples seria: 
```cpp
int n;
int q;
cin >> n;
vector<int> v(n);
// leitura dos elementos
for(int i = 0; i < n; i++){
    scanf("%d",v+i);
}
cin >> q;
// respondendo as consultas
for(int i = 0; i < q; i++){
    int l, r;
    scanf("%d %d",&l,&r);
    int soma = 0;
    for(int j = l; j <= r; j++){
        soma += v[j];
    }
    cout << soma << endl;
}
```

Essa solução teria complexidade `O(q*n)` aonde `q` é o número de consultas, e `n` o tamanho do vetor. 


# Somas de prefixos

O vetor de somas prefixas é uma ED que podemos usar para resolver esse tipo de problema de forma mais eficiente. A ideia é construir um vetor P tal que `P[i]` representa a soma do índice 0 até o índice i.

Tendo essas informações, para responder uma consulta (l,r) podemos usar a seguinte ideia: sabe-se que em `P[r]` temos a resposta para a consulta (0,r), com isso, podemos agora subtrair a parte que não nos interessa, (0,l-1) ou `P[l-1]`.

## Construção 

A construção do vetor de somas prefixas em `v` tem complexidade `O(n)`. 

```cpp
vector<int> psum(v.size(), v[0]);
for(int i = 1; i < v.size(); i++) {
    psum[i] = v[i] + v[i-1];
}
```

## Resposta de consulta (l,r)

A resposta às consultas tem complexidade constante, já que são só acessos ao vetor. Apenas tem-se que tomar cuidado quando `l = 0`.

```cpp
int sum(int l, int r){
    if(l == 0)
        return psum[r];
	else
        return psum[r] - psum[l-1];
}
```

## Ressalvas 

Vale lembrar que essa ED é mais interessante de ser usada quando não há (ou há poucas) atualizações nos valores do vetor, caso haja, é necessário recomputar as somas prefixas do vetor todo em `O(n)`, o que não é uma complexidade atrativa. 

Além disso, esse raciocínio não precisa se extender apenas a somas, funciona para operações como xor, por exemplo.  


# Problemas de atualização em intervalos

Agora suponha que você se depare com um problema do seguinte tipo:

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

Tendo as informações organizadas dessa forma, isso nos permite percorrer o vetor `delta` da esquerda pra direita obtendo os valores finais do vetor, em `O(n)`.

 Isso é feito criando uma variável `atual`, inicializada com 0. Então, enquanto percorremos o vetor, na i-ésima iteração, sempre somamos a essa variável `delta[i]`, após isso, a configuração final de `v[i]` será o valor de `atual`. 

Então, é por esse motivo que guardamos a informação daquela forma no vetor. Como vamos percorrer da esquerda pra direita, quando fazemos `v[l] += x`, estamos dizendo, quando você passar no índice `l`, você deve adicionar mais `x` a resposta. E quando fazemos `v[r+1] -= x`, dizemos: quando seu índice for maior que `r`, pare de considerar x no resultado.

Dessa forma, a versão final: 

```cpp
vector<int> delta(n,0);
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
