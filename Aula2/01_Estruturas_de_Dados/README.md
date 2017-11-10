
# Estruturas de dados 


## Vector

A grosso modo, vector é uma ED no qual se parece a um Array, porém tem seu tamanho expansível. 
- A diferença principal entre Vector e Array é a sua alocação, no qual a do Array se faz estáticamente, já a do Vector é feita dinamicamente [com ponteiros :D]
- Para mais detalhes: http://www.cplusplus.com/reference/vector/vector/

```cpp
	vector<int> v; // declaracao de um vector;
```


### push_back()

Pode-se inserir elementos em um vector usando push_back. push_back tem complexidade O(1) amortizado. 

```cpp
	v.push_back(9);   //Exemplo de inserção de numeros em um vector
	v.push_back(2);
	v.push_back(3);
```


### size()
Para saber quantos elementos tem-se atualmente dentro de um vector, podemos usar o método size. size tem complexidade O(1).
```cpp
int n = v.size();
```

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


## Exercícios

- Map
	- [Pontos de Feno](https://www.urionlinejudge.com.br/judge/pt/problems/view/1261)	 
	- [Perguntas mais Frequentes](https://www.urionlinejudge.com.br/judge/pt/problems/view/1553)
	- [Composição de Jingles](https://www.urionlinejudge.com.br/judge/pt/problems/view/1430)
	- [Decifra](https://www.urionlinejudge.com.br/judge/pt/runs/code/6602221)
	- [Número Solitário](https://www.urionlinejudge.com.br/judge/pt/problems/view/2091)
	- [Espécies de Madeira*](https://www.urionlinejudge.com.br/judge/pt/problems/view/1260)

- Vector
	- [Lista de Chamada](https://www.urionlinejudge.com.br/judge/pt/problems/view/2381)
	- [System of a Download](https://www.urionlinejudge.com.br/judge/pt/problems/view/2582)
	- [Número de Envelopes](https://www.urionlinejudge.com.br/judge/pt/problems/view/2341)
	- [A Lenda de Flavious Josephus*](https://www.urionlinejudge.com.br/judge/pt/problems/view/1030) 
