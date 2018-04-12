# Busca binária

Busca binária é um algoritmo de divisão e conquista usado em sua maior parte para minimizar o tempo de uma busca linear.

Imagine você com um livro de 1000 páginas em mãos no momento em que o professor pede para que o abra no começo do capitulo 6 seção 4. Existem várias maneiras de se alcançar a página certa. Uma delas é ir de uma em uma até que se alcance a página desejada. Outra maneira é ir pulando alguns blocos de páginas, se você está numa página depois do começo do capitulo 6 seção 4 pula algumas páginas para tras, se você está numa página antes, pula algumas páginas para frente.

Perceba que no exemplo acima uma busca linear (passar de página em página) demoraria muito mais do que ir pulando algumas partes do livro. E fazendo da segunda maneira involuntariamente você acaba aplicando uma versão primitiva do que chamamos de busca binária.

## O algortimo

Usando a mesma ideia do livro porém agora em uma linguagem mais computacional. No lugar de 1000 páginas podemos ter um vetor de 1000 posições onde a i-ésima tem um pair <capitulo, seção> da pagina i, por exemplo, se a página 125 faz parte do capítulo 4 seção 2 então `v[125] = make_pair(4, 2);`. E digamos que o capítulo 6 seção 4 está na página 375(que não sabemos no começo da busca).

Primeiro podemos, por exemplo, para a página 400. A partir do pair daquela posição aprendemos que o que procuramos está antes de 400, então agora não precisamos procurar a resposta no intervalo [1, 1000] e sim no intervalo [1, 399]. Podemos fazer um segundo chute na posicao 300, por exemplo pois podemos chutar em qualquer posição do intervalo, e depois de olhar v[300] aprendemos que a resposta está no intervalo [301, 399]. Podemos então chutar na página 375 e encontrar que esta é a resposta que procuramos.

O único problema do que foi descrito acima é determinar como chutar o elemento dentro do intervalo já que os chutes foram meio aleatórios. O primeiro chute foi no elemento 400 num intervalo [1, 1000], depois de olhar o elemento poderíamos passar a ter que olhar o intervalo \[1, 399\](se o que procuramos está antes) ou \[401, 1000\](se o que procuramos está depois), tivemos sorte e caimos no primeiro caso mas no pior caso poderíamos cair no intervalo maior. O jeito de garantirmos de no pior caso sempre irmos para um intervalo de menor tamanho possivel é chutar de uma forma a dividir o intervalo em 2 intervalos de tamanhos (aproximadamente) iguais. Podemos fazer isso só chutando na metade do intervalo, assim é melhor fazer o primeiro chuta na posição 500 e nao 400.

Perceba que o algoritmo é bastante simples porém precisamos de uma condição muito importante para que ele funcione! No momento em que é dividido pela metade nós fazemos uma pergunta para saber que parte podemos descartar, e para que seja possível responder a essa pergunta precisamos garantir que nossa função seja crescente ou decrescente. Imagine esse exemplo simples, temos o seguinte vetor [3, 1, 5, 4, 2] e buscamos o valor 2. Na primeira vez que dividirmos e perguntarmos se o valor 5 é menor, igual ou maior que 2 teremos a resposta que 5 é maior que 2 e com isso iriamos descartar todos os elementos a direita de 5 e junto com esses elementos o 2 iria embora e nunca iríamos achar resposta.

Formalmente falando, seja uma função F ordenada para verificarmos se um dado valor X pertence a F basta selecionar o elemento no centro do segmento e verificar se seu valor é menor, igual ou maior que X e com isso diminuir o segmento de maneira condizente com a resposta, faremos isso até que se ache X ou que não tenha mais segmento para ser dividido.

## Complexidade

Tudo muito massa, mas falta a complexidade! Depois de saber isso podemos começar a aplicar esse algoritmo nos problemas por ae :)

