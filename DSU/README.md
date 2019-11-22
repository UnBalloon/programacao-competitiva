# Disjoint-Set/Union-Find

> É recomendado que você leia as aulas de [conceitos de grafos](/Grafos/) e [detecção de ciclos](/Detecção%20de%20ciclos/) antes dessa

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

# Union
Com isso, as operações de Find e SameSet ficam triviais, mas a de Union ainda não pode ser feita rapidamente. Faremos uma pequena modificação para tornar a união tão fácil quanto o Find: // TODO
