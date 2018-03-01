# Grafos

Um dos assuntos mais frequentes são problemas relacionados a grafos, ou que podem ser representados como grafos, apesar de não ser óbvio à primeira vista.

## Conceitos

Há diversos tipos e atributos de um grafo:

### O que é um grafo?

Um grafo é definido simplesmente por um conjunto de vértices, e outro conjunto de arestas. Essas arestas ligam dois vértices, e podem ter pesos atrelados à elas.

### Grafo simples

Grafo simples é um grafo que não cujas arestas não tem peso, não possui loops, e nem arestas múltiplas. Loops são arestas do tipo `(u,u)`,  ou seja, que saem do vértice `u`, e vão para o vértice `u`. Um grafo com arestas múltiplas é um grafo que tem duas aresta iguais.

### Grafos direcionados

Existem grafos direcionados e não direcionados. No caso dos não direcionados, significa que cada aresta tem uma direção, ou seja, se é possível chegar de a em b, não significa que é possível chegar de b em a.

### Ciclos

A definição de ciclo é um pouco diferente dependendo se o grafo é direcionado ou não.

 Caso o grafo não seja direcionado, e hajam dois caminhos diferentes de um vértice `a` para um vértice `b`, então há um ciclo.

 Caso contrário, ou seja, caso o grafo seja direcionado, para que haja um ciclo é necessário que exista um vértice `a` tal que seja possível voltar a `a` partindo dele mesmo.

### Conexo

Um grafo conexo é um grafo tal que para dois vértices quaisquer u e w, sempre existe um caminho de u para w.

### Componentes conexas

Um grafo que não é conexo pode ter várias componentes conexas (grafos conexos tem somente uma componente). Essencialmente, uma componente conexa é um pedaço conexo do grafo. Esse conceito é usado no caso de grafos não-direcionados.

### Componentes fortemente conexas

Já nos casos do grafos direcionados, o termo usado é esse, também chamados por SCCs(Strongly Connectec Components). A definição mais 'formal' é a seguinte: dentro de uma componente conexa de um grafo direcionado, para todo vértice `a` e `b`, deve ser possível de chegar de `b` partindo de `a` e em `a` partindo de `b`.

Basicamente o que a definição acima está dizendo é: uma componente fortemente conexa é um ciclo, mas é importante lembrar que se dois ciclos se juntam, formam um ciclo maior, logo, uma componente maior.
### Árvore

Uma árvore é um tipo de grafo. Para ser uma árvore, o grafo precisa ser conexo, não ter ciclos e ter `n-1` arestas, aonde n é o número de vértices.

### DAG

DAG é uma sigla para `Directed Acyclic Graph`, ou seja, um grafo acíclico e direcionado. É um termo bastante usado.

### Grafos bipartidos

Um grafo bipartido é um grafo tal que é possível dividir seus vértices em dois grupos, de forma que só hajam arestas ligando vértices do primeiro ao segundo grupo.



## Representação de um grafo

Mas como representar um grafo em código?

Na verdade é bem mais simples do que parece. Para cada vértice, temos que manter apenas uma lista das arestas que saem daquele vértice.

Nessa representação, a i-ésima posição no vector de fora `vector<int>`, esse vector representam as arestas que saem daquele vértice. Então, cada vértice tem um número associado a ele.

```cpp
vector<vector<int>> graph(GRAPH_MAX_SIZE);

graph[0].push_back(1); // adiciona a aresta (0,1)
graph[1].push_back(0); // adiciona a aresta (1,0)
```

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