Suponha um vetor ordenado de tamanho N onde vamos aplicar o algoritmo de busca binária e o valor procurado não está presente no vetor (pior caso). Na nossa primeira iteração iremos dividir o vetor em 2 partes ou seja teremos N/2 elementos restantes, na segunda iteração iremos dividir do que restou e teremos (N/2)/2 ou seja N/4, seguindo essa lógica na K-ésima iteração vamos dividir o tamanho do vetor K vezes por 2, ou seja, N/(2^K) e como estamos calculando complexidade temos que pensar no pior caso, quando chegarmos no ponto onde teremos um espaço de apenas 1 elemento(e verificamos que o elemento não está no vetor). O que estamos buscando para saber a complexidade é K (quantidade de passos) para o pior caso então temos que N/(2^K) = 1 daí temos que N = 2^K e tirando o log2 dos dois lados temos que K = log2(N). Então no pior caso nosso algortimo demora `O(log2(N))` passos, N sendo o tamanho do vetor inicial.

## Ressalvas

Existem muitas aplicações interessantes relacionadas a busca binária. Nesse documento ressaltamos apenas a aplicação mais simples para que se torne simples e didático esse primeiro contato com o algoritmo.

Só foi falado que a quantidade de passos da busca bínaria é `O(log2(n))`, e em cada passo avaliamos se achamos o que queremos ou para qual metade está o que procurarmos. Esta avaliação pode ser simples, como no exemplo e ser `O(1)`, mas pode ser bem complexa e demorar `O(m)`, fazendo o algoritmo rodar em tempo `O(m*log2(n))`.

## Exemplo de código

Consideremos o problema de achar o indice do primeiro elemento maior ou igual um `x` num vetor `v` de tamanho `n`.

```c++
int v[MAXN], n; // vetor global para facilitar o código

// funcao que retorna se id é uma resposta válida pro nosso problema
bool check(int id, int x){
    return v[id] >= x;
}

// retorna o indice do primeiro elemento >= x, considerando que o vetor v está ordenado
// se todos os elementos sao menores que x, retorna -1
int lower_bound(int x){
    int L, R, ans;
    L = 0; // começo do intervalo que consideraremos
    R = n-1; // fim do intervalo que consideraremos
    ans = n; // começamos a resposta com um valor fora do vetor, inválido para marcar se conseguimos achar alguma resposta ou nao
    while(L <= R){ // enquanto tiver algum número no intervalo
        int mid = (L+R)/2;
        if(check(mid, x)){ // se esse mid é uma resposta apropriada
            ans = mid; // achamos uma nova resposta para o problema
            R = mid-1; // se mid é uma resposta temos que tentar procurar uma resposta menor(nesse problema em especifico)
        }
        else{ // se mid nao é uma resposta pro nosso problema
            L = mid+1; // precisamos procurar em indices maiores(neste problema)
        }
    }
    if(ans == n) return -1; // se ans ainda é n depois da busca binária, então nunca achamos resposta
    return ans;
}
```

Perceba que se quisermos achar o indice do último elemento maior ou igual um `x` num vetor `v` de tamanho `n`.

```c++
int v[MAXN], n; // vetor global para facilitar o código

// funcao que retorna se id é uma resposta válida pro nosso problema
bool check(int id, int x){
    return v[id] >= x;
}

// retorna o indice do primeiro elemento >= x, considerando que o vetor v está ordenado
// se todos os elementos sao menores que x, retorna -1
int lower_bound(int x){
    int L, R, ans;
    L = 0; // começo do intervalo que consideraremos
    R = n-1; // fim do intervalo que consideraremos
    ans = n; // começamos a resposta com um valor fora do vetor, inválido para marcar se conseguimos achar alguma resposta ou nao
    while(L <= R){ // enquanto tiver algum número no intervalo
        int mid = (L+R)/2;
        if(check(mid, x)){ // se esse mid é uma resposta apropriada
            ans = mid;  // achamos uma nova resposta para o problema
            L = mid+1; // se mid é uma resposta temos que tentar procurar uma resposta maior(nesse problema em especifico)
        }
        else{ // se mid nao é uma resposta pro nosso problema
            R = mid-1; // precisamos procurar em indices menores(neste problema)
        }
    }
    if(ans == n) return -1; // se ans ainda é n depois da busca binária, então nunca achamos resposta
    return ans;
}
```

Em ambos os exemplos a complexidade de checar se mid é uma resposta válida para o problema é `O(1)`. Portanto a complexidade total é `O(lg n)`.
