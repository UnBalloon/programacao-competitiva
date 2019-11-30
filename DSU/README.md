# Disjoint-Set/Union-Find

> É recomendado que você leia as aulas de [conceitos de grafos](/Grafos/) e [detecção de ciclos](/Detecção%20de%20ciclos/) antes dessa.

Uma das estruturas de dados mais elegantes existentes é o Union-Find, também conhecido como Disjoint-Set, Merge-Find e DSU. 
O problema que essa ED resolve é o seguinte: dados vários conjuntos disjuntos, como podemos saber se dois elementos 
estão no mesmo conjunto ou não, além de poder unir dois conjuntos, tudo isso em tempo rápido?
Uma DSU realiza essas duas operações em tempo praticamente constante!

![concept](https://imgur.com/7UF6cLRm.png "Conjuntos disjuntos de números")

# Operações
Podemos fazer 4 operações em um Union-Find:
1. **MakeSet/Build:** Inicializa a estrutura de dados.
2. **Find(X):** Encontra o "id" do conjunto que contem o elemento X.
3. **SameSet(X, Y):** Verifica se X e Y pertencem ao mesmo conjunto.
4. **Join/Merge/Union(X, Y):** Encontra os conjuntos que contém X e Y, e une os dois.

# A Ideia
O truque que podemos usar para saber se dois números estão no mesmo conjunto é escolher um "elemento representante" para cada conjunto:

![representante](https://imgur.com/OpWvushm.png "Representantes")

Agora dois elementos pertencem ao mesmo conjunto se (e somente se) eles tem o mesmo representante. Mas como podemos achar esse elemento, dado qualquer um dos elementos do conjunto? Simples, podemos manter um vetor `P[]`, onde P[x] = representante. Visualizamos isso como uma setinha/ponteiro para P[x]:

![parent pointers](https://imgur.com/046YbLXm.png "Ponteiros para os representantes")

Perceba que os representantes são os elementos que apontam para eles mesmos (P[x] = x).

# Union
Com isso, as operações de Find e SameSet ficam triviais, mas como seria a de Union? Suponha que temos dois conjuntos A e B, cada um com N elementos. Para unir A e B podemos fazer todos os elementos de B apontarem para o representante de A. Isso funciona, mas é muito lento (O(N) por Union). Podemos fazer melhor com uma modificação simples na estrutura.

![dsu union 1](https://imgur.com/wyvZvpcm.png)

Em vez de mudar os ponteiros de todos os elementos de B, vamos fazer apenas o representante de B apontar para o de A:

![dsu united](https://imgur.com/oE64rN7m.png)

Agora o Union funciona em O(1)! Mas nosso Find quebrou. O Find de 4, por exemplo, será P[4] = 3, mas 3 não é representante! Consertar isso é simples, basta pegar P[x] sucessivamente até termos um representante (até ter P[x] = x). Estamos basicamente subindo na árvore formada até encontrar a raiz. Já podemos escrever o código de todas as operações:

```cpp
int P[100005];
 
void Build() {
  // Apontamos cada número para ele mesmo, para fazer N conjuntos disjuntos
  for (int i = 0; i < 100005; i++)
    P[i] = i;
}

// versão iterativa
int Find(int x) {
  while (P[x] != x)
    x = P[x];
   return x;
}

// versão recursiva
// É importante aprender essa versão antes de continuar para as otimizações
int Find(int x) {
  if (P[x] == x) {
    return x;
  }
  return Find(P[x]);
}

void Union(int x, int y) {
  P[Find(x)] = Find(y); // aponta o representante de x para o de y
}
```

# Otimizações
Nosso Union-Find está ficando melhor, mas ainda não faz tudo em O(1), porque a árvore pode ter altura muito grande, o que gera operações Find em O(N). Há duas maneiras de diminuir essa altura:

## Path Compression
Sempre que chamamos Find(x) vamos subir na árvore até encontrar o representante, que vamos chamar agora de `R`. Concorda que o conjunto não muda se fizermos `P[x] = R`? É exatamente isso que path compression faz, mas não só para x, aplicamos a compressão recursivamente em todo o caminho de `x` até a raiz.

![dsu path compression](https://imgur.com/8KPBKfJm.png)

A implementação disso é bem simples
```cpp
int Find(int x) {
  if (P[x] == x) {
    return x;
  }
  return P[x] = Find(P[x]); // Só colocamos um "P[x] =" nessa linha
}
```

Aplicar só essa otimização já deixa o Find em [O(log N)](http://e-maxx.ru/bookz/files/dsu/Efficiency%20of%20a%20Good%20But%20Not%20Linear%20Set%20Union%20Algorithm.%20Tarjan.pdf).

## Union by size
Enquanto o path compression diminui a altura, o union by size faz as uniões aumentando a altura o mínimo possível. A ideia é que se vamos unir X e Y, e o conjunto de X é menor que o de Y, é melhor apontar X->Y do que Y->X. Vamos então guardar a informação de tamanho de um conjunto no array `S[]`. Importante: com path compression esse array pode não estar certo em todo índice, mas ele sempre está certo para um índice que é representante. O código fica assim:

```cpp
int P[100005], S[100005];

void Build() {
  // Também precisamos inicializar os tamanhos de cada conjunto
  for (int i = 0; i < 100005; i++)
    P[i] = i, S[i] = 1;
}

void Union(int x, int y) {
  x = Find(x);
  y = Find(y);
  if (x == y) return;
  if (S[x] > S[y]) swap(x, y); // depois disso x é o conjunto menor
  P[x] = y;
  S[y] += S[x];
}
```

Com isso, as operações de Find podem ser feitas em O(log N) sem compressão de caminhos. Provar isso fica como exercício ao leitor. 

Utilizando tanto path compression quanto union by size podemos fazer o Find em O(α(N)), onde α é a função inversa de Ackermann. Essa função cresce tão lentamente que é mais fácil considerar ela igual a O(1), mas não escreva isso em uma prova.

Há outras otimizações possíveis que também deixam o Find em O(α(N)), que podem ser encontradas na [Wikipedia](https://en.wikipedia.org/wiki/Disjoint-set_data_structure#Operations).

# Problemas
> Tente resolver por 10-15 minutos antes de olhar a solução

## [News Distribution](https://codeforces.com/problemset/problem/1167/C)
<details>
 <summary>Solução</summary>
 Um dos jeitos de resolver essa questão é representar os usuários por vértices em um grafo. Se dois usuários estão no mesmo grupo, colocamos uma aresta entre eles. Agora, a resposta para um usuário é o tamanho da componente conexa em que ele se encontra. // TODO: explicar melhor
</details>

[Código](https://codeforces.com/contest/1167/submission/65958807)

# Material Extra
+ Visualização interativa: https://visualgo.net/en/ufds
