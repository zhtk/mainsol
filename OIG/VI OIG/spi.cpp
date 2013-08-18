#include<iostream>
#include<string>
using namespace std;

int lu, wynik=0;
string str;
bool tab[1000005];

int main(){
	cin>>lu>>str;
	
	for(int i=0; i<lu; ++i) if(str[i]=='W')tab[i]=1;
	tab[lu]=1;
	
	for(int i=0; i<lu; ++i){
		if(tab[i]==0 && tab[i+1]==0){
			++wynik;
			tab[i]=1;
			tab[i+1]=1;
			tab[i+2]=1;
		}
		
		if(tab[i]==0 && tab[i+1]==1){
			++wynik;
			tab[i]=1;
		}
	}
	
	cout<<wynik<<endl;
}
