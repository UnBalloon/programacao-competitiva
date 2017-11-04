#include <bits/stdc++.h>


int v[100005];
int psum[100005];

/* respondendo soma de intervalos do vetor
		seja a o indice do primeiro elemento e 
		b o indice do ultimo elemento da soma,
		a soma nesses intervalos será psum[b] - psum[a-1]
		só é necessário tratar o caso de a = 0 para não
		acessar posicao negativa no vetor */
int pergunta(int a, int b)
{
	if(a == 0)
		return psum[b];
	else
		return psum[b] - psum[a-1];
}


int main(){

	int n = 100000;
	/* loop de leitura do vetor 

		nesse exemplo, o vetor será preenchido com dados aleatórios */

	for (int i = 0; i < n; ++i)
	{
		v[i] = rand() % 100;
	}
	
	/* loop de calculo da soma prefixa */
	int soma_acumulada = 0;
	for (int i = 0; i < n; ++i)
	{
		soma_acumulada += v[i];
		psum[i] = soma_acumulada;
	}

	/* a funcao pergunta diz a soma de um determinado
	   intervalo em complexidade O(1) com esse
	   pré-processamento */
}