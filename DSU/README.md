# Disjoint-Set/Union-Find

Uma das estruturas de dados mais elegantes existentes é o Union-Find, também conhecido como Disjoint-Set, Merge-Find e DSU. 
O problema que essa ED resolve é o seguinte: dados vários conjuntos disjuntos, como podemos saber se dois elementos 
estão no mesmo conjunto ou não, além de conseguir fazer a união de dois conjuntos, tudo isso em tempo rápido?
Uma DSU realiza essas duas operações em tempo praticamente constante!

# Operações
Podemos fazer 4 operações em um Union-Find:
1. **MakeSet/Build:** Inicializa a estrutura de dados.
2. **Find(X):** Encontra o "id" do conjunto que contem o elemento X.
3. **SameSet(X, Y):** Verifica se X e Y pertencem ao mesmo conjunto.
4. **Join/Merge/Union(X, Y):** Encontra os conjuntos que contém X e Y, e une os dois.

# A Ideia
