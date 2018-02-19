# Grafos

Um dos assuntos mais frequentes são problemas relacionados a grafos, ou que podem ser representados como grafos, apesar de não ser óbvio à primeira vista.

## Conceitos

Há diversos tipos e atributos de um grafo:

### O que é um grafo?

Um grafo é definido simplesmente por um conjunto de vértices, e outro conjunto de arestas. Essas arestas ligam dois vértices, e podem ter pesos atrelados à elas.

### Grafo simples

Grafo simples é um grafo que não cujas arestas não tem peso, não possui loops, e nem arestas múltiplas. Loops são arestas do tipo (u,u),  ou seja, que saem do vértice u, e vão para o vértice u. Um grafo com arestas múltiplas é um grafo que tem duas aresta iguais.

### Grafos direcionados

Existem grafos direcionados e não direcionados. No caso dos não direcionados, significa que cada aresta tem uma direção, ou seja, se é possível chegar de a em b, não significa que é possível chegar de b em a.

### Ciclos

blablabla

### Conexo

Um grafo conexo é um grafo tal que para dois vértices u e w, sempre existe um caminho de u para w.

### Árvore

Uma árvore é um tipo de grafo. Para ser uma árvore, o grafo precisa ser conexo, não ter ciclos e ter `n-1` arestas, aonde n é o número de vértices.

### DAG

DAG é uma sigla para "directed acyclic graph", ou seja, um grafo acíclico e direcionado. É um termo bastante usado.
