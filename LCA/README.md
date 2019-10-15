# Lowest Common Ancestor (LCA)

Lowest Common ancestor (LCA) - ou ancestral comum mais baixo, é o nome típico dado para o seguinte problema: dado uma Árvore cuja raiz é um vértice arbitrário `e` dois vértices `u,v` que a pertencem, diga qual é o nó mais baixo(relativo a raiz) que é ancestral de `u,v`. 

![a](https://i.imgur.com/OuGPlXf.png "a")

Por exemplo na imagem a cima, o LCA de 2 e 3 é 1, o LCA de 6 e 7 é 0, e o LCA de 1 e 2 é 1.

um jeito naive de se fazer isso seria o seguinte, para cada nó da árvore, pré-processamos sua profundidade com relação a raiz (raiz tem profundidade 0, filhos 1, e assim por diante). Agora, para determinarmos os LCA de dois vértices `u,v`, podemos fazer o seguinte procedimento. Escolhemos qual dos dois vértices está mais profundo, subimos nos seus pais até igualar as alturas de ambos, e após isso, vamos subindo em ambos os caminhos um a um até que os caminhos se encontrem, então saberemos o LCA.

```cpp

int depth[100005];
vector<int> graph[100005];

void pre_process_depth(int u, int d) {
	depth[u] = d;
	for(auto adj : graph[u]) {
		pre_process_depth(adj, d + 1);
	}
}

int slow_lca(int u, int v) {
	if(depth[u] < depth[v]) {
		swap(u, v);
	}
	while(depth[u] > depth[v]) {
		u = pai[u];
	}
	while(u != v) {
		u = pai[u];
		v = pai[v];
	}
	return u;
}

```
Essa estratégia efetivamente funciona, então teríamos um pré-processamento que é um DFS e após isso conseguiríamos responder queries em `O(n)`, pois numa árvore com um ramo muito profundo teríamos no pior caso que subir todos os vértices, portando complexidade overall de `O(n + Qn) = O(Qn)` onde `Q` é o número de queries e `n` a quantidade de nós na árvore.

O LCA é relevante porque como em uma árvore há um único caminho que liga dos vértices, se conseguimos obter o LCA rápido então uma das coisas que já ganhamos de quebra é conseguir responder as distâncias entre quaisquer par de vértices, já que a distância vai ser a distância de um vértice para o LCA e do LCA para o outro, sendo que essas duas distâncias intermediárias são apenas a diferença de alturas na árvore.

Aqui nesse tutorial vamos mostrar duas ideias para computar LCA, uma que vai nos permitir responder Queries de LCA em `O(log n)` com preprocessamento `O(n log n)` e uma segunda abordagem que vai nos permitir responder queries de LCA em `O(1)` (isso mesmo, tempo constante!) com preprocessamento `O(n log n)` também. 

Apesar de a complexidade da segunda abordagem para responder queries de LCA ser estritamente melhor que da primeira, veremos que a primeira carrega um pouco mais de informação, permitindo obter algumas outras informações fora o LCA, enquanto na segunda podemos obter apenas o LCA.

# Abordagem 1

O problema da solução naive é essa subida de um em um até que atinjamos o pai comum. Então faz sentido tentarmos atacarmos isso para ganhar um desempenho assintótico melhor. Uma coisa a se observar é que estamos fazendo duas buscas lineares. A primeira busca linear é pelo primeiro ancestral de `u` que iguala a altura a `v` e após isso outra busca linear para procurar o primeiro ancestral de ambos que é comum. 

Podemos observar que há uma espécie de monotonicidade nessas busca linear, até certo ponto os ancestrais não satisfazem uma condição, e após certo ponto todos satisfazem. Na primeira estaríamos buscando o ancestral mais baixo de `u` que satisfaz a condição "Ter altura menor ou igual a v", e na segunda busca estaríamos buscando algo como "o menor número de níveis que temos que subir na árvore que faz com que `u,v` se encontrem".

 Se nós tivéssemos uma função *mágica* chamada por exemplo `climb(n,k)` que nos retornasse o k-ésimo pai do vértice `n`, poderíamos então usar buscas binárias na quantidade de vértices a subir para resolver esse problema, e restaria implementar essa função de maneira eficiente. Vamos seguir por essa linha de raciocínio então.

 ## O pulo do gato

Se nós tivéssemos uma outra função `mágica` chamada `p2k(n,k)` que retorna o (2^k)-ésimo pai de um vértice `n`, poderíamos implementar a função que sobe `k` vértices da seguinte maneira. Se nosso grafo tem tamanho menor que `10^6`, sabemos que não precisamos subir mais do que `2^20`.

```cpp
int climb(int node, int k){
	for(int i = 20; i >= 0; i--) {
		if(k >= (1 << i)) {
			node = p2k(node,i);
			k -= (1 << i);
		}
	}
	return node;
}
```

A complexidade dessa função depende do número que colocamos no for, que não precisa ser maior do que o `log` do tamanho do grafo(não faz sentido subir mais nós do que o grafo possui), então conseguimos obter o k-ésimo ancestral de um vértice arbitrário em complexidade `O(log) * X` aonde X é a complexidade de p2k.

Mostramos agora que podemos preprocessar todos os valores possíveis de p2k em `O(n log n)`. Precisamos saber os valores dos ancestrais para todos os `n` vértices e para cada vértice só faz sentido saber `log` ancestrais. Podemos obter todos os valores de uma vez usando programação dinâmica, com uma recorrência muito elegante. 

```cpp
int p2k(int node, int k) {
	if(k == 0) {
		return pai[node];
	}
	return p2k(p2k(node, k-1),k-1);
}

```
### Versão recursiva

Usamos então memoização para computarmos cada estado em `O(1)`

```cpp
int memo[GRAPH_SIZE][log2(GRAPHSIZE)];

int p2k(int node, int k) {
	if(k == 0) {
		return pai[node];
	}
	if(memo[node][k] != -1) {
		return memo[node][k];	
	}
	return memo[node][k] = p2k(p2k(node, k-1),k-1);
}
```
### Versão iterativa

```cpp
int p2k[GRAPH_SIZE][log2(GRAPH_SIZE)];
for(int node = 0; node < GRAPH_SIZE; node++) {
	p2k[node][0] = pai[node];
}
for(int node = 0; node < GRAPH_SIZE; node++) {
	for(int k = 1; k <= log2(GRAPH_SIZE); k++) {
		p2k[node][k] = p2k[p2k[node][k-1]][k-1];
	}
}
```

Dessa forma então temos o seguinte procedimento para acharmos o LCA, fazemos uma busca binária, em cada iteração obtemos o k-ésimo ancestral, e checamos se ele satisfaz as propriedades, tendo então complexidade `O(log n * log n) = O(log^2 n)`, já que fazemos `log` iterações e em cada iteração demoramos `log` para obter o k-ésimo ancestral. Isso funciona, mas podemos melhorar um pouco mais.

## Exercícios recomendados
- https://codeforces.com/problemset/problem/208/e
- https://www.urionlinejudge.com.br/judge/pt/problems/view/2470
- https://www.urionlinejudge.com.br/judge/pt/problems/view/1135
