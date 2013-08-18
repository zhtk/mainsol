#include<cstdio>

int n, tab[30], max;

int main(){
    scanf("%d", &n);
    
    for(int i=0; i<n; ++i)scanf("%d", tab+i);
    for(int i=0; i<n; ++i)
        if(tab[i]>max)max = tab[i];
    for(int i=0; i<n; ++i)
        if(tab[i] == max)printf("%c", 'A'+i);
    printf("\n");
}
