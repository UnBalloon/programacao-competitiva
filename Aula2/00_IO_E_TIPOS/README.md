IO e Tipos
==========


Hello World
-----------


O exemplo hello world mostra como se imprime na tela em c++, usa-se o comando cout. cout é muito parecido com printf, mas você no precisa indicar o tipo da variável na impressão. 
```cpp
cout << "Hello World!\n";
puts("Hello World!"); // imprime com quebra de linha
```

Leitura
-------

O exemplo leitura mostra como ler variáveis em c++, pode-se usar o comando cin, que é parecido com o scanf, e assim como o cout, não é necessário indicar o tipo.
```cpp
double y;
cin >> y;
```

Importante
----------

É importante ressaltar que c++ não impede de continuar usando o printf e scanf, na verdade, muitas vezes é mais fácil imprimir ou ler em um formato específico usando eles. Além disso, eles são mais rápidos que cin e cout, apesar de ambos terem complexidade constante, o tempo constante de cin e cout é consideravelmente maior. Isso é relevante porque algumas vezes alguns problemas tem input de tamanho ```5*10^5```, e ler isso com cin  já demoraria muito mais que com scanf, então usar cin nesses casos pode exceder o tempo limite do programa. 

Funções já implementadas
-------
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






Strings
------

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
Pair
----

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
Define
-----
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
