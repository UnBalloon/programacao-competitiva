# Ambiente e ferramentas c++


## Template

```cpp
#include <bits/stdc++.h>
using namespace std;

int main(){

}
```

Esse include nos traz a bilbioteca STL, que inclui todas as bibliotecas padrão do c++, então tem-se suporte a matematica, strings, estruturas de dados e e diversas funções úteis.

## Compilação
O comando de compilação que usamos é
```
g++ -std=c++11 arquivo.cpp
```
É importante usar '-std=c++11' porque isso nos permite usar ferramentas mais recentes da linguagem.

# IO e Tipos



## Hello World



O exemplo hello world mostra como se imprime na tela em c++, usa-se o comando cout. cout é muito parecido com printf, mas você não precisa indicar o tipo da variável na impressão. 
```cpp
cout << "Hello World!\n";
puts("Hello World!"); // imprime com quebra de linha
```

## Leitura


O exemplo leitura mostra como ler variáveis em c++, pode-se usar o comando cin, que é parecido com o scanf, e assim como o cout, não é necessário indicar o tipo.
```cpp
double y;
cin >> y;
```

## Importante


É importante ressaltar que c++ não impede de continuar usando o printf e scanf, na verdade, muitas vezes é mais fácil imprimir ou ler em um formato específico usando eles. Além disso, eles são mais rápidos que cin e cout, apesar de ambos terem complexidade constante, o tempo constante de cin e cout é consideravelmente maior. Isso é relevante porque algumas vezes alguns problemas tem input de tamanho ```5*10^5```, e ler isso com cin  já demoraria muito mais que com scanf, então usar cin nesses casos pode exceder o tempo limite do programa. 


## Strings


C++ tem strings como tipo nativo,  como se fosse um char ou um inteiro. Por esse motivo, há diversas facilidades na manipulação de strings(concatenação, comparação, conversão para inteiro, etc.). 


```cpp
string a = "abc";
string b = "def";
```

A concatenação de strings é simplesmente juntar 2 strings, uma após a outra. Então se tenho a string 'abc' e a string 'def',
'abc' + 'def' = 'abcdef'. Como é necessário uma operação para cada caractere, esse operaçao é executada em O(S), aonde S é a soma dos tamanhos das strings.

```cpp
string resultado = a + b;
```


O critério para comparação de strings é muito parecido com o critério de ordenação lexicográfico (do dicionário), mas também funciona para sequencia de caracteres com caracteres especiais (?,-,.,!). Na verdade, o que é feito é comparar caractere à caractere pelo seu valor na tabela ASCII, Caso uma string s1 tenha um caractere com valor menor que o de uma string s2, a comparação termina e s1 é considerada menor que s2. No pior caso, será necessário comparar todos os caracteres de pelo menos uma das strings, então comparação entre strings é executada em O(S) aonde S é o tamanho da menor entre as duas strings.

```cpp
if(a > b)
  // faz tal coisa
else
  // faz outra coisa
```

A conversão para inteiro é bem simples, a única restrição é que caso a string seja muito grande, seu tamanho estourará o limite para inteiro (ou long long), é executada em O(S) com s sendo o tamanho da string. O mesmo vale para a conversão de inteiro para string.

```cpp
string s = "123";
int a = stoi(s);
```
```cpp
int a = 123;
string s = to_string(a);
```
## Pair


Pares ordenados também são um tipo padrão do c++, pares ordenados são úteis quando se quer guardar informações que tenham a ver uma com a outra (sem fazer uma struct pra isso), como uma coordenada xy ou a altura e peso de alguém. 

```cpp
pair<int,int> p1 = make_pair(0,1);
pair<int,int> p2 = make_pair(1,0);
```
Pares podem ser comparados, de forma que o valor da esquerda é comparado antes, caso haja empate, o valor da direita desempata, então(1,0) > (0,1), por exemplo. Comparação entre pares tem complexidade O(1). 

```cpp
if(p1 > p2)
  //faz tal coisa
else
  // faz outra coisa
``` 


## iterator

Em linhas gerais, podemos chamar iterators de ponteiros mais inteligentes. Quando usamos os operadores ++ em um ponteiro comum, o que a linguagem faz é: faça aquele ponteiro apontar x posições a frente de onde apontava antes, aonde x é o sizeof() daquele tipo. 

```cpp
int v[2] = {0,1};
int* p = v; //p aponta para o começo do vetor(v[0])
p++; //p agora aponta para v[1]
```

## Capacidade dos tipos

É válido ressaltar que os tipos primitivos tem limitações na magnitude do número que representam:
- int : 2^31-1 ~ 2 x 10^9
- long long: 2^63 -1 ~ 8 x 10 ^18

Isso é levante porque se sabemos que nosso programa poderia por exemplo multiplicar dois números que podem ser da ordem de `10^5`, saberíamos que o resultado é da ordem de 10^10, e precisaríamos de um long long para representá-lo.

