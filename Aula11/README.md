# Percorrimento de grafos


## Percorrimento em largura

Uma das formas de percorrer um grafo é fazer um percorrimento em largura. Começamos a explorar os vértices do grafo a partir de um certo vértice `a`. E a ordem que vamos navegando entre os vértices é de forma que os mais próximos a `a` sempre serão visitados antes. Então, primeiro `a` será visitado, depois os vértices que são adjacentes a `a`(distância 1), depois os vértices que estão a duas arestas de distância, e assim por diante. Como os vértices mais próximos são sempre visitados antes, esse algoritmo serve para, por exemplo, dizer qual a distância mínima entre dois vértices no grafo.

Esse comportamento é implementado usando-se uma fila. Primeiro insere-se na fila o vértice inicial, e começa-se a desenfileirar da fila enquando houver algum nodo. Quando um vértice `a` é desenfileirado, enfileram-se todos os vértice adjacentes a `a` que não foram visitados. Caso não marquemos os visitados, e o grafo tiver ciclos, nosso programa não terminará.

O algoritmo a baixo é um BFS que simplesmente percorre o grafo.

```cpp
void bfs(int start){
    
    queue<int> q;
    q.push(start);

    vector<bool> visited(GRAPH_MAX_SIZE,false);

    while(q.size()){//Enquanto houver vértices na fila

        // Retire o vértice da frente
        int u = q.front();
        q.pop();
        visited[u] = true;

        for(int w: graph[u]){ // Para cada vértice adjacente a u
            if(!visited[w]){
                q.push(w);
            }
        }
    }

}
```
A complexidade desse código é `O(n+m)`, temos no máximo n vértices enfileirados, e no loop interno, cada iteração é considerar uma aresta, como não estamos voltando no grafo, não passaremos por uma aresta mais que duas vezes naquele loop. Então, em todas as chamadas, aquele loop iterará no pior caso m vezes.




## Percorrimento em profundidade

outra forma de percorrer um grafo é fazer percorrimento em profundidade, também de chamado de DFS(Depth-first search). O algoritmo  se chama assim porque funciona de uma forma que sempre vamos 'mergulhar' no grafo o mais fundo que pudermos. Quando não for mais possível ir mais fundo no grafo, voltamos até que seja ir mais fundo novamente, sem repetir vértices já visitados.

A implementação do DFS mais comum é recursiva, por ser mais intuitiva. Assim como o exemplo anterior, esse programa simplesmente percorre o grafo, mas na ordem que um DFS percorre.

```cpp
vector<vector<int>> graph;
vector<bool> visited;     // globais, inicializados na main.

void dfs(int vertex){ // na main chamamos dfs(start), aonde start é o vértice que começamos o dfs
    visited[vertex] = true;

    for(int w: graph[vertex]){
        if(!visited[w]){
            dfs(w);
        }
    }    
}
```
A complexidade desse código é `O(n+m)`, temos no máximo `n` chamadas recursivas, e no loop interno às chamadas, assim como no BFS, estaremos considerando uma aresta e não passaremos nela mais de uma vez. Então no máximo `m` iterações ao longo de todas as chamadas.



# Mais sobre grafos

## Detecção de ciclos

Detectar ciclos em um grafo é algo que é necessário com bastante frequência, muitas vezes porque um caso de borda do problema envolve o grafo ter ciclos e solução para aquele caso deve ser tratada separadamente. A detecção é diferente no caso do grafo ser direcionado ou não-direcionado, isso porque como no caso do não-direcionado, pra toda aresta (a,b) tem-se (b,a), o algoritmo usado em grafos direcionados detectaria um ciclo de tamanho 2, mas não é o caso.


### Direcionado

Para detectar ciclos em grafos direcionados, uma das abordagens possíveis é fazer um 'dfs com cores'. Isso quer dizer que enquanto percorremos nosso grafo, iremos colorindo os vértices de cinza e de preto, sendo que todos os vértices começam com a cor branca. Cada cor tem o seguinte significado:

- Branco: Não visitado
- Cinza: visitado, mas ainda está na pilha de execução.
- Preto: visitado e já saiu da pilha de execução.

A ideia é a seguinte: se enquanto estamos percorrendo o grafo, nos depararmos com um vértice que ainda está na pilha de execução então temos um ciclo. Caso o vértice seja preto, não precisamos percorrê-lo porque isso já foi feito.

```cpp
int BRANCO = 0;
int CINZA = 1;
int PRETO = 2;
int GRAPH_SIZE = 1e5;
vector<vector<int>> graph;

int cor[GRAPH_SIZE+1]; // global, inicializado como 0
bool has_cycle(int node){
    // esse vértice está na pilha, há um ciclo.
    if(cor[node] == CINZA){
        return true;
    }
    // já chamamos essa função pra esse vértice, não precisamos 
    // chamar novamente(se houver um ciclo, já foi levado em conta)
    if(cor[node] == PRETO){
        return false;
    }
    
    bool b = false;

    cor[node] = CINZA;
    // este vértice está na pilha agora
    for(auto v: graph[node]){
        b |= dfs(v); // basta que uma instância do dfs detecte ciclo para
                    // que esse 'true' se propague pela pilha toda.
    }
    cor[node] = PRETO;
    // este vértice saiu da pilha
    return b;
}

int main(){
    // preenche grafo

    bool cycle = false;
    for(int i = 0; i < GRAPH_SIZE; i++){
        if(cor[i] == BRANCO){// só faz sentido começar o dfs de vértices brancos.
            cycle |= has_cycle(i); 
        }
    }
}

```

A complexidade desse código é a complexidade de um DFS, porque é isso que estamos fazendo no fim das contas.

### Não-direcionado

O algoritmo é mais simples no caso do não direcionado. Também faremos uma DFS, mas na nessa DFS, iremos pra todos os nós adjacentes, exceto o nó que chamou aquele, para que não fiquemos voltando.

Se fizermos isso, e acabarmos num nó que já foi visitado, isso significa que tem um caminho de volta para aquele nó sem ser voltando por onde já passamos, o que configura um ciclo no grafo não-direcionado.

```cpp
int GRAPH_SIZE = 1e5;
vector<vector<int>> graph;
bool visited[GRAPH_SIZE+1]; //inicializado como false

bool has_cycle(int node, int last){
    // voltamos pra um nodo que já visitados, há um ciclo.
    if(visited[node])
        return true;
    visited[node] = true;

    bool b = false;
    for(auto v: graph[node]){
        // visitamos todos os adjacentes, menos o que chamou essa instância da função.
        if(v != last){
            b |= has_cycle(v,node);
        }
    }
    return b;
}

int main(){
    // preenche o grafo

    bool cycle = false;
    for(int i = 0; i < GRAPH_SIZE; i++){
        if(!visited[i]){
            cycle |= has_cycle(i,-1);
        }
    }
}

```

A complexidade desse código também é `O(n+m)`, pelo mesmo motivo do código anterior.