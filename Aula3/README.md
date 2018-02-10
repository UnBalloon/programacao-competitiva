# Árvores de busca binária

Uma árvore de busca binária (BST) é uma árvore binária (cada nó pode ter no máximo dois filhos, esquerda e direita) onde cada nó possui uma chave (um elemento de um conjunto com relação de ordem total) e, para todo nó `u`, as chaves de todos os filhos na subárvore esquerda são menores que a chave de `u` e as chaves de todos os filhos na subárvore direita são maiores que a chave de `u`. Aqui há uma demonstração visual de como elas funcionam: https://visualgo.net/en/bst

Uma BST balanceada (pela altura) é uma estrutura de dados (ED) onde a representação dos dados é uma BST e as operações de modificação garantem que as distâncias da raiz até as folhas na árvore resultante serão limitadas por algum valor em função do número total de nós armazenados, por exemplo `O(lg n)`.

Existem diversas BSTs balanceadas com `O(lg n)`: AVL trees, red-black trees, treaps, splay trees, scapegoat trees... A mais fácil de implementar para competições é a treap: https://e-maxx-eng.appspot.com/data_structures/treap.html

## Set

Set é mais uma ED da STL C++, que representa um conjunto matemático. Sua implementação é feita por uma BST balanceada.

### declaração

Assim como no vector, temos que indicar qual de qual tipo será nosso set.

```cpp
set<int> conj;
```

### insert

para inserir no set, utiliza-se o método insert(). A complexidade dessa operação é ```O(log n)```
```cpp
set<int> conj;
conj.insert(1);
conj.insert(1);
conj.insert(2);

```

Assim como no conjunto matemático, valores duplicados não contam. Então nosso set teria os valores {1,2} após a execução desse trecho.



###  erase

Para retirar elementos do set, utiliza-se o método erase(). A complexidade dessa operação é ```O(log n)```

```cpp
set<int> conj;
conj.insert(1);
conj.insert(1);
conj.erase(1);
```

Ao fim da execução desse trecho, o conjunto está vazio.

### count

Pode-se verificar se um elemento está no set usando o método count(). A complexidade é ```O(log n)```

```cpp
set<int> conj;
conj.insert(1);
if(conj.count(1)){// retorna 1 se tiver o elemento
	// faça algo
}

```
### size

O método size retorna o tamanho do set, a complexidade é ```O(1)```
```cpp
set<int> conj;
conj.insert(1);
conj.insert(1);
conj.insert(2);
conj.insert(3);
int x = conj.size(); // x = 3

```

### clear()

Se você quiser reinicializar o set, pode usar o método clear(). Sua complexidade é ```O(n)```, já que precisa-se liberar toda memória alocada.




## Map

Map é outra ED da STL C++, também implementada por uma BST balanceada. Enquanto o set é análogo à um conjunto matemático, o map é análogo a uma função, no sentido que podemos mapear o retorno de uma determinada entrada. 

Para efeitos práticos, o map é bem parecido com set, mas ele permite guardar mais informações além de se o elemento está lá ou não. Maps nos permitem atrelar um dado a aquele elemento.

Mais formalmente, maps armazenam informações do tipo {chave, valor}, aonde os tipos de chave e de valor são definidos na declaração.


### Declaração
```cpp
// meu mapa recebe chaves do tipo string e armazena valores inteiros
map<string,int> meu_mapa;
// o acesso é como o de um vetor, mas o índice tem o tipo da chave.

mapa["Deivis"] = 2;

cout << mapa["Sei la"] << endl;
// Isso vai imprimir 0, as chaves que ainda nao tem valores sao inicializados com um valor base quando são acessadas.
```


### size

O método size retorna a quantidade de chaves criadas no map. No caso do map, é necessário tomar cuidado pois apenas acessar o valor de uma chave faz com que ela seja criada. A complexidade é ```O(1)```

```cpp
map<string, int> meu_mapa;
int x = meu_mapa["Deivis"];
int size = meu_mapa.size(); // size = 1
```

### count

Assim como no set, usa-se count para ver se uma chave está no map ou não, a função retorna 1 caso esteja. A complexidade é ```O(log n)```.

```cpp
	map<char,int> meu_mapa;
	meu_mapa['c'] = 2; 
	if(meu_mapa.count('c')) 
		puts("Meu mapa contém o char c");
```


### erase

Remove uma chave do map. A complexidade é ```O(log n)```
```cpp
	map<char,int> meu_mapa;
	meu_mapa['c'] = 2; 
	meu_mapa.erase('c');
	if(mp.count('c')) 
		puts("Meu mapa contem o char c");
	else 
		puts("Meu mapa nao contem o char c");
```

### clear()
Limpa o map. A complexidade é ```O(n)```.
```cpp
	map<char,int> mp;

	for(char i = 'd'; i < 'j'; i++){
		mp[i]++;
	}

	for(char i = 'a'; i < 'l'; i++){
		if(mp.count(i)) printf("%c pertence\n",i);
		else printf("%c NAO pertence\n",i);
	}
	puts("");
	mp.clear();
	
	for(char i = 'a'; i < 'l'; i++){
		if(mp.count(i)) printf("%c pertence\n",i);
		else printf("%c NAO pertence\n",i);
	}
```

