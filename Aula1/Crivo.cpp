#include <bits/stdc++.h>


int mark[1000005];
int primos[100005];
int main(){


	int cont = 0;
	for (long long i = 2; i <= 1000000; ++i)
	{
		if(mark[i] == 0)
		{		
			primos[cont] = i;
			cont++;
			for (long long j = i*i; j <= 1000000; j += i)
			{
				mark[j] = 1;
			}
		}
	}

	for (int i = 0; i < cont; ++i)
	{
		printf("%d\n",primos[i]);
	}


}