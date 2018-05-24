# Programação dinâmica

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