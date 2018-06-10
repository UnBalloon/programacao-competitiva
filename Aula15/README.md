# Programação dinâmica

### Estrutura básica

```cpp

// podem ser vários argumentos, mas geralmente todos são inteiros
tipo_retorno f(argumentos){
	// checa se a funcao já foi chamada com exatamente os mesmos argumentos
	// se ja foi, então só retorna o valor salvo na tabela

	// checa casos base

	// calcula a resposta
	// essa parte geralmente é a mais complexa

	// marca a resposta na tabela

	// retorna resposta
}
```

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

## Problema das moedas

```cpp
int tb[1005];

int size;
vi valor;

int dp(int n){
	if(n >= size)
		return 0;
	if(tb[n] != -1)
		return tb[n];

	tb[n] = max(dp(n+1), dp(n+2) + valor[n]);
	return tb[n];
}

int main(){
	memset(tb,-1,sizeof(tb));
}
```

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
