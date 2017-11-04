Complexidade
============

O tema da primeira aula é Complexidade de algoritmos.

O que é Complexidade?
---------------------

Em linhas gerais, a complexidade de um algoritmo é o quanto as variáveis de entrada impactam no seu tempo de execução.

Para se referir a complexidade de um algoritmo, se usa a notação O(complexidade)



Exemplos:


```
  printf("Hello World\n");
```

Esse código tem complexidade O(1) (também chamado de complexidade constante), porque nennhuma variável de entrada impacta no seu tempo de execução.

```
int n;
scanf("%d",&n);
for(int i = 0; i < n; i++){
    printf("%d\n",i);
}
```

Esse código tem complexidade O(n), pois o seu tempo tempo de execução cresce linearmente dependendo da variável n.

