# Segment Trees

Segment tree(Segtree) é outra estrutura de dados para lidar com problemas de consulta em intervalos. O que tornas as segtrees poderosas é sua capacidade de fazer atualização  e consulta em intervalos em complexidade `O(log n)`, além do tipo da consulta ser bem abrangente.


A ideia é a seguinte: Criamos uma árvore, de forma que cada nodo representa a informação que desejamos saber a respeito de um segmento do vetor, e tem dois filhos, um filho representa a parte esquerda desse intervalo, e o outro, a parte direita. Esse processo recursa até que os intervalos atinjam tamanho 1.

Aqui há uma demonstação visual de como funciona: https://visualgo.net/en/segmenttree


É interessante entender o funcionamento da segtree pois, por mais que tenhamos o código pronto, quando mudamos de operação ou precisamos inserir long longs, será necessário mexer na sua estrutura interna.

## Representação

Nossa segtree será representada como um vetor. Cada nodo terá um id nesse vetor, e o conteúdo dessa posição representa a informação que aquele nodo guarda. A raiz da segtree será o nodo 0, que guarda a informação sobre o vetor todo. A partir do índice `id` de um nodo, podemos obter os filhos sem colisões da seguinte forma: índice dos filhos esquerdo e direito são `(id*2 + 1,id*2 +2)`, respectivamente.

```cpp
    vector<int> st;
    int size;

```


## Operação

Essa função define que informação queremos saber a respeito dos elementos do vetor. Nese caso é uma segtree que computa o máximo de intervalos, mas poderia ser soma, mínimo, produto,  xor, gcd, mmc(lcm), or e and lógicos etc.

```cpp
    int f(int a, int b){
        return max(a,b);
    }
```

## Elemento neutro
O elemento neutro depende da operação. Como queremos saber os máximos, o elemento neutro dessa operação seria um número muito baixo, que nunca será o máximo.

 Caso não saiba a definição de elemento neutro, a definição é a seguinte: `e` é um elemento neutro da operação f se `f(e,x) = x` para todo `x`.

 Caso fosse uma soma, nosso elemento neutro seria 0, caso fosse um produto, seria 1, etc..
```cpp
 int el_neutro = -(1e9 + 7);
```

## Consulta

A  função recursiva abaixo responde às consultas na segtree. Cada parâmetro tem o seguinte significado:

- `sti`: id do nodo que estamos na segment tree
- `stl`: limite inferior do intervalo que aquele nodo representa(inclusivo)
- `str`: limite superior do intervalo que aquele nodo representa(inclusivo)
- `l`  : limite inferior do intervalo que queremos fazer a consulta
- `r`  : limite superior do intervalo que queremos fazer a consulta

```cpp
int query(int sti, int stl, int str, int l, int r){
    //O nodo está fora do intervalo que estamos interessados, retorne o elemento neutro que não afeta a consulta
        if(str < l || r < stl) 
            return el_neutro;

    // O nodo está completamente incluído no intervalos que estamos interessados, retorne a informação contida naquele nodo.
        if(stl >= l and str <= r)
            return st[sti];

    // Se chegarmos aqui, é porque esse Nodo está parcialmente contido no intervalo que estamos interessados. Então, continuamos procurando nos filhos.
        int mid = (str+stl)/2;

        return f(query(sti*2+1,stl,mid,l,r),query(sti*2+2,mid+1,str,l,r));
    }
```
## Atualização

Essa função atualiza um elemento da segtree. Cada parâmetro tem o seguinte significado:
- `sti`: id do nodo que estamos na segment tree
- `stl`: limite inferior do intervalo que aquele nodo representa(inclusivo)
- `str`: limite superior do intervalo que aquele nodo representa(inclusivo)
- `i`  : índice do **vetor** que queremos atualizar
- `amm`: novo valor daquele índice no vetor

