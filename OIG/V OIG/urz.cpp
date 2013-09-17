#include <cstdio>

const int MTAB = 1e6+10;
int n, tree[MTAB], size[MTAB], ans[MTAB];

int main(){
	scanf("%d", &n);
	
	for(int i=2; i<=n; ++i)
		scanf("%d", &tree[i]);
	
	for(int i=n; i; --i){
		size[ tree[i] ]+=size[i]+1;
		
		if(ans[i]*2 < size[i])
			++ans[i];
		
		ans[ tree[i] ]+=ans[i];
	}
	
	printf("%d\n", ans[1]);
	return 0;
}
