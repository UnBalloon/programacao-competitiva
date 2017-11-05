#include <bits/stdc++.h>
using namespace std;



int eh_primo(long long n)
{
	for (long long i = 2; i < n; ++i)
	{
		if(n % i == 0)
			return 0; // nao é primo;
	}
	return 1; //chegou ate o final, entao é primo
}
int main(){

	int n = 1e9 + 7;


	if(eh_primo(n))
		printf("%d é primo!\n", n);
	else
		printf("%d não é primo!\n",n);


}
