# Sparse Table

## Recorrência


## Versão recursiva

```cpp
int memo[SIZE][log2(SIZE)+1];
vector<int> v(SIZE);
int dp(int i, int k) {
	if(k == 0) {
		return v[i];
	}
	if(memo[i][k] != -1) return memo[i][k];
	return memo[i][k] = min(dp(i,k-1),dp(i + (1 << (k-1)), k-1));
}
```

## Versão iterativa