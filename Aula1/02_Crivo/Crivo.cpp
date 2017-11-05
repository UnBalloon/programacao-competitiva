#include <bits/stdc++.h>

int main(){

	int eh_primo[1000005];
	int primos[100005]; // vetor de tamanho suficiente para salvar todos os primos até 1000005
	
	int limite = 1000000, tamvetor = 0;
	
	// no começo consideramos que todos são primos
	for(int i = 2; i <= 1000000; ++i) {
		eh_primo[i] = 1;
	}
	
	for(long long i = 2; i <= 1000000; ++i) {
		if(eh_primo[i] == 1) {
			primos[tamvetor] = i; // salvamos o novo primo no vetor de primos
			tamvetor++;
			for(long long j = i*i; j <= 1000000; j += i) {
				eh_primo[j] = 0; // marcamos que j não é primo, pois é multiplo de i
			}
		}
	}

	for(int i = 0; i < tamvetor; ++i) {
		printf("%d\n", primos[i]);
	}
	
	return 0;
}