## Percorrendo map e set

Ás vezes é necessário percorrer os elementos no map e no set. Uma maneira de fazer isso é a seguinte:

### set
```cpp
set<int> conj;
// codigo que preenche o set

	//iterator!
for(auto i = conj.begin(),i != conj.end(); i++){
	printf("%d\n",*i);
}
```
### map
```cpp
map<int,int> mapa;
// codigo que preenche o map

	//iterator!
for(auto i = mapa.begin(),i != mapa.end(); i++){
	// Os *pares* chave valor do map funcionam como um pair (Duh!) 
					
	printf("%d %d\n",(*i.first),(*i).second);
}
```

## Jeito mais simples

A boa notícia é que tem um jeito um pouco mais simples.

### set
```cpp
set<int> conj;
// codigo que preenche o set

for(int elem : conj){
	printf("%d\n",elem);
}

```

### map
```cpp
map<int,int> mapa;
// codigo que preenche o map

// p é um par de chave valor
for(auto& p : mapa){
	printf("%d %d",p.first,p.second);
}
```

Perceba que no map é possível adicionar `&` após o tipo para modificar o campo `second` (valor mapeado pela chave, armazenada no campo `first`).

# Set e map x vector

É interessante considerar a seguinte ideia: E se usássemos um vetor para indicar se um elemento está ou não no set, ou guardar seu valor no map? (No caso de chaves inteiras). Sim, é possível.


## "Set"
```cpp
// Max é o maior elemento que pode aparecer
// set<int> conj;
vector<bool> conj(MAX,false);
// insert
v[9] = true;

// erase
v[9] = false;

// count
if(v[9]){
// faça algo
}
```

## "Map"

```cpp
// map<int,string> mapa;
vector<string> mapa(MAX);
//mesmo uso
mapa[1] = "oie";

// if(mapa.count(2))
if(mapa[2] != ""){
	// faça algo
}	
```

E a vantagem disso é que as operações de acesso e escrita ocorrem em ```O(1)```, e não ```O(log n)```. Mas para fazer isso, é necessário ter memória suficiente, caso o maior elemento for da ordem de 10^9 por exemplo, não teremos memória para tal e seria melhor usar um set ou map.


# Tabelas hash

## Função hash

Uma função hash é **qualquer** função que pode ser usada para mapear dados de um conjunto de tamanho arbitrário para um conjunto de tamanho fixo.


```cpp

int hash(int n){
	return n % 10;
}
```

Antes de entrar na função, ```n``` podia ter qualquer valor abrigado pelo tipo `int` (um conjunto bem grande). Agora sabemos que ele é um inteiro no intervalo [0, 9].

## Tabela hash

Tabela hash é uma ED que faz uso dessa idéia. Cada dado é mapeado por meio da função hash, e armazenado naquela posição da tabela.

https://visualgo.net/en/hashtable

### Colisões

É evidente que quando se tem uma função cujo domínio é maior que o contra-domínio, dois elementos do domínio terão a mesma imagem. Ou seja, estamos propensos a ter dois elementos com o mesmo resultado na função hash.

Por essa razão, a tabela hash não guarda só um elemento numa das suas posições, e sim uma lista desses elementos. 

Isso é de certa forma problemático, pois se tivermos muitas colisões, a eficiência dessa ED cai drasticamente.

### Diminuindo colisões

Existem diversas formas de melhorar a eficiência de uma tabela hash:

1. Escolher uma função hash com bom espalhamento. `hash(n) = k` é uma função hash, mas com espalhamento ruim (a imagem só possui um único elemento, `k`).
2. Aumentar o tamanho do contra-domínio da função hash e o tamanho da tabela até um limite aceitável de uso de memória.
3. Fazer vários níveis de hash, onde cada nível tem sua própria função hash. Assim que uma lista do nível `i` atinge um tamanho limite, ela é substituída por uma nova tabela hash que usa a função hash do nível `i+1`.

## Hashset e hashmap

Equivalentes a sets e maps, implementadas com tabelas hash no lugar de BSTs. Não suportam armazenamento ordenado dos elementos (limitação de tabelas hash).

### Declaração

```cpp
unordered_set<int> conj;
unordered_map<int,int> mapa;
```

### Métodos e operações
Os métodos e funcionalidades dessas estruturas de dados são quase em totalidade iguais aos set e map comuns, a maior mudança é relacionada a complexidade das operações.

Enquanto na implementação usando BSTs a maioria das operações tinha complexide logarítmica, na implementação usando hashtables, o caso médio tem complexidade ```O(1)```, mas o pior caso continua sendo ```O(n)```, caso hajam muitas colisões.

# Multiset e multimap

Equivalentes a sets e maps, permitindo elementos repetidos no set e chaves repetidas no map.

## Declaração

```cpp
multiset<int> conj1;
multimap<int,int> mapa1;
unordered_multiset<int> conj2;
unordered_multimap<int,int> mapa2;
```

# Ordered_set TODO


