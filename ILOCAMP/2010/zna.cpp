#include <stdio.h>

inline void numout(long long int a){
    if(a<0)printf("(%lld)", a);
    else printf("%lld", a);
}

inline void out(char sgn, long long int a, long long int b){
    numout(a);
    printf("%c", sgn);
    numout(b);
    printf("=");

    if(sgn=='+')numout(a+b);
    if(sgn=='-')numout(a-b);
    if(sgn=='*')numout(a*b);
}

int main(){
    long long int a, b;

    scanf("%lld%lld", &a, &b);
    if(a+b == a-b){printf("NIE\n"); return 0;}
    if(a+b == a*b){printf("NIE\n"); return 0;}
    if(a*b == a-b){printf("NIE\n"); return 0;}

    if((a+b > a-b) && (a+b>a*b)){out('+',a,b); return 0;}
    if((a-b > a+b) && (a-b>a*b)){out('-',a,b); return 0;}
    if((a*b > a-b) && (a*b>a+b)){out('*',a,b); return 0;}
    return 0;
}
