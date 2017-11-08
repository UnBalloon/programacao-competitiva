
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
- Para mais detalhes: http://www.cplusplus.com/reference/map/map/
```cpp
    map<string,int> mp;
    string nome;
    cin >> nome;
    mp["Thiago"]++; // agora o mapa mp["Thiago"] = 1
    mp[nome] = 3;
```
- Falar sobre complexidade
- Os elementos de um map são inseridos de forma ordenada de acordo com sua key, ou seja, se voce fizer um map<string,int>, as palavras (keys) ficarão dispostas na ordem lexicográfica (alfabética)
- Para poder caminhar pelos elementos de um map, existem algumas maneiras:
```cpp
    string nome;
    int n;
    map<string,int> mp;
    cout << "Digite a quantidade de nomes que deseja inserir" << endl;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        cin >> nome;
        mp[nome]++;
    }
    cout << "A frequencia das palavras ficou:" << endl;
    
    for(map<string,int>::iterator it = mp.begin(); it != mp.end(); it++){
            cout << it -> first << " " << it -> second << endl;
    }
    
    /*for(auto x : mp){
        cout << x.first << " " << x.second << endl;
    }*/ // Outra forma, só descomentar para ver funcionar, não esquecer de compilar com a flag -std=c++10
    
```

