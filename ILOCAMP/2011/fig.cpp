#include <stdio.h>

int main(){
    int a, b, c;
    long long int n;

    scanf("%lld", &n);
    n-=3;
    scanf("%d%d%d", &a, &b, &c);
    if(a!=b && b!=c && a!=c){printf("TAK"); return 0;}
    while(n){
        a=b;
        b=c;
        scanf("%d", &c);
        if(a!=b && b!=c && a!=c){printf("TAK"); return 0;}
        --n;
    }

    printf("NIE\n");
    return 0;
}
