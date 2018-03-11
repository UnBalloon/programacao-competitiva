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
