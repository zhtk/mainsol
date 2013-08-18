#include<stdio.h>

int *tab;

int main(){
	int liczbap, ap, max=0, min=0;
	scanf("%d %d", &liczbap, &ap);
	
	tab=new int[liczbap];
	for(int i=0; i<liczbap; ++i)tab[i]=0;
	
	while(ap){
		int num;
		scanf("%d", &num);
		--num;
		
		if(num==liczbap) min=max;
		else {
			if(tab[num]<min)tab[num]=min;
			++tab[num];
			if(tab[num]>max)max=tab[num];
		}
		
		--ap;
	}
	
	for(int i=0; i<liczbap; ++i) if(tab[i]<min)tab[i]=min;
	for(int i=0; i<liczbap; ++i)printf("%d ", tab[i]);
	
	return 0;
}
