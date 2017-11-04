Soma Prefixa
============


Soma prefixa é uma técnica útil quando você precisa responder várias vezes uma pergunta do seguinte tipo

dado o vetor v = {1,3,5,-3,1,12,20,-3,2}, qual é a soma de todos os elementos contidos entre os indices a e b ?
Por exemplo, se a = 0 e b = 3, queremos a soma 1 + 3 + 5 + (-3).

Cada pergunta sobre a soma de um determinado intervalo pode ser respondida com um laço de repetição do estilo

```
int pergunta(int a, int b){

    int resposta = 0;
    for(int i = a; i <= b; i++){
        resposta += v[i];
    }
    return resposta;
}
```

Mas isso resultaria em complexidade O(n) para cada pergunta, o que vem a ser ineficiente. 
Fazendo o pré-processamento de soma prefixa, é possível responder cada pergunta em complexidade O(1)

cada índice do vetor de soma prefixa significa "Qual é a soma de todos os elementos anteriores a este índice?"

v    = {1,3,5,-3,1,12,20,-3,2}
psum = {1,4,9,6,7,19,39,36,38}


Tendo essas informações, a resposta pra cada pergunta pode ser obtida da seguinte forma:

int pergunta(int a, int b){
    if(a != 0)
        return psum[b] - psum[a-1];
    else
        return psum[b];
}
