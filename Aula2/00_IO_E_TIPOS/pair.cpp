#include <bits/stdc++.h>
using namespace std;


int main(){
	
	//C++ tem o tipo pair
	// que é um par ordenado matemático

	pair<int,int> par1 = make_pair(0,1);
	pair<int,int> par2 = make_pair(1,0);


	// C++ permite a comparação de pares,
	// de forma que o elemento da esquerda
	// é mais importante e o da direita 
	// serve de desempate.
	if(par1 > par2)
		printf("par1 é maior\n");
	else if(par1 < par2)
		printf("par2 é maior\n");
	else
		printf("sao iguais\n");

	
}
	