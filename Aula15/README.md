# Programação dinâmica

Programação dinâmica é uma forma de resolver problemas que não passa de uma força bruta utilizando uma tabela para que não computemos duas vezes a mesma coisa. Sério, é só isso mesmo. Para guiar a explicação, vamos usar o exemplo da função de fibonacci.

Todo mundo já ouviu falar em algum momento na famosa função de Fibonacci. O primeiro elemento é 0, o segundo é 1, e a partir do segundo, um elemento é a soma dos dois que o precedem. Escrevendo mais matematicamente, como uma relação de recorrência:

```
F(0) = 0
F(1) = 1
F(n) = F(n-1) + F(n-2)
```
Recorrência essa que podemos traduzir em uma função.

```cpp
int fibonacci(int n){
    if(n == 0)
        return 0;
    if(n == 1)
        return 1;
    return fibonacci(n-1) + fibonacci(n-2);
}
```


E aí quando estudamos complexidade pela primeira vez essa mesma função muitas vezes é utilizada como exemplo, porque sua complexidade é exponencial, por razões que explicamos em mais detalhes na aula de complexidade nesse repositório. 

![](https://i.stack.imgur.com/QVSdv.png)


Em suma, o motivo de essa complexidade ser exponencial é porque calculamos repetidamente muitos valores fibonacci. Isto é, se enxergarmos computar F(n) como resolver um problema, e F(n-1) e F(n-2) como subproblemas que precisam ser resolvidos para calcular F(n), o que acontece é que em diferentes ramos na arvore de recursão, ocorre o que chamamos de sobreposição de subproblemas.


E é justamente aí que entra a programação dinâmica. Com nossa recorrência de fibonacci, estamos fazendo uma "força bruta" para o calculo de Fibonacci, mas estamos observando que estamos calculando inúmeras vezes a mesma coisa sem de fato precisarmos. 


Então a ideia aqui é adicionarmos uma tabela, inicialmente com valores que indicam que ela ainda não foi preenchida, e toda vez que vamos calcular nossa recorrência, verificamos se aquela posição da tabela já foi preenchida, isto é, se já resolvemos aquele subproblema. Se já tivermos resolvido, esse valor estará na tabela e poderemos já retorná-lo, se não, aí sim computamos a recorrência, e salvamos na tabela em seguida.



# Exemplos

## Fibonacci

Calcular o valor da função de fibonacci
```cpp
int tb[1005];

int dp(int n){
	if(n == 0)
		return 0;
	if(n == 1)
		return 1;
	if(tb[n] != -1)
		return tb[n];
	tb[n] = (dp(n-1) + dp(n-2)) % 1000000007;
	return tb[n];
}

int main(){
	memset(tb,-1,sizeof(tb));
}
```

Então, aqui nessa modificação, adicionamos a tabela pra salvar nossos valores, um if extra pra verificar se aquela posição já foi preenchida, e preenchemos a tabela antes de retornar o valor computado.

 A função memset preenche os bytes de uma região de memória com o argumento passado, é normalmente um pouco mais rápida em execução e mais fácil de escrever do que fazer um for, então por isso normalmente a usamos. Sua complexidade é linear na quantidade de memória preenchida.

 Agora, qual a complexidade da nossa função?

 Bem, na recorrência, os números maiores só chamam números menores. Inclusive isso é o que faz a recorrência terminar em algum momento. Por esse motivo, uma vez que chegamos num problema, só chamamos a recursão pra números menores que aquele. Então nas chamadas de dp(n-1) e dp(n-2) , não haverá ocorrido nenhuma chamada para dp(n), e já preencheremos a tabela. 
 
 Quando ocorrer uma chamada de dp(n) novamente, a tabela já estará preenchida e não começaremos novamente uma recorrência, e os únicos números que chamarão dp(n) são n+1 e n+2, então dessa forma, dp(n) só poderá ser chamada no máximo 3 vezes, para todo n, e em cada chamada, nosso trabalho tem complexidade constante. Então `O(3*n)` = `O(n)`. Então com programação dinâmica, transformamos algo exponencial em algo linear! incrível, não?

### Estrutura básica

Na verdade, todas as programações dinâmicas podem ser codadas nessa mesmas estrutura do fibonacci. Primeiro nós pensamos em uma função recursiva que calcule a resposta a partir de força bruta, depois, adicionamos uma tabela e salvamos o que já computamos para evitar retrabalho computacional.


```cpp

// podem ser vários argumentos, mas quase sempre todos são inteiros


// vamos colocar tamanhos na nossa tabela
// que comportem o que precisemos, se arg1 vai no máximo até 1000 e arg2 até 200, 
//podemos ter dimensões de 1005 e 205 por exemplo
int tabela[1005][205];

int dp(int arg1,int arg2){
	// checa casos base, ou seja, 
	// os casos que sabemos responder sem recorrência
	if(eh um caso base da recorrencia)
		return resposta;
	
	// checa se a funcao já foi chamada com exatamente os mesmos argumentos
	// se ja foi, então só retorna o valor salvo na tabela
	if(tabela[arg1][arg2] != -1){
		return tabela[arg1][arg2];
	}
	
	// Não é um caso base, então temos que 
	// fazer a recorrência para computar a resposta
	// essa parte geralmente é a mais complexa

	// salva a resposta na tabela

	// retorna resposta
}
```

Normalmente, a parte mais complicada é pensar na função recursiva que vai computar a força bruta. Mas uma vez que a recorrência está pronta, é tão fácil quanto foi passar o fibonacci. Então vamos ver diversos exemplos formas de computar essas forças brutas através de recorrências.


## Problema das moedas

Agora vamos para outro problema. Talvez hajam outros nomes mas alguns chamam de o problema das moedas. Nesse problema, temos a seguinte situação, há um numero n de moedas sobre uma mesa, enfileiradas. Cada moeda tem o seu valor, e devemos escolher moedas para pegar dessa mesa de forma que peguemos o valor máximo possível de moedas. Mas há um custo para pegar uma moeda: você não poderá pegar as moedas adjacentes. No final devemos dizer o valor máximo que podemos obter.

Então por exemplo, se temos [100, 1, 1, 100], a resposta seria 200, pois pegaríamos a primeira e a última moeda. Para [9,17,9], a resposta seria 18, pois pegaríamos a primeira e terceira moedas e para [10,19,11,20,17,5,5,10,11,21,10], bem sei lá qual é a resposta dessa. é por isso que precisamos de um programa pra fazer isso pela gente. 

Note que poderíamos tentar algumas abordagens para resolver esse problema, mas o exemplo [9, 17, 9] mostra que precisaríamos de uma estratégia mais complexa que só pegar os maiores. Não posso afirmar que não exista uma estratégia que resolva o problema, mas com certeza uma coisa que poderíamos fazer é testar todas as possibilidades.

Queremos então testar todas as possibilidades através de uma função recursiva, e como queremos maximizar o valor de moedas obtido, vamos fazer a escolha que nos dá mais valor. 

Bem uma abordagem possível, seria caminhar por todas as moedas, começando da primeira, considerar as duas possibilidades que temos, escolhê-la ou não. Caso a escolhamos, vamos ganhar o valor dela, mas não vamos ter a opção de pegar a moeda logo ao lado. Caso não a escolhamos, não vamos ganhar seu valor, mas vamos poder pegar a moeda imediatamente ao lado. 

Quando acabarem as moedas, saberemos que acabaram nossas opções e não há mais escolhas para fazer, então não há mais como ganhar valor a partir desse ponto. Isso será quando a nossa força bruta irá parar.

Então vamos construir essa recorrência de forma que `dp(i)` retorna **"maior valor de moedas considerando pegar só as moedas do índice `i` em diante"**. Vamos assumir que temos `n` moedas no total, e que seus valores estão armazenados no vector moedas. Lembre-se sempre de manter o significado de o que a função retorna na cabeça. 


```cpp

int n;
vector<int> moedas;

int dp(int i){
	// há n moedas, de 0 a n-1, então,
	// do indice n pra frente não há mais moedas
	// então o maior valor a partir daqui é com certeza 0.
	if(i >= n)
		return 0;

	// agora vamos considerar nossas duas opções.
	// pegar ou não pegar a moeda.

	// Caso eu escolha pegar, terei o valor dessa moeda,
	// mas então, para garantir que não vou pegar a próxima,
	// já que não é permitido, vou chamar a minha função que
	// retorna o maior valor possível considerando 
	// só as moedas a partir do índice i + 2,
	// ou seja, nao contando com a próxima(i+1)
	int pegar = moedas[i] + dp(i + 2);

	// Caso eu escolha não pegar, ok, considere todas as 
	// moedas a partir da próxima, mas não adicione o valor
	// dessa à resposta.
	int nao_pegar = dp(i+1);

	// queremos o máximo, então
	return max(pegar, nao_pegar);	
	
}
```
### Arvore de recursão

Com a nossa função, observe a árvore  da chamada para `dp(0)` sobre o vetor [9, 17, 9].

![](https://i.imgur.com/cNojrbJ.jpg)


Desenhando a árvore, fica mais fácil de perceber porque funciona, todos os caminhos possíveis até as folhas dessa árvore são todas as nossas opções válidas de escolha! Dessa forma, podemos escolher o caminho que soma mais valor, no caso o caminho que pega o primeiro e o terceiro item.

E ao que tudo indica, essa função realmente resolve nosso problema. Mas qual será a complexidade da nossa solução?

 Da pra perceber também que nossa árvore de recorrência está tendo sobreposição. Chegamos no subproblema do índice 2 por dois caminhos diferentes, e recomputamos a sua árvore inteira, que é pequena por causa do exemplo, mas poderia ser muito grande! Na verdade a velocidade com que essa árvore cresce é igual à do fibonacci, mas em vez de chamar (n-1) e (n-2) estamos chamando (i+1) e (i+2). Então essa solução funciona em `O(2^n)`.

Então, para nos aproveitarmos da sobreposição, vamos aplicar programação dinâmica ao problema. Nossa recorrência que resolve o problema já está pronta.
```
DP(i) = 0, se i >= n
DP(i) = max(DP(i+1), moedas[i] + DP(i+2)), caso contrário.
```
Basta memorizar os estados no nosso código anterior:

```cpp
int tb[1005];

int n;
vector<int> moedas;

int dp(int i){
	if(i >= n)
		return 0;
	if(tb[i] != -1)
		return tb[i];

	tb[i] = max(dp(i+1), dp(i+2) + moedas[i]);
	return tb[i];
}

int main(){
	memset(tb,-1,sizeof(tb));

	// logica para ler o input
}
```

Agora temos a mesma funcionalidade de testar todas as possibilidades, mas computamos cada subproblema apenas um número constante de vezes. Pela mesma argumentação do fibonacci, essa solução agora fica `O(n)`.

## Problema do troco mínimo

O problema do troco mínimo é o seguinte: você tem um conjunto de `n` valores de moedas e pode considerar que há infinitas moedas de cada valor. A partir de várias dessas moedas, devemos acumular um valor `K`, usando a menor quantidade de moedas possível.

Então se temos moedas de valores [1,5,12] e queremos juntar o valor `K = 13`, a resposta seriam 2 moedas, uma de 12 e uma de 1. Da mesma forma, se tivermos os valores [1,26,50] e devemos juntar `k = 52` moedas, a resposta seria 2, duas moedas de valor 26.

Esse segundo exemplo já nos mostra que há casos em que sair subtraindo a moeda mais valiosa não funciona. pois dessa forma, pegaríamos uma de 50 e duas de 1, resultando em 3 moedas.

Então,  mais uma vez, não posso provar que não haja uma estratégia ótima para pegar as moedas, mas posso afirmar com certeza que podemos testar todas as possibilidades. Vamos mais uma vez fazer nossa função recursiva que realiza uma força bruta em todas nossas possibilidades.

Vamos fazer da seguinte forma. Queremos somar moedas de forma a chegar a 0. Vamos enxergar pegar uma moeda como um 'custo' de valor 1. Queremos o menor custo para chegar em 0. Da mesma forma como no problema das moedas, é um problema aonde temos várias escolhas sempre, lá nossa escolha era pegar uma moeda ou considerar apenas as próximas, agora nossas escolhas serão qual valor de moeda pegar, dentre os `n` que temos disponíveis.

Dentre todas essas possibilidades, vamos escolher a possibilidade que nos dá a menor resposta. Ou seja, na nossa árvore de recursão, em cada chamada recursiva, haverá vários ramos, um para cada escolha de moeda, e vamos escolher o ramo que nos dá a melhor resposta. 

Dessa forma, faremos todos os 'caminhos' possíveis que nos levem a 0, e como estamos considerando todas as possibilidades, não há como nossa resposta não estar correta.

```cpp

int n;
vector<int> valores;

int dp(int k){
	// quando cheguei em 0, nao preciso mais
	// pegar moedas para atingir 0.
	if(k == 0){
		return 0;
	}

	int melhor = 1e9; // de começo iniciamos com um valor muito alto, que será
			// com certeza substituido pela resposta.

	for(int i = 0; i < n; i++){
		// primeiro verificamos se pegar esse valor
		// não nos levará a valores negativos, pois
		// isso não faria sentido.
		if(valores[i] <= k)
			melhor = min(melhor,1 + dp(k - valores[i]));
			// caso eu pegue, pagarei um 'custo' de 1,
			// e irei para uma nova instancia da recursão
			// aonde tenho que computar a melhor resposta
			// para k - valores[i], então, a melhor resposta 
			// para k será a melhor resposta para (k - valores[i]) + 1.
	}
	return melhor;
}
```


Observe a árvore de recursão formada para uma chamada de dp(8) para os valores de moeda [2, 3, 5]. Dessa vez não vou desenhar os custos, pos são sempre um, mas vou desenhar os ramos em profundidade, dessa forma, o ramo menos profundo nos dará a melhor resposta.

![](https://i.imgur.com/YmrQe3c.jpg)


Os ramos com espessura mais grossa são os ramos que cada chamada recursiva escolheu como a resposta, pois eram os ramos que davam a resposta mínima. Então por exemplo, a resposta para 6 foi 2, para 5 foi 1 e para 3 foi 1, então a nossa chamada de dp(8) itera sobre essas possibilidades e escolhe um dos ramos com valor 1.

 O ramos 'cortados' são so ramos que levariam a valores negativos, portanto inválidos.


Assim como nos outros exemplos, nossa árvore de recursão se sobrepõe muito. A recursão para de 3 é chamada 3 vezes, por exemplo, e em todas, recomputamos a mesma coisa.

colocando nossa tabela:

```cpp
int n;
vector<int> valores;

int tabela[1005];

int dp(int k){
	if(k == 0){
		return 0;
	}
	if(tabela[k] != -1)
		return tabela[k];
	int melhor = 1e9; 
	for(int i = 0; i < n; i++){
		if(valores[i] <= k)
			melhor = min(melhor,1 + dp(k - valores[i]));
	}
	// aqui atribuimos e retornamos de uma vez só
	return tabela[k] = melhor;
}
```

Então, realmente, é sempre assim, a dificuldade é escrever uma função recursiva que computa a resposta, e colocar as coisas numa tabela para evitar retrabalho é fácil. Antes tínhamos uma solução exponencial, em cada estado abríamos mais 3 estados, e agora temos uma solução que para cada estado, a complexidade para computá-lo é `O(n)` e temos `K` estados, então essa solução funciona em `O(nK)`.

## Problema da mochila

	todo


## Maior subsequencia crescente
No problema de achar a maior [subsequencia](https://en.wikipedia.org/wiki/Subsequence) crescente recebemos um vetor v de N elementos e é pedido o tamanho da maior subsequencia(ou seja, apagando elementos em quaisquer posições) desse vetor que é totalmente crescente. Por exemplo, a maior subsequencia crescente de [2, 5, 3, 1, 4, 6] é [2, 3, 4, 6] e aqui retornaríamos 4 que é o tamanho.

É possível recurperar a subsequencia em si, mas por hora focaremos somente em computar o tamanho da maior subsequencia.

É possível resolver de várias formas, abordaremos três formas usando programação dinâmica.

#### Primeira forma

Podemos inicialmente pensar no que acontece caso pegamos um certo elemento i. A partir daí só poderemos pegar elementos com um valor maior.

Assim dá pra fazer um dp em que sempre consideramos o elemento i. E apartir dele só precisamos encontrar o próximo indice para continuar a sequencia crescente, é possivel fazer isto só testando todas as possiblidades.

```cpp
int v[MAXN], N;
int calculado[MAXN];
int tabela[MAXN];

int f(int i){ // consideramos que o i é sempre pego nesta chamada
	if(calculado[i]) return tabela[i];

	int ans = 1; // como pegamos o elemento i, a resposta começa com 1

	for(int j = i+1; j < N; j++){
		// se podemos continuar a sequencia apartir do j pegamos a resposta dele e somamos 1(para considerar o elemento i)
		if(v[i] < v[j])
			ans = max(ans, f(j) + 1);
	}

	calculado[i] = 1;
	tabela[i] = ans;

	return ans;
}
```

Na dp acima f(i) retorna o tamanho da maior subsequencia crescente que começa em i, como queremos a maior subsequencia crescente entre todas para pegar a resposta precisamos fazer algo tipo

```cpp

int resposta = 0;

for(int i = 0; i < N; i++)
	resposta = max(resposta, f(i));

```

E assim conseguimos computar a resposta.

Para saber a complexidade da dp podemos pensar que vamos ter que preencher a tabela completamente com as respostas então a complexidade é pelo menos O(tamanho da tabela) o que falta contar é a complexidade de dentro de uma chamada da função, aqui temos um for que é linear. O tamanho da tabela é O(N) e com o for a complexidade total fica O(N*N) em tempo, mas O(N) de espaço.

#### Segunda forma

Outra forma de pensar na dp é passar pelos itens e escolher entre pegar ou não cada item.

Nesses tipos de soluções em que é testado pegar ou não, as vezes é necessário testar se é possivel ou não pegar o item.

Para conseguir determinar se conseguimos pegar o item vamos precisar de mais um estado(argumento da função) que nos fala qual o último elemento pego.

```cpp
int v[MAXN], N;
int tabela[MAXN][MAXN];
int resposta[MAXN][MAXN];

int f(int i, int lastid){
	if(i == N) return 0;
	if(calculado[i][lastid])
		return tabela[i][lastid];

	int ans = f(i+1, lastid); // não pegar o item

	// se pode pegar o item
	if(v[lastid] < v[i]){
		ans = max(ans, f(i+1, i)+1)
	}
	calculado[i][lastid] = 1;
	tabela[i][lastid] = ans;

	return ans;
}
```

A complexidade da dp será O((tamanho da tabela) \* (complexidade em uma chamada)). O tamanho da tabela é O(N*N) e cada chamada só realiza operações constantes(if, max etc), assim a complexidade é O(N*N) em tempo e espaço

Temos um pequeno problema com esta dp. Como é possível pegar a resposta para o problema original? Numa chamada é preciso botar um elemento "anterior". É facil resolver isto de forma similar a dp anterior.

```cpp

int resposta = 0;

for(int i = 0; i < N; i++)
	resposta = max(resposta, f(i+1, i) + 1);

```

#### Terceira forma

Esta última forma é uma variação da anterior.

Usando a ideia de testar pegar ou não o item é preciso saber de alguma forma se é possível ou não pegar o item. Na versão anterior isso foi resolvido passando o indice do elemento anterior, é possível também passar o elemento anterior. Repare que fazer isto os elementos precisarão ser positivos já que usaremos isso como indice num vetor(para tabela).

```cpp
int v[MAX], N;
int tabela[MAXN][MAXV];
int resposta[MAXN][MAXV];

int f(int i, int lastvalue){
	if(i == N) return 0;

	int tabela[MAXN][MAXN];
	int resposta[MAXN][MAXN];

	if(calculado[i][lastvalue])
		return tabela[i][lastvalue];

	int ans = f(i+1, lastvalue); // não pegar o item

	// se pode pegar o item
	if(lastvalue < v[i]){
		ans = max(ans, f(i+1, v[i])+1);
	}

	calculado[i][lastvalue] = 1;
	tabela[i][lastvalue] = ans;

	return ans;
}
```

A complexidade da dp será O((tamanho da tabela) \* (complexidade em uma chamada)). Sendo N o tamanho do vetor e V o valor máximo dos elementos, o tamanho da tabela é O(N*V) e cada chamada só realiza operações constantes, assim a complexidade é O(N*V) em tempo e espaço.

O bom dessa versão é que há problemas com vetor grande mas que os elementos não variam muito. Por exemplo, num problema de achar a maior subsequencia crescente de uma string de tamanho 10^5 que só pode ter as 26 letras do alfabeto, a terceira versão funciona bem enquanto as duas anteriores, não.

Há problemas em que o tamanho é pequeno mas o elementos podem ir até 10^9, o que dificulta um pouco o uso dessa versão também.

Para pegar a resposta do problema, caso os elementos sejam positivos o 0 não aparece e podemos pegar a resposta com
`f(0, 0)`.

## Substring palindroma
Considere o seguinte problema.

Inicialmente é dada uma string S e a seguir é perguntado Q consultas. Em cada consulta é dado dois indices i e j, e você deve informar se a substring de S formada pelos elementos entre os indices i e j é um palindromo ou não. S tem tamanho N, que é no máximo 1000 e o maior valor de Q é 10^6.

Podemos pensar numa função `palin` que recebe os dois indices e retorna `true` caso a substring seja palindromo	e `false` caso contrário.

Pensando numa função recursiva chegamos a

```cpp
char s[MAX];

int is_palin(int i, int j){
	if(i == j) return true;
	if(i + 1 == j) return s[i] == s[j];

	int ans = false;
	if(s[i] == s[j]){
		if(is_palin(i+1, j-1)){
			ans = true;
		}
	}
	return ans;
}
```

A complexidade do código acima é linear na distancia entre i e j. Assim para responder Q queries a solução é O(Q*N).

Já temos uma solução recursiva, podemos salvar a resposta para intervalos ja perguntados usando memoização.

```cpp
char s[MAX];
int calculado[MAX][MAX]; // inciado com false, ou 0
int tabela[MAX][MAX];

int is_palin(int i, int j){
	if(calculado[i][j]){
		return tabela[i][j];
	}
	if(i == j) return true;
	if(i + 1 == j) return s[i] == s[j];

	int ans = false;
	if(s[i] == s[j]){
		if(is_palin(i+1, j-1)){
			ans = true;
		}
	}
	calculado[i][j] = true;
	tabela[i][j] = ans;
	return ans;
}
```

E assim só com 4 linhas de código adicionais na função a complexidade do código vira O(Q + N*N).

A complexidade para pegar a resposta de algo já calculado é constante pois só vai retornar no primeiro if da função. Então a complexidade da fica O(Q + complexidade de computar todas as respostas da dp).

A complexidade da dp é O((tamanho da tabela) \* (complexidade em uma chamada)) e a complexidade de uma chamada da é constante. Portanto a complexidade da dp é somente O(tamanho da tabela), tabela é uma matriz de N por N, ou seja, O(N*N) em tempo e espaço.

# VideoAulas complementares

## MIT (esse professor é top)
https://www.youtube.com/watch?v=OQ5jsbhAv_M

https://www.youtube.com/watch?v=ENyox7kNKeY

https://www.youtube.com/watch?v=ocZMDMZwhCY

https://www.youtube.com/watch?v=tp4_UXaVyx8


## HackerRank
https://www.youtube.com/watch?v=P8Xa2BitN3I