Os tipo double de ponto flutuante abriga um valor bem maior, até 10^308, mas como possui erros em sua representação, é melhor sempre usar tipos inteiros quando possível.

## Funções úteis

Na linguagem C++ existem várias funções já implementadas que facilitam nossa vida como:
### Swap()
A função swap faz a troca de 2 elementos do mesmo tipo.
```cpp
int v[10];
v[5] = 1;   
v[3] = 412;
swap(v[5],v[3]); // v[5] = 412 e v[3] = 1
```

### Min() e Max()
A função min e max retorna o menor/maior elemento respectivamente.
```cpp
int v[10];
v[5] = 1;
v[3] = 412;
int menor = min(v[5],v[3]); // menor = 1
int maior = max(v[5],v[3]); // maior = 412
```
### to_string()
Para executar a função to_string, não pode esquecer de compilar com a flag -std=c++11. E como o nome da própria função diz, ela transforma um número em uma string.
```cpp
int x = 1320;
string a = to_string(x); // a = "1320"
```
### Substituir if por '?'
A princípio pode parecer um pouco confuso, mas pode ajuda a economizar algumas linhas de código. O operador ? realiza uma pergunta e retorna verdadeiro ou falso dependendo do parâmetro passado.
```cpp
bool q = true;
printf("%s\n", q ? "TRUE":"FALSE"); // Se q for True, irá printar uma msg escrito "TRUE" e "FALSE" caso contrário

int x = q ? 1:0;
```



## Define

Defines são expressões pré definidas pelo programador, que podem facilitar sua vida reduzindo tempo de escrita.Além disso, as vezes muitas dessas expressões são aninhadas, deixando a linha de código muito longa, o que atrapalha um pouco. 

```cpp
#define a b
```
Esse trecho de código pega todas as ocorrências de a e troca por b no momento da compilação. Aqui vão estar algumas das macros mais comuns que são usadas.

```cpp
#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int,int>
int main(){

	vector<int> v;
	v.pb(N); // inserindo 100000 no vetor
	vector<ii> v2; //vetor de pair<int,int>
	v2.pb(mp(1,0)); //inserindo o par (1,0) no vetor de par
}
```






Mas isso só funciona quando os elementos estão uns ao lado dos outros na memória. Com iterators, o comportamento para esse operador pode ser redefinido, permitindo passar pelos elementos de um objeto da forma que desejarmos.

## auto
Podemos pedir para o C++ inferir o tipo de uma variável determinando seu tipo como 'auto'.
```cpp
auto n = 5; // o compilador sabe que n é um inteiro
```


# Vector

A grosso modo, vector é uma ED no qual se parece a um Array, porém tem seu tamanho expansível. 
- A diferença principal entre Vector e Array é a sua alocação, no qual a do Array se faz estáticamente, já a do Vector é feita dinamicamente.
- Para mais detalhes: http://www.cplusplus.com/reference/vector/vector/

```cpp
vector<int> v; // declaracao de um vector;
```

### push_back()

Pode-se inserir elementos em um vector usando push_back. push_back tem complexidade O(1) amortizado. 

```cpp
v.push_back(9);
v.push_back(2);
v.push_back(3);
```

### size()
Para saber quantos elementos tem-se atualmente dentro de um vector, podemos usar o método size. size tem complexidade O(1).
```cpp
int n = v.size();
```
### inicializador
É possível definir o um tamanho do vetor e valores iniciais para cada um dos elementos do vector. O trecho de código abaixo significa: Crie um vetor de inteiros com 100 posições, cujos elementos tem valor 5.
```cpp
vector<int> v(100,5);
```

### begin() e end()
É possível obter iterators(ponteiros) que indicam o começo e o fim de um vector usando esses métodos(mais pra frente veremos que quase todas as estruturas tem isso). Essas operações tem complexidade ```O(1)```

```cpp
vector<int> v;
v.push_back(1);
v.push_back(2);
vector<int>::iterator i = v.begin(); //i aponta para v[0];
i++; // i aponta para v[1];
```


## sort
A função sort pode ser usada para ordenar um vector. Basta passar os endereços do começo e do fim. A complexidade é ```O(n * log n)```. A implementação por trás da função sort pode variar dependendo do ambiente, mas é garantido que sua complexidade é essa. Você pode ver mais sobre os algoritmos de ordenação aqui: https://visualgo.net/en/sorting.

```cpp
vector<int> v;
v.push_back(4);
v.push_back(3);
v.push_back(2);
v.push_back(1);
// v = {4,3,2,1}
sort(v.begin(),v.end());
// v = {1,2,3,4} 
``` 

Essa função não se limita a vectors, na verdade, se olharmos bem o que estamos fazendo é passando dois ponteiros para ela, então, ela ordena a região de memória entre esses ponteiros. O que nos permitiria fazer coisas do tipo:

