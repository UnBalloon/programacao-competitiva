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

	int v[10] = {9,8,7,6,5,4,3,2,1,0};
	imprime(v,10);
	sort(v,v+10); // ordene da posicao de memória v até a posicao de memória v+10 (nao inclui v+10)
	imprime(v,10);
}