```cpp
    void update(int sti, int stl, int str, int i, int amm){
        // Chegamos no índice que queremos, vamos atualizar o valor
        if(stl == i and str == i){
            st[sti] = amm;
            return;
        }
        // O intervalo que estamos não contem o índice que queremos atualizar, retorne
        if(stl > i or str < i)
            return;
        
        // O intervalo contém o índice, mas temos que chegar no nodo específico, recurse para os filhos.
        int mid = (stl + str)/2;

        update(sti*2+1,stl,mid,i,amm);
        update(sti*2+2,mid+1,str,i,amm);
        // Após os filhos mais em baixo, precisamos atualizar o valor desse nodo
        st[sti] = f(st[sti*2+1],st[sti*2+2]);
    }


```
## Declaração

Essa é a classe com as funcionalidades implementadas.
```cpp
class  SegTree{
    vector<int> st;
    int size;

    int el_neutro = -(1e9 + 7);

    int f(int a, int b){
        return max(a,b);
    }

    int query(int sti, int stl, int str, int l, int r){
        if(str < l || r < stl)
            return el_neutro;


        if(stl >= l and str <= r)
            return st[sti];

        int mid = (str+stl)/2;

        return f(query(sti*2+1,stl,mid,l,r),query(sti*2+2,mid+1,str,l,r));
    }

    void update(int sti, int stl, int str, int i, int amm){
        if(stl == i and str == i){
            st[sti] += amm;
            return;
        }

        if(stl > i or str < i)
            return;
        int mid = (stl + str)/2;
        update(sti*2+1,stl,mid,i,amm);
        update(sti*2+2,mid+1,str,i,amm);
        st[sti] = f(st[sti*2+1],st[sti*2+2]);
    }


    public:
        SegTree(int n):  st(4*n,0){size = n;}
        int query(int l, int  r){return query(0,0,size-1,l,r);}
        void update(int i, int amm){update(0,0,size-1,i,amm);}
};
```


## Interface

Os métodos que mostramos são todos internos da segtree, na hora de chama-los, não precisamos passar tantos parâmetros assim.

```cpp
 public:

        SegTree(int n):  st(4*n,0){size = n;}
        int query(int l, int  r){return query(0,0,size-1,l,r);}
        void update(int i, int amm){update(0,0,size-1,i,amm);}
```
### SegTree 

Construtor, recebe o tamanho do vetor.

### query

Executa uma consulta, recebe o intervalo(l,r) da consulta, retorna o resultado.

### update
Atualiza um índice no vetor recebe o índice e o novo valor.

## Construção
```cpp
vector<int> v;
SegTree st(v.size());
for(int i = 0; i< v.size();i++){
    st.update(i,v[i]);
}
```


## Atualizações em intervalos

A segtree que temos até agora faz atualização de uma posição no vetor e consulta de qualquer em intervalo, em `O(log n)`. Mas e se precisarmos atualizar um intervalo, por exemplo: "Todos os elementos da posição 1 até 10 recebem 2". Assim, a melhor forma que teríamos de fazer isso seria


```cpp
SegTree st(n);
// preenche segtree
for(int i = 1 ; i <= 10; i++){
    st.update(i,2);
}
```

O que tem complexidade `O(n * log n)`. Precisamos fazer isso mais rápido.

# Lazy progapation

Lazy propagation é uma alteração na segtree que nos permite fazer atualizações em intervalos em `O(log n)`.

## A ideia

Em nossa abordagem anterior, o que tornava a execução lenta é que procurávamos o nodo responsável por cada elemento que precisava ser atualizado.

 Para acelerar esse processo, podemos usar uma ideia parecida com a da consulta, em vez de atualizar individualmente os elementos, podemos atualizar a resposta nos intervalos que os contém, e postergar a atualização nos filhos.
 
  Para implementar lazy propagation, cada configuração de segtree vai requerer uma implementação um pouco diferente, por isso, será necessário entender o que cada parte do código está fazendo.

  O exemplo a seguir será de uma segtree de soma, aonde a atualização de intervalo vai setar todos os elementos para um qualquer.

 ## vetor de lazy

 A ideia é introduzir um vetor extra com o seguinte significado: Quando eu passar no nodo identificado por id, em uma consulta, ou outra atualização, preciso atualizar seu valor para `lazy[id]`. O vetor has indica se há uma atualização para ser feita naquele nodo.

 ```cpp
    vector<int> st;
    vector<int> lazy;
    vector<bool> has;
    int size;
 ```

 ## A propagação