```cpp
int v[100];
// código para inicializar os valores
sort(v,v+100);
```

### função de comparação 

Uma outra aplicação interessante que podemos fazer com a função sort é definir qual será nosso critério de ordenação. E para isso passaremos para a função um terceiro argumento, uma função de comparação implementada por nós ```sort(v.begin(),v.end(), comparacao)```, esse argumento fica a critério do programador nomeá-lo da maneira que achar adequada (aqui chamei de comparação para facilitar), o importante é implementá-lo de maneira correta.

Toda função de comparação terá sua identidade fixa, ela sempre retornará um ``` bool ``` e receberá dois parâmetros que devem ser do mesmo tipo da estrutura que você está ordenando, no nosso caso um  ``` vector <int> ``` então receberemos dois parâmetros do tipo inteiro, ``` bool comparacao(int a, int b) ```.

O que nossa função de comparação quer saber é se o valor de ``` a ``` deve vir antes do valor de ``` b ``` no vetor final ordenado, e para responder a essa pergunta usaremos o retorno da função como true e false. Usaremos um exemplo para que fique mais claro.

```cpp
bool comparacao(int a, int b){
  if(a > b) return true;
  return false;
}
```

Na função acima estamos retornando true caso o valor de ```a``` seja superior ao valor de ```b```, ou seja, estamos pedindo para que ```a``` venha antes de ```b```. Caso ```b``` seja superior a ```a``` retornamos false o que indica que esses valores devem ser trocados de posição. Com isso nosso vetor será ordenado de forma decrescente.

### upper_bound e lower_bound

Esses métodos executam busca binária no vetor para achar o primeiro elemento estritamente maior do que um dado, ou o primeiro elemento maior ou igual a um dado, respectivamente. Vale lembrar que para realizar busca binária, o vetor precisa estar ordenado.A complexidade é ```O(log n)```.

 Essas funções retornam um iterator, se um elemento for encontrado, é retornado um iterator que aponta para ele, caso contrário, é retornado o iterator '.end()', então é necessário verificar que algum resultado foi encontrado.

```cpp
vector<int> v;
v.push_back(1);
v.push_back(3);
v.push_back(5);
v.push_back(7);
v.push_back(9);
// procure pelo primeiro elemento maior que 3 nesse vetor
auto u = upper_bound(v.begin(),v.end(),3);
// para nao termos que escrever 
// vector<int>::iterator, vamos usar auto

//*u = 5(o primeiro elemento maior que 3 é 5)

u = lower_bound(v.begin(),v.end(),3);

//*u = 3(o primeiro elemento maior ou igual a 3 é 3).

```

Usando essas funções, também é possível determinar o primeiro elemento 'menor ou igual' ou 'menor que' algum `x`. Por exemplo, se lower_bound nos retorna a primeira posição do primeiro elemento maior ou igual a `x`, o elemento anterior a x é o primeiro elemento menor que `x`. Então basta subtrair 1 do iterator de retorno.

## random_shuffle

Por diversar razões, as vezes pode ser útil embaralhar os elementos do vetor. A função random_shuffle faz isso. A complexidade é ```O(n)```;

```cpp
random_shuffle(v.begin(),v.end());
```

## reverse

Também existe um método pronto para trocar a ordem de um vetor. A complexidade é ```O(n)```;

```cpp
reverse(v.begin(),v.end());
```

## next_permutation e prev_permutation

Essas funções geram a próxima e prévia permutação de um conjunto de números. Elas são úteis quando se tem que testar todas as ordens possíveis que certos números podem estar. Esse código imprime todas as permutações de {0,1,2,3,4}. A complexidade de uma chamada é ```O(n)```;

```cpp

int n;
cin >> n;
vector<int> v;
for(int i = 0; i < n; i++){
	v.push_back(i);
}
// v = {0,1,2,3,..,n-1}
do{
	for(int i = 0; i < n; i++){
		printf("%d ",v[i]);
	}
	printf("\n");
}while(next_permutation(v.begin(),v.end()));

```

A função retornará falso quando chegar na última permutação possível(vetor ordenado ao contrário).


<details> 
  <summary>Bônus: Qual é a complexidade do código acima? </summary>
   A complexidade é O(n! * 2 * n) = O(n! * n). Passamos por todas as permutações do vetor; e em cada permutação, passamos pelo vetor todo imprimindo ele e calculamos a próxima permutação.
</details>

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

<!-- # Multiset e multimap

Equivalentes a sets e maps, permitindo elementos repetidos no set e chaves repetidas no map.

## Declaração

```cpp
multiset<int> conj1;
multimap<int,int> mapa1;
unordered_multiset<int> conj2;
unordered_multimap<int,int> mapa2;
``` -->
