#include <bits/stdc++.h>
using namespace std;


int main(){
	
	// C++ tem o tipo string
	string s1,s2;
	printf("Digite a primeira string(s1)\n");
	cin >> s1;
	printf("Digite a segunda string(s2)\n");
	cin >> s2;
	// c++ permite concatenação de
	// strings usando o operador +
	printf("s1 + s2:\n"); // nada impede de continuar usando printf
	cout << s1 + s2 << '\n';
	printf("s2 + s1:\n");
	cout << s2 + s1 << '\n';

	// c++ também permite comparação de strings
	if(s1 > s2)
		printf("s2 vem antes na ordem ASCII\n");
	else if (s1 < s2)
		printf("s1 vem antes na ordem ASCII\n");
	else
		printf("s1 e s2 sao iguais\n");
	
	printf("\n\n\n");	
	string numero = "12345";	
	int n = stoi(numero); //stoi significa string to int (se quiser long long é stoll)
	printf("%d\n",n);
	numero = to_string(n);
	cout << numero << '\n'; // para fazer IO com strings, precisa ser com cin e cout.
}
	
