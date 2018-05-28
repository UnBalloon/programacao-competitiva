## Dijkstra

O algoritmo de Dijkstra é um algoritmo muito conhecido para percorrimento de grafos cujas arestas te pesos, ele nos permite percorrer os vértices na ordem de distância para um vértice fonte. 

Mais especificamente, de uma forma tal que considerando o vértice fonte como `s`, se o menor caminho de `s` para um vértice `u` é estritamente menor que o menor caminho de `s` para um outro vértice `v`, com certeza visitaremos `u` antes de `v`.

A forma como o algoritmo opera é muito parecida com o BFS, mas em vez de usarmos uma fila, usamos uma fila de prioridades(priorizando menores valores). O motivo de usarmos essa outra estrutura de dados é que usar uma fila não gera mais o mesmo comportamento que desejamos quando as arestas passam a ter pesos. 

Como as arestas tem pesos, nosso grafo será um `vector<pair<int,int>> grafo[n]` ao invés de um `vector<int> grafo[n]`.

### A ideia

Assim como no BFS, teremos essa fila que ditará a ordem com que os nodos serão desenfileirados (visitados). Mas agora Nossa Fila é de prioridades abriga pares ao invés de apenas um inteiro.

Pra qualquer par `p` na fila, `(p.first,p.second)` significa: Consigo chegar no vértice `p.second` por um caminho de custo `p.first`. Por isso no começo da execução enfileiramos o par `(0, s)`, dizendo: consigo chegar no vértice fonte pagando 0, afinal já estamos nele no começo do percorrimento.

Quando desinfileiramos um vértice, assim como no BFS, consideramos todas as arestas que partem dele, agora com pesos. 



Há diversas formas de implementar o algoritmo, é possível usar um vetor indicando quais vértices foram visitados, assim como no BFS e DFS, mas outra forma é usar um vetor que indica as menores distâncias


### Implementação

```c++
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = 100005;
const ll oo = 1e18;

ll d[N]; // vetor onde guardamos as distancias

int n; // numeros de vertices

// lista de adjacencias guarda
// pair <vertice para onde a aresta vai, peso da aresta>
vector<pair<int, ll>> g[N];

void dijkstra(int start){

	// inicialmente a distancia do vertice
	// start para todo os outros é infinita
	for(int u = 1; u <= n; u++)
		d[u] = oo;

	// fila de prioridade de pair<ll, int>, mas que o
	// menor pair fica no topo da fila
	// guardamos um pair <distancia ate o vertice, vertice>
	// assim o topo da fila sempre é o vertice com menor distancia
	priority_queue<pair<ll, int>, vector<pair<ll, int>>,
		greater<pair<ll, int>> > pq;

	d[start] = 0;
	pq.emplace(d[start], start);

	ll dt, w;
	int u, v;
	while(!pq.empty()){
		tie(dt, u) = pq.top(); pq.pop();

		for(auto edge : g[u]){
			tie(v, w) = edge;

			// se a distancia ate o u somado com o peso
			// da aresta é menor do que a distancia ate o v que
			// tinhamos antes, melhoramos a distancia ate o v
			if(d[v] > d[u] + w){
				d[v] = d[u] + w;
				pq.emplace(d[v], v);
			}
		}
	}
}


int main(){

	// lê o input, qnt de vertices, arestas
	// e vertice inicial(start)
	
	dijkstra(start);

	for(int u = 1; u <= n; u++){
		printf("Distancia de %d para %d: %lld\n", start, u, d[u]);
	}

}
```
