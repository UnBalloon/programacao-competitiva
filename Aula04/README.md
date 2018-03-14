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


## Usando inteiros para representar conjuntos

Há uma forma de representar conjuntos a partir de inteiros. Se enchergarmos um inteiro como uma sequência de bits, e cada bit representar a inclusão ou não-inclusão de um elemento, podemos representar conjuntos de até 32 elementos usando inteiros. Ou seja, se você enumerar os elementos de 0 a 31, o i-ésimo bit ligado significa que o i-ésimo elemento está incluso no conjunto.

### Inserindo elementos

```cpp
int conj = 0; // conjunto vazio

conj |= (1 << 3); // insira o elemento número 3;
conj |= (1 << 0); // insira o elemento número 0;

```

### Removendo elementos

```cpp
conj &= ~(1 << 3);//remova o elemento número 3.
conj &= ~(1 << 0);//remova o elemento número 0.
```



### Checando se um elemento está no conjunto

```cpp

//retornará positivo caso o terceiro bit esteja ligado.
if((1 << 3) & conj){

}
```

### União

```cpp

int conj1;
int conj2;

int uni = conj1 | conj2;
```

### Interseção

```cpp

int conj1;
int conj2;

int inter = conj1 & conj2;
```



# Gerando todos os subconjuntos de um conjunto
----------------------------------------------

Suponha que você tenha um conjunto S = {a,b,c}.  
Para formar um subconjunto de S, podemos escolher ou não o elemento **a** (2 opções), escolher ou não o elemento **b** (2 opções de novo) e escolher ou não o elemento **c** (2 opções novamente). Logo, podemos formar um subconjunto de S de 2\*2\*2 maneiras diferentes. 
Um conjunto de N elementos possui 2^N subconjuntos. S possui 2^3 = 8 subconjuntos.

Ok, agora vamos representar cada elemento do conjunto S com um bit, como S tem 3 elementos, precisamos de 3 bits para isso:  
**a** = bit 2,  
**b** = bit 1,  
**c** = bit 0  

Com esta associação de elementos e bits, podemos representar todos os subconjuntos de S como uma palavra de 3 bits. Veja:

0 = (000)2 = {}  
1 = (001)2 = {c}  
2 = (010)2 = {b}  
3 = (011)2 = {b, c}  
4 = (100)2 = {a}  
5 = (101)2 = {a, c}  
6 = (110)2 = {a, b}  
7 = (111)2 = {a, b, c}  

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

# Alguns truques com bits
-------------------------
// TODO
