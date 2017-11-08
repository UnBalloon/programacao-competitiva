
# Estruturas de dados 

## Introdução



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
