#include <bits/stdc++.h>
using namespace std;

/* Funcao que encontra a raiz quadrada
   por meio de busca binária */
double raiz(double k)
{
	double l = 0.0;
	double r = k+1;


	for (int i = 0; i <= 100; ++i)
	{
		double mid = (l + r)/2;

		/* se esse número ao quadrado
		é maior do que k, então ele é
		maior que a raiz, logo todos
		acima dele são maiores que a 
		raiz, então cortamos essa 
		metade de cima do intervalo

		o mesmo vale para caso o número
		ao quadrado seja menor que k*/
		if(mid*mid > k)
			r = mid;
		else
			l = mid;
	}
	return l;
}


int main(){

	printf("%lf\n",raiz(2) );
	printf("%lf\n",raiz(3) );
	printf("%lf\n",raiz(4) );
	printf("%lf\n",raiz(5) );

}