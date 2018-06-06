# Programação dinâmica	

Explicação

# Exemplos	 

## Fibonacci 

Calcular o valor da função de fibonacci
```cpp	
int tb[1005];	
	
int dp(int n){	
	if(n == 0)	
		return 0;	
	if(n == 1)	
		return 1;	
	if(tb[n] != -1)	
		return tb[n];	
	tb[n] = (dp(n-1) + dp(n-2)) % 1000000007;	
	return tb[n];	
}	
	
int main(){	
	memset(tb,-1,sizeof(tb));	
}	
```	

## Problema das moedas

```cpp	
int tb[1005];	
	
int size;	
vi valor;	
	
int dp(int n){	
	if(n >= size)	
		return 0;	
	if(tb[n] != -1)	
		return tb[n];	
	
	tb[n] = max(dp(n+1), dp(n+2) + valor[n]);	
	return tb[n];	
}	
	
int main(){	
	memset(tb,-1,sizeof(tb));	
}	
```


# VideoAulas complementares

## MIT (esse professor é top)
https://www.youtube.com/watch?v=OQ5jsbhAv_M

## HackerRank
https://www.youtube.com/watch?v=P8Xa2BitN3I
