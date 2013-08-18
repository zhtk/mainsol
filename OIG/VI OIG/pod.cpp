#include<stdio.h>

long long int map_l=0, map_p=0, map_g=0, map_d=0;
long long int x=0,y=0;
char tmps[1000009];

int main(){
	int n;
	scanf("%d", &n);
	
	while(n){
		int repet; //Liczba powtórzeń ciagu
		int wekx=0, weky=0; //wektor przesunięcia
		int kl=0, kr=0, ku=0, kd=0; //Współrzędne kwadratu
		//Przygotuj dane:
		scanf("%d %s", &repet, &tmps);
	
		int i=0;
		while(tmps[i]!='\0'){
			if(tmps[i]=='N')++weky;
			if(tmps[i]=='S')--weky;
			if(tmps[i]=='E')++wekx;
			if(tmps[i]=='W')--wekx;
		
			if(weky>ku)ku=weky;
			if(weky<kd)kd=weky;
			if(wekx>kr)kr=wekx;
			if(wekx<kl)kl=wekx;
		
			++i;
		}
		
		if(wekx>0) kr+=(repet-1)*wekx;
		if(wekx<0) kl+=(repet-1)*wekx;
		if(weky>0) ku+=(repet-1)*weky;
		if(weky<0) kd+=(repet-1)*weky;
		
		//Os x tj. W<->E
		if(x+kr>map_p)map_p=x+kr;
		if(x+kl<map_l)map_l=x+kl;
		//Os Y
		if(y+ku > map_g)map_g=y+ku;
		if(y+kd < map_d)map_d=y+kd;
		
		//Aktualizacja współrzędnych o wektor
		x+=wekx * repet;
		y+=weky * repet;
	
		--n;
	}
	
	printf("%lld %lld\n", map_g - map_d, map_p - map_l);
	return 0;
}
