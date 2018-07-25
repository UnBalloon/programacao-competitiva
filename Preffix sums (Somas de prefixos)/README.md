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
    psum[i] = v[i] + psum[i-1];
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