# Decomposição em blocos

Consiste em dividir uma parte do problema em blocos menores de forma a atingir uma melhor complexidade.

## Soma de intervalos com update
Já vimos uma forma de computar a soma de intervalos quando não há updates usando preffix sums. Uma forma de resolver o problema tendo que efetuar updates além responder às queries seria guardar um vetor com todos os updates já feitos usando-o para responder às queries apropriadamente.

```cpp
struct mystruct{ int before, pos, after; };
// Dentro da main lê n e q, o vetor v
build_preffix_sum(); // Monta a preffix sum com base no vetor v de tamanho n
vector<mystruct> updates;
for(int i = 0; i < q; i++){ // para toda query
  scanf("%d", &type);
  if(type == 0){ // update
    scanf("%d %d", &j, &x); // pos j muda o valor para x
    updates.emplace_back(v[j], j, x);
    v[j] = x;
  }
  else{ // query
    scanf("%d %d", &l, &r);
    ll ans = query(l, r);
    for(auto up : updates){
      if(up.pos >= l && up.pos <= r){
        ans = ans - up.before + up.after;
      }
    }
    printf("%lld\n", ans);
  }
}
```

Como no código acima precisamos olhar o resultado de todo update anterior para resulver uma query, a complexidade é O(n + q^2).

Podemos mudar drasticamente a complexidade por uma ideia simples. Definimos um número B e a cada B updates remontamos completamente a estrutura de preffix sum.

```cpp
struct mystruct{ int before, pos, after; };
// Dentro da main lê n e q, o vetor v
build_preffix_sum(); // Monta a preffix sum com base no vetor v de tamanho n
vector<mystruct> updates;
for(int i = 0; i < q; i++){ // para toda query
  scanf("%d", &type);
  if(type == 0){ // update
    scanf("%d %d", &j, &x); // pos j muda o valor para x
    updates.emplace_back(v[j], j, x);
    v[j] = x;
    if(updates.size() == B){
      build_preffix_sum();
      updates.clear();
    }
  }
  else{ // query
    scanf("%d %d", &l, &r);
    ll ans = query(l, r);
    for(auto up : updates){
      if(up.pos >= l && up.pos <= r){
        ans = ans - up.before + up.after;
      }
    }
    printf("%lld\n", ans);
  }
}
```
Olhando só para a parte da query, agora vemos que o vetor `updates` tem tamanho máximo B temos então O(q\*B). E olhando só para a parte do update, a cada B updates a preffix sum é remontada então O(q/B\*n). Numa complexidade total de O(q\*B + q/B\*n). Só nos resta escolher o valor do parametro B, neste caso B = sqrt(q) serve bem ficando com complexidade O((q+n)\*sqrt(q)) poderíamos escolher B = sqrt(n) obtendo O((q+n)\*sqrt(n)).

### Uma outra abordagem
Podemos aplicar a ideia de blocos de outra forma, dividimos o vetor em blocos de tamanho sqrt(N), a não ser o último que pode ter o tamanho menor. Desta vez não usamos preffix sum, somente uma variável por bloco que indica o valor da soma dos elementos dentro dele.

Assim o elemento no indice `i` estará no bloco de indice `i/B`, arredondado para baixo. Portanto, os indices cujo resto por B sejam 0, i % B == 0, serão os índices de começo de um bloco.

```cpp
// Dentro da main lê n e q, o vetor v
for(int i = 0; i < n; i += B)
  build_block(i / B);

for(int i = 0; i < q; i++){ // para toda query
  scanf("%d", &type);
  if(type == 0){ // update
    scanf("%d %d", &j, &x); // pos j muda o valor para x
    v[j] = x;
    build_block(j / B)
  }
  else{ // query
    scanf("%d %d", &l, &r);
    printf("%lld\n", query(l, r));
  }
}
```
```cpp
void build_block(int id){
  sum_block[id] = 0;
  for(int j = 0, i = id * B; j < B && i < n; j++, i++){
    sum_block[id] += v[i];
  }
}
```
A complexidade do `build_block` e consequentemente do update é O(sqrt(n)).

Fazer a query agora pode ser um pouco complicado, temos como objetivo fazê-la em O(sqrt(n)). Um caso mais simples é quando `l` e `r` estão no mesmo bloco, só precisamos passar por todos os elementos e resolvemos em O(sqrt(n)). Para os outros casos sabemos um intervalo de blocos que estão completamente dentro da query e podemos pegar a resposta para cada com o vetor `sum_block` em tempo O(n / sqrt(n)) = O(sqrt(n)). Por fim, basta considerar o sufixo do bloco do l e o prefixo do bloco do r que fazem parte da query em tempo linear no tamanho do bloco. Temos tempo de query O(sqrt(n)).
```cpp
ll query(int l, int r){
  ll ans = 0;
  int idl = l/B, idr = r/B;
  if(idl == idr){
    for(int i = l; i <= r; i++)
      ans += v[i];
    return ans;
  }
  for(int i = l; i < (idl+1)*B; i--)
    ans += v[i];
  for(int i = idl+1; i < idr; i++)
    ans += sum_block[i];
  for(int i = idr*B; i <= r; i++)
    ans += v[i];
  return ans;
}
```

Apesar de no fim obtermos praticamente a mesma complexidade para o mesmo problema usando duas abordagens diferentes. Alguns problemas só são resolvidos usando uma delas.

Na última versão, observe que podemos modificar facilmente as funções `build_block` e `query` para lidarmos com outros tipos de consultas sobre intervalos como menor elemento, maior elemento, gcd dos elementos.


## Algoritmo de Mo

Supondo o problema de encontrar a maior frequencia de um elemento em um range, `q, v[i], n < 10^5`. Usaremos uma ideia um pouco não convencional que pode ser aplicada a outros problemas. Mantemos o range e sua respectiva resposta atual. Se conseguirmos adicionar e remover um elemento em qualquer uma das pontas e continuar com a resposta certa, podemos editar o range atual para que seja igual ao range da query.




```cpp
struct mystruct{ int id, l, r; };
bool cmp(mystruct a, mystruct b){
  if(a.l / B != b.l / B)
    return a.l / B < b.l / B;
  return a.r < b.r;
}
// .. dentro da main
vector<mystruct> queries;
for(int i = 0; i < q; i++){
  scanf("%d %d", &l, &r);
  queries.emplace_back(i, l, r);
}

int L = 0, R = -1; //intervalo vazio
for(auto query : queries){
  while(R < query.r) add(++R);
  while(L > query.l) add(--L);
  while(R > query.r) rem(R--);
  while(L < query.l) rem(L++);
  ans[query.id] = cur_ans;
}

for(int i = 0; i < q; i++)
  printf("%d\n", ans[i]);
```
