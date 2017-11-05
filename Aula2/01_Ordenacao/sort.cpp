#include <bits/stdc++.h>
using namespace std;

void imprime(int* v,int n){
	for (int i = 0; i < n; ++i)
	{
		printf("%d ",v[i]);
	}
	printf("\n");
}

int main(){

	int vetor[10] = {9,2,1,6,5,3,4,8,7,0};

	printf("Antes de ordenar:\n");
	imprime(vetor,10);
	sort(vetor,vetor+10); // ordene da posicao de memória v até a posicao de memória v+10 (nao inclui v+10)
	printf("Após de ordenar:\n");
	imprime(vetor,10);





}
