#include <stdio.h>

int main(){
    long long int n, a=0, r=0, t;

    scanf("%lld", &n);

    while(n){
        scanf("%lld", &t);
        
        if(t) ++a;
        else ++r;
        
        --n;
    }

    if(a<r){
		printf("%ld\n", a); 
		return 0;
	}
	
    printf("%ld\n", r);
    return 0;
}
