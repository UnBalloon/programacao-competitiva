http://codeforces.com/contest/702/problem/B

Com map em c++
```cpp
#include <bits/stdc++.h>

using namespace std;

int main(){
	vector<int> pows2;
	int p = 1;
	while(p <= 2000000000){
		pows2.push_back(p);
		p *= 2;
		printf("%d\n",p );
	}

	int n;
	scanf("%d",&n);
	int a;
	map<int,int> nums;
	long long ans = 0;

	for(int i = 0; i < n; i++){
		scanf("%d",&a);
		for(int j : pows2)
			ans += nums[j - a];
		nums[a]++;
	}

	printf("%lld\n",ans );
	return 0;
}
```

Em C
```cpp
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void mergi(int vet[],int ini,int mid,int fim){
  static int left[100001], right[100001];
  memcpy(left,&vet[ ini], sizeof(int)*(mid-ini+1));
  memcpy(right,&vet[mid+1], sizeof(int)*( fim-mid));
  left[mid-ini+1]=1000000001;
  right[fim-mid]=1000000001;
  for(int i=ini,j=0,k=0;i<=fim;i++){
    vet[i]=(left[j]<=right[k] ? left[j++] :right[k++]);
  }
}

void mergesort(int v[],int inicio,int fim){
  int meio;
  if(fim <= inicio) {
    return;
   }
   meio = (inicio + fim) / 2;
   mergesort(v,inicio,meio);
   mergesort(v,meio+1,fim);
   mergi(v,inicio,meio,fim);
}

int buscab(int v[],int inicio,int fim,int x,int* i,int *f){
  int meio;
  *i = inicio;
  *f = fim;
  if(fim < inicio){
    return -1;
   }
  meio = (inicio+fim)/2;
  if(v[meio] == x){
  	if(v[inicio] == x){
  		if(v[fim] == x){
    			return meio;
  		}
  		else{
  			while(v[fim] > x){
  				fim--;
  			}
  			return buscab(v,inicio,fim,x,i,f);
  		}
  	}
  	else{
  		while(v[inicio] < x)
  			inicio++;
  		return buscab(v,inicio,fim,x,i,f);
  	}
  }
  else if(x < v[meio])
    return buscab(v,inicio,meio-1,x,i,f);
  
  else
    return buscab(v,meio+1,fim,x,i,f);
  
}

int main(){
	int n, x, y, vet[31], lido[100000], rep[100000], c, i, j, f, d, ini, fim;
	long long ans;
	
	scanf("%d",&n);
	for(i = 0; i < n; i++)
		scanf("%d",&lido[i]);
	for(i = 1; i <= 30; i++)
		vet[i] = pow(2,i);
	ans = 0;
	mergesort(lido,0,n-1);

	for(x = 0; x < n; x++){
		for(i = 1; i <= 30; i++){
			c = vet[i] - lido[x];
			f = buscab(lido,0,n-1,c,&ini,&fim);
			if(f != -1){
				ans += fim + 1 - ini;
				if(x >= ini && x <= fim)
					ans--;
			}
		}
	}
	printf("%lld\n",ans / 2);
	return 0;
}
```
