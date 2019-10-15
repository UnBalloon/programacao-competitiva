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




## Exercícios recomendados
- https://codeforces.com/problemset/problem/208/e
- https://www.urionlinejudge.com.br/judge/pt/problems/view/2470
- https://www.urionlinejudge.com.br/judge/pt/problems/view/1135
