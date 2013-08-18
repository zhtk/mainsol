#include <stdio.h>
#include <string.h>

int n,k;
char s1[2009], s2[2009];
int wynik=0;

void pl(){
	for(int i=0;1;++i){
		s1[i]=getchar();
		
		if(s1[i]=='\n' || s1[i]==EOF){// EOF - bugfix na test 0c
			s1[i]='\0';
			break;
		}
	}
	
	for(int i=0;1;++i){
		s2[i]=getchar();
		
		if(s2[i]=='\n' || s2[i]==EOF){
			s2[i]='\0';
			break;
		}
	}
	
	int s1s=0, s2s=0;
	int s1len=strlen(s1);
	int s2len=strlen(s2);
	
	if(s1len<k && s2len<k)return;
	
	//Takie same koncowki?
	int k1=k;
	while(k1 && s1len && s2len){
		if(s1[s1len-1]==' '){--s1len; continue;}
		if(s2[s2len-1]==' '){--s2len; continue;}
		
		if(s1[s1len-1]!=s2[s2len-1])return;
		
		--s1len; --s2len;
		--k1;
	}
	
	//if(k1)return; //???
	
	//Zliczanie samoglosek
	s1len=strlen(s1);
	s2len=strlen(s2);
	
	for(int i=0; i<s1len; ++i)if(s1[i]=='a' || s1[i]=='e' || s1[i]=='i' || s1[i]=='o' || s1[i]=='u' || s1[i]=='y')++s1s;
	for(int i=0; i<s2len; ++i)if(s2[i]=='a' || s2[i]=='e' || s2[i]=='i' || s2[i]=='o' || s2[i]=='u' || s2[i]=='y')++s2s;
	
	if(s1s!=s2s)return;
	++wynik;
}

int main(){
	scanf("%d %d", &n, &k);
	getchar();
	
	while(n){
		pl();
		--n;
	}
	
	printf("%d\n", wynik);
	return 0;
}
