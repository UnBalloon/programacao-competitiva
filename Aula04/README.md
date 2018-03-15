# Representação binária
-----------------------
Qualquer tipo de dado, seja um número inteiro, número racional ou um caracter, pode ser representado por bits.
Exemplos de representação binária de números inteiros (sem sinal):  
**1)** 14 = {1110}2 = 1 * 2^3 + 1 * 2^2 + 1 * 2^1 + 0 * 2^0 = 14.  
**2)** 20 = {10100}2 = 1 * 2^4 + 0 * 2^3 + 1 * 2^2 + 0 * 2^1 + 0 * 2^0 = 20.  

# Operadores bit-a-bit
----------------------
**NOT ( ~ )**: Bitwise NOT é um operador unário que flipa os bits de um número (se o bit é 0, vira 1 e vice-versa). Bitwise NOT é apenas o complemento de 1 de um número.  
N = 5 = (101)2  
~N = ~5 = ~(101)2 = (010)2 = 2  

**AND ( & )**: Bitwise AND é um operador binário que opera em duas palavras de bits de mesmo tamanho. Se ambos os bits na posição comparada das palavras forem 1, então o valor do bit resultante nessa posição na palavra final será 1, qualquer outro caso o bit resultante será 0.
A = 5 = (101)2  
B = 3 = (011)2  
A & B = (101)2 & (011)2= (001)2 = 1  

**OR ( | )**: Bitwise OR, similarmente ao bitwise AND, é um operador binário que opera em duas palavras de bits de mesmo tamanho. Se ambos os bits na posição comparada forem 0, o valor do bit resultante nessa posição na palavra final será 0, qualquer outro caso o bit resultante será 1.  
A = 5 = (101)2  
B = 3 = (011)2  
A | B = (101)2 | (011)2 = (111)2 = 7  

**XOR ( ^ )**: Bitwise XOR também é um operador binário que opera em duas palavras de bits de mesmo tamanho. Se ambos os bits na posição comparada forem iguais (0 ou 1), o valor do bit resultante nessa posição na palavra final será 0, se os bits forem diferentes (um 0 e outro 1), o bit resultante será 1.  
A = 5 = (101)2  
B = 3 = (011)2  
A ^ B = (101)2 ^ (011)2 = (110)2 = 6  

**Left Shift ( << )**: Existem dois operadores de deslocamento (left shift e righr shift). O left shift operator é um operador binário que desloca os bits de uma palavra X vezes para a esquerda e preenche a palavra com X 0s à direita. **Left shift de X bits em um número inteiro é equivalente a multuplicá-lo por 2^X.**  
1 << 1 = 2  
1 << 2 = 4  
2 << 2 = {00010}2 << 2 = {01000}2 = 8  
1 << n = 2^n

**Right Shift ( >> )**: O right shift operator é um operador binário que desloca os bits de uma palavra X vezes para a direita e preenche a palavra com X 0s à esquerda. **Right shift de X bits em um número inteiro é equivalente a dividi-lo por 2^X.**  
4 >> 1 = 2  
6 >> 1 = 3  
5 >> 1 = 2  
16 >> 4 = 1  

#### Tabela-verdade

| X | Y | X&Y | X\|Y | X^Y |
|---|---|-----|-----|-----|
| 0 | 0 |  0  |  0  |  0  |
| 0 | 1 |  0  |  1  |  1  |
| 1 | 0 |  0  |  1  |  1  |
| 1 | 1 |  1  |  1  |  0  |

# Manipulando bits
------------------
#### Checando se um determinado bit está ligado
Para checarmos de um jeito eficiente se o i-ésimo bit de um número N está ligado, basta apenas checar se o AND de 2^i e N é diferente de 0. Como vimos anteriormente, o número 2^i é simplesmente o número 1 shiftado de i bits (1 << i).
```cpp
bool isSet(int bitPosition, int number) {
  bool ret = ((number & (1 << bitPosition)) != 0);
  return ret;
}
```

