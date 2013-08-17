#include <stdio.h>

int main(){
    long long int n, i1, i2, l=0;
    bool rev=false;

    scanf("%lld", &n);

    i1=1;
    while(i1<=n){
        i2=0;
        while(i2<n){
            if(!rev){++l; printf("%ld ", l);}
            if(rev) printf("%ld ", l+n-i2);
            ++i2;
        }
        if(rev) l+=n;
        rev= !rev;
        printf("\n");
        ++i1;
    }
    return 0;
}
