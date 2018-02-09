# Árvores binárias de busca

Uma árvore binária de busca é uma árvore binária(cada nodo pode ter no máximo dois filhos) que satisfaz a seguinte propriedade: para todo nodo,o valor de todos os filhos na subárvore esquerda é menor que o valor do próprio nodo, e o valor de todos os filhos na subárvore direita é maior que o do próprio nodo.
https://visualgo.net/en/bst


## Map

- Map é uma espécie de vetor que armazena elementos formados por uma chave e valor (key,value)
- Isso abre um universo de possibilidades, como:
	- Fazer um vetor de char com char, no qual uma letra armazena uma outra letra (Crifa de César)
	- Vetor de palavras, para armazenar a frequencia de palavras em um texto

- Falar sobre complexidade 
- Os elementos de um map são inseridos de forma ordenada de acordo com sua key, ou seja, se voce fizer um     map de string, as palavras (keys) ficarão dispostas na ordem lexicográfica (alfabética)
- Para mais detalhes: http://www.cplusplus.com/reference/map/map/
```cpp
    map<string,int> mp; // declaração 
    mp["Thiago"]++; // agora o mapa mp["Thiago"] = 1
```
### count()
Esta função retorna 1 caso exista o elemento com a chave que você esteja procurando e 0 caso contrári.o
```cpp
	map<char,int> mp;
	mp['c'] = 2; 
	if(mp.count('c')) puts("Meu mapa contém o char c");
```
### erase()
Permite a remoção de um elemento do mapa.
```cpp
	map<char,int> mp;
	mp['c'] = 2; 
	mp.erase('c');
	if(mp.count('c')) puts("Meu mapa contem o char c");
	else puts("Meu mapa nao contem o char c");
```
### clear()
Limpa todo o para para poder utilizar novamente
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

## Set
...



## Define

Defines são expressões pré definidas pelo programador, que podem facilitar sua vida reduzindo tempo de escrita. *MUITO* cuidado!!! Elas podem  acabar atrapalhando caso usadas de maneira errada.
```cpp
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define ii pair<int,int>
#define N 100000
int main(){

	vector<int> v;
	v.pb(N); // inserindo 100000 no vetor
	vector<ii> v2; //vetor de <int,int>
	v2.pb(mp(1,0)); //inserindo o par (1,0) no vetor de par
}
```