#### Ligando um determinado bit em um número
Para ligar o i-ésimo bit de um número N, basta apenas fazermos o OR de 2^i com N.
```cpp
bool setBit(int bitPosition, int number) {
  return (number | (1 << bitPosition) );
}
```


# Representando conjunto com bits - bitmasks
--------------------------------------------
Suponha que tenhamos conjunto universo com 8 elementos, U = {a,b,c,d,e,f,g,h}.  
Vamos associar cada elemento de U a um bit: 

a -> bit 7  
b -> bit 6  
c -> bit 5  
d -> bit 4  
e -> bit 3  
f -> bit 2  
g -> bit 1  
h -> bit 0  

Com essa associação, podemos representar qualquer subconjunto de U como uma máscara de 8 bits. Exemplo:

| Conjunto | Bitmask |
| -------- | ------- |
| {b,c,f,h} | 01100101 |
|  {a}       | 10000000 |
| {}         | 00000000 |

#### Adicionar um elemento ao conjunto
Para adicionarmos um elemento a um conjunto que está representado como uma bitmask é simples. Basta apenas setarmos o bit correspondente ao elemento na bitmask do conjunto.

```cpp
int addElement(int bitmask, int elementPosition) {
  bitmask = bitmsak | (1 << elementPosition);
  return bitmask;
}
```

#### Checar se um conjunto contem um elemento
Essa operação é a mesma de checar se um dado bit está setado na bitmask.
```cpp
bool hasElement(int bitmask, int elementPosition){
  bool ret = ((bitmask & (1 << elementPosition)) != 0);
  return ret;
}
```

#### União de 2 conjuntos
Um elemento estará presente na união de 2 conjuntos se e somente se pelo menos um dos conjuntos contiver este elemento. Com base nisso e na tabela-verdade, podemos ver que a máscara que representa a união de duas máscaras é o OR delas.
```cpp
int union(int bitmaskA, int bitmaskB){
  return (bitmaskA | bitmaskB);
}
```

#### Interseção de 2 conjuntos
Um elemento estará presente na interseção de 2 conjuntos se e somente se os 2 conjuntos contiverem este elemento. Logo, a máscara que representa a interseção de duas máscaras é o AND delas.
```cpp
int intersection(int bitmaskA, int bitmaskB){
  return (bitmaskA & bitmaskB);
}
```

#### Gerando todos os subconjuntos de um conjunto
Suponha que você tenha um conjunto S = {p,q,r}.  
Para formar um subconjunto de S, podemos escolher ou não o elemento **p** (2 opções), escolher ou não o elemento **q** (2 opções de novo) e escolher ou não o elemento **r** (2 opções novamente). Logo, podemos formar um subconjunto de S de 2\*2\*2 maneiras diferentes. 
Um conjunto de N elementos possui 2^N subconjuntos. S possui 2^3 = 8 subconjuntos.

Ok, agora vamos representar cada elemento do conjunto S com um bit, como S tem 3 elementos, precisamos de 3 bits para isso:  
**p** = bit 2,  
**q** = bit 1,  
**r** = bit 0  

Com esta associação de elementos e bits, podemos representar todos os subconjuntos de S como uma palavra de 3 bits. Veja:

0 = (000)2 = {}  
1 = (001)2 = {r}  
2 = (010)2 = {q}  
3 = (011)2 = {q, r}  
4 = (100)2 = {p}  
5 = (101)2 = {p, r}  
6 = (110)2 = {p, q}  
7 = (111)2 = {p, q, r}  

Como temos 2^N subconjuntos em um conjunto de N elementos, passando por todos os números de [0, 2^N - 1] é possível representar todos os subconjuntos de um conjunto.  
Código para printar todos os subconjuntos de um conjunto:

```cpp
void possibleSubsets(char S[], int N) {
    for(int i = 0;i < (1 << N); ++i) {  // i = [0, 2^N - 1]
        for(int j = 0;j < N;++j)
            if(i & (1 << j))  // se o j-ésimo bit de i está setado, printamos S[j]
                cout << S[j] << ‘ ‘;
        cout << endl;
    }
}
```

