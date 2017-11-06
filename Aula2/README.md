Ambiente e ferramentas c++
==========================

Na segunda aula, abordaremos um pouco da linguagem c++ e os recursos presentes nela que são úteis em programação competitiva.
Será uma aula prática;

Template
--------

Como já deve ter sido possível observar nos exemplos da aula 1, o template básico que usamos para escrever programas é

```
#include <bits/stdc++.h>
using namespace std;

int main(){

}
```

Esse include inclui todas as bibliotecas padrão do c++, então tem-se suporte a: 

Matematica, strings, estruturas de dados e e diversas funções úteis.

# STL(Standard Template Library) 

## Introdução
STL é uma parte fundamental de C++, pois com o passar do tempo, iremos nos deparar com diversos problemas comuns em relação a dados, com isso podemos criar uma coleção de dados e executar várias operações, como: adicionar, remover, mover, ordenar, alterar dados.

## Objetivos
Nesta aula, iremos ter contatos com algumas estruturas de dados (EDs) mais usadas na programação competitiva.
- Vector
- Map
- Set
- Queue


## Vector

- A grosso modo, vector é uma ED no qual se parece a um Array, porém tem seu tamanho expansível.
- A diferença principal entre Vector e Array é a sua alocação, no qual a do Array se faz estáticamente, já a do Vector é feita dinamicamente [com ponteiros :D]
- Desenhos-no-quadro.jpg
- Apresentar principais métodos: push_back(), begin(), end(), etc.
- Para mais detalhes: http://www.cplusplus.com/reference/vector/vector/
```cpp
	vector<int> v;
	for(int i = 0 ; i < n; i++) v.push_back(i);   //Exemplo de inserção de numeros em um vector
```

## Map

- Map é uma espécie de vetor que armazena elementos formados por uma chave e valor (key,value)
- Isso abre um universo de possibilidades, como:
- Fazer um vetor de char com char, no qual uma letra armazena uma outra letra (Crifa de César)
- Vetor de palavras, para armazenar a frequencia de palavras em um texto
- Para mais detalhes: http://www.cplusplus.com/reference/map/map/
```cpp
	map<string,int> mp;
	mp["Thiago"]++; // agora o mapa mp["Thiago"] = 1
	
```
- Falar sobre complexidade
- Falar sobre sua inserção ordenada
- Demonstrar como fazer um for pelo mapa (com auto e com iterator)
