#include<stdio.h>
unsigned long long int leftt[1000000], rightt[1000000];
unsigned long long int n, i, maxl, tmp;

int main()
{
    scanf("%llu", &n);
    maxl=0;
    
    for(i=0;i<n;++i){
        scanf("%llu", &tmp);//cin>>tmp;
        rightt[i]=tmp;
        if(maxl<tmp){maxl=tmp;}
        leftt[i]=maxl;
    }

    maxl=0;
    for(i=n-1;i+1;--i){
        if(maxl<rightt[i]){maxl=rightt[i];}
        rightt[i]=maxl;
    }

    for(i=0;i<n;++i)
        printf("%llu %llu\n", leftt[i], rightt[i]);
    
    return 0;
}
