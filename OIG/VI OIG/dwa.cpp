#include<stdio.h>
#include<set>
using namespace std;

char s1[1000009], s2[1000009];
int pnp, strle, Q; //Pierwsza niepasujaca literka
int lastans;
set<int> lpnp; //Potrzebny do przyspieszenia kilku operacji

int main(){
	scanf("%d", &strle);
	scanf("%s %s", &s1, &s2);
	
	for(pnp=0;pnp<=strle; ++pnp)
		if(s1[pnp]!=s2[pnp])
			lpnp.insert(pnp);
	
	if(lpnp.empty())pnp=strle;
	else pnp=*lpnp.begin();
	
	if(pnp>=strle)lastans=0;
	else if(s1[pnp]>s2[pnp])lastans=1;
	else if(s2[pnp]>s1[pnp])lastans=2;

	scanf("%d", &Q);
	while(Q){
		int a,b;
		scanf("%d %d", &a, &b);
		
		//Słowa identyczne po zamianie
		if(s1[a]==s2[b]){
			printf("%d\n",lastans);
			--Q;
			continue;
		}

		if(a>pnp && b>pnp){
			printf("%d\n", lastans);//Kolejnosć się nie zmieni
			//Zamieniamy litery
			char c;
			c=s1[a];
			s1[a]=s2[b];
			s2[b]=c;
			
			if(s1[a]!=s2[a])lpnp.insert(a);
			else lpnp.erase(a);
			
			if(s1[b]!=s2[b])lpnp.insert(b);
			else lpnp.erase(b);
		}
		
		//Kolejnosć może się zmienić
		if(a<=pnp || b<=pnp){
			//Zamieniamy litery
			char c;
			c=s1[a];
			s1[a]=s2[b];
			s2[b]=c;
			
			if(s1[a]!=s2[a])lpnp.insert(a);
			else lpnp.erase(a);
			
			if(s1[b]!=s2[b])lpnp.insert(b);
			else lpnp.erase(b);
			//Porównanie słów
			int min=a<b?a:b;
			if(s1[min]==s2[min]){//Mamy problem, musimy użyć seta
				if(lpnp.empty())pnp=strle;
				else pnp=*lpnp.begin();
			
				if(pnp>=strle)lastans=0;
				else if(s1[pnp]>s2[pnp])lastans=1;
				else if(s2[pnp]>s1[pnp])lastans=2;
			}
			else if(s1[min]>s2[min]){
				lastans=1;
				pnp=min;
			}
			else {
				lastans=2;
				pnp=min;
			}

			printf("%d\n", lastans);
		}

		--Q;
	}
	
	return 0;
}
