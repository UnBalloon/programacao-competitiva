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

Vale lembrar que essa ED só pode ser usada quando não há atualização nos valores do vetor, caso haja, é necessário recomputar as somas prefixas do vetor todo em `O(n)`. 

Além disso, esse raciocínio não precisa se extender apenas a somas, funciona para operações como xor, por exemplo.  


# Delta encoding

Imagine um problema parecido, porém com `q` atualizações e no final quer saber o soma de valores de um intervalo. Soma de Prefixos executaria em `O(q*n)`. Delta encoding é uma ED que executa em `O(q)`, pois atualiza em `O(1)`.

A ideia é construir um vetor  `d` tal que  `d[i]` seja a variação (delta) em relação a `d[i-1]`. Assim, somar mais `v`  em `[l, r]` não altera `(l-r)` deltas, apenas `d[l]`  e `d[r+1]` (que são as bordas relativas do intervalo) .

## Construção

A construção do vetor do delta encoding em `v` tem complexidade `O(n)`. 

```cpp
vector<int> d(v.size(), v[0]);
for(int i = 1; i < v.size(); i++) {
    d[i] = v[i] - v[i-1];
}
```

## Atualização de [l,r]

A atualização tem complexidade constante, já que são só acessos ao vetor.

```cpp
void update (int l, int r, int value){
    d[l] += value; 
    if (r+1 < d.size()) 
        d[r+1] -= value;
}
```

## Ressalvas

Vale lembrar que essa ED serve para quando se tem muitas atualizações e poucas buscas, já que uma soma no intervalo é  `O(n)`. 

Assim como Soma de Prefixos, pode ser usado de outras formas.

# 