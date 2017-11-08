IO e Tipos
==========


Hello World
-----------


O exemplo hello world mostra como se imprime na tela em c++, usa-se o comando cout. cout é muito parecido com printf, mas você no precisa indicar o tipo da variável na impressão. 
```cpp
cout << "Hello World!\n";
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

É importante ressaltar que c++ não impede de continuar usando o printf e scanf, na verdade, muitas vezes é mais fácil imprimir ou ler em um formato específico usando eles. Além disso, eles são mais rápidos que cin e cout, apesar de ambos terem complexidade constante, o tempo constante de cin e cout é consideravelmente maior. Isso é relevante porque algumas vezes alguns problemas tem input de tamanho 5*10^5, e ler isso com cin  já demoraria muito mais que com scanf, então usar cin nesses casos pode exceder o tempo limite do programa. 



Strings
------

C++ tem strings como tipo nativo,  como se fosse um char ou um inteiro. Por esse motivo, há diversas facilidades na manipulação de strings(concatenação, comparação, conversão para inteiro, etc.). 

A concatenação de strings é simplesmente juntar 2 strings, uma após a outra. Então se tenho a string 'abc' e a string 'def',
'abc' + 'def' = 'abcdef'. Como é necessário uma operação para cada caractere, esse operaçao é executada em O(S), aonde S é a soma dos tamanhos das strings.

O critério para comparação de strings é muito parecido com o critério de ordenação lexicográfico (do dicionário), mas também funciona para sequencia de caracteres com caracteres especiais (?,-,.,!). Na verdade, o que é feito é comparar caractere à caractere pelo seu valor na tabela ASCII, Caso uma string s1 tenha um caractere com valor menor que o de uma string s2, a comparação termina e s1 é considerada menor que s2. No pior caso, será necessário comparar todos os caracteres de pelo menos uma das strings, então comparação entre strings é executada em O(S) aonde S é o tamanho da menor entre as duas strings.

A conversão para inteiro é bem simples, a única restrição é que caso a string seja muito grande, seu tamanho estourará o limite para inteiro (ou long long), é executada em O(S) com s sendo o tamanho da string. O mesmo vale para a conversão de inteiro para string.

Pair
----

Pares ordenados também são um tipo padrão do c++, pares ordenados são úteis quando se quer guardar informações que tenham a ver uma com a outra (sem fazer uma struct pra isso), como uma coordenada xy ou a altura e peso de alguém. 

Pares podem ser comparados, de forma que o valor da esquerda é comparado antes, caso haja empate, o valor da direita desempata, então(1,0) > (0,1), por exemplo. Comparação entre pares tem complexidade O(1). 