A função de propagação é a função que atualiza o valor de um nodo, e posterga a atualização para os filhos. Precisamos chamar essa função toda vez que passamos por algum nodo. 

 ```cpp
 void propagate(int sti, int stl, int str){
        // Se há algo para atualizar, atualize()
        if(has[sti])
            st[sti] = lazy[sti];
            // Se o nó representa um segmento de tamanho maior que 1, isto é, não é terminal, propague a atualização para os filhos.
            if(stl != str){
                // O valor que cada elemento tem é o total do intervalo dividido pelo numero de elementos no intervalo
                int val = lazy[sti] / (r-l+1);
                int mid = (stl + str)/2;
                // O novo valor de um intervalo será o tamanho dele vezes o novo valor dos elementos
                lazy[sti*2 + 1] += val*(mid-stl+1);
                lazy[sti*2 + 2] += val*(str - (mid+1) + 1);
                has[sti*2 + 1] = true;
                has[sti*2 + 2] = true;
            }
            // agora não é mais necessário atualizar esse nodo
            has[sti] = false;
        }
    }
 ```

## A função de atualização em intervalo

Essa é a função que realiza a atualização de intervalos. O significado dos argumentos é:

- `sti`: id do nodo que estamos na segment tree
- `stl`: limite inferior do intervalo que aquele nodo representa(inclusivo)
- `str`: limite superior do intervalo que aquele nodo representa(inclusivo)
- `l`: limite inferior do intervalo que queremos atualizar no **vetor**
- `r`: limite superior do intervalo que queremos atualizar  no **vetor**
- `amm`: novo valor dos elementos nesse intervalo

```cpp
    void update_range(int sti, int stl, int str, int l,int r, int amm){
    
        if(stl >= l and str <= r){
            // O valor desse nodo da segtree será (número de elementos que esse intervalo representa vezes novo valor de cada elemento do intervalo)
            lazy[sti] = amm*(r-l+1);
            has[sti] = true;
            propagate(sti, stl, str);
            return;
        }

        if(stl > r  or str < l)
            return;

        int mid = (stl + str)/2;

        update_range(sti*2+1,stl,mid,l,r,amm);
        update_range(sti*2+2,mid+1,str,l,r,amm);
        st[sti] = f(st[sti*2+1],st[sti*2+2]);
    }
```

## Versão final

Essa é a versão final da nossa ED.

```cpp
class  SegTree{
    vector<int> st;
    vector<int> lazy;
    vector<bool> has;
    int size;

    int el_neutro = -(1e9);

    int f(int a, int b){
        return a + b;
    }

     void propagate(int sti, int stl, int str){
        if(has[sti]){
            st[sti] = lazy[sti];
            if(stl != str){
                int val = lazy[sti] / (r-l+1);
                int mid = (stl + str)/2;

                lazy[sti*2 + 1] += val*(mid-stl+1);
                lazy[sti*2 + 2] += val*(str - (mid+1) + 1);

                has[sti*2 + 1] = true;
                has[sti*2 + 2] = true;
            }
            has[sti] = false;
        }
    }

    int query(int sti, int stl, int str, int l, int r){
        propagate(sti, stl, str);

        if(str < l || r < stl)
            return el_neutro;


        if(stl >= l and str <= r)
            return st[sti];

        int mid = (str+stl)/2;

        return f(query(sti*2+1,stl,mid,l,r),query(sti*2+2,mid+1,str,l,r));
    }

    void update_range(int sti, int stl, int str, int l,int r, int amm){
    
        if(stl >= l and str <= r){
            lazy[sti] = amm*(r-l+1);
            has[sti] = true;
            propagate(sti, stl, str);
            return;
        }

        if(stl > r  or str < l)
            return;
        int mid = (stl + str)/2;
        update_range(sti*2+1,stl,mid,l,r,amm);
        update_range(sti*2+2,mid+1,str,l,r,amm);
        st[sti] = f(st[sti*2+1],st[sti*2+2]);
    }

    public:
        SegTree(int n):  st(4*n,0), lazy(4*n,0),has(4*n,false){size = n;}
        int query(int l, int  r){return query(0,0,size-1,l,r);}
        void update_range(int l, int r, int amm){update_range(0,0,size-1,l,r,amm);}
};

```
