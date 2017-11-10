#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second

int main(){
	
	//C++ tem o tipo pair
	// que é um par ordenado matemático

	pair<int,int> par1 = make_pair(0,1); //make_pair constroi um par.
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
		printf("par1 e par2 sao iguais\n");

	
	// nao precisa ser um par de inteiros
	pair<int,string> par3 = make_pair(0,"oie");
	pair<int,string> par4 = make_pair(0,"aie");
	
	// nesse exemplo, o elemento da esqueda é igual,  e o desempate será feito pelo da direita.
	if(par3 > par4)
		printf("par3 é maior\n");
	else if(par4 > par3)
		printf("par4 é maior\n");
	else
		printf("par3 e par4 sao iguais\n");
	
	printf("%d %s\n",par3.first, par3.second.c_str());
	
}
