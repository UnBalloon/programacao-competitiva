http://codeforces.com/contest/702/problem/B

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
