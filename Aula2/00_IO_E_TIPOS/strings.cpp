#include <bits/stdc++.h>
using namespace std;


int main(){
	
	// C++ tem o tipo string
	string s,s1;
	cin >> s;
	cin >> s1;
	// c++ permite concatenação de
	// strings usando o operador +
	printf("s + s1:\n"); // nada impede de continuar usando printf
	cout << s + s1 << '\n';
	printf("s1 + s:\n");
	cout << s1 + s << '\n';

	// c++ também permite comparação de strings
	if(s > s1)
		printf("s1 vem antes na ordem lexicográfica\n");
	else if (s < s1)
		printf("s vem antes na ordem lexicográfica\n");
	else
		printf("s e s1 sao iguais\n");
	
	string numero = "12345";	
	int n = stoi(numero); //stoi significa string to int (se quiser long long é stoll)
	printf("%d\n",n);
	numero = to_string(n);
	cout << numero << '\n'; // para fazer IO com strings, precisa ser com cin e cout.
}
	
