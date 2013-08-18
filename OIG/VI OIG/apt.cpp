//Apteka
#include<iostream>
#include<vector>
using namespace std;

int lo;

int main(){
	cin>>lo;
	vector<long long int> kol(lo+2);
	vector<int> min(lo+2);
	for(int i=0; i<lo; ++i)cin>>kol[i+1];
	
	long long int wynik=0, minimalna=kol[lo]+5, lpos=lo;
	
	for(int i=lo;i>=0;--i){
		min[i]=lpos;
		
		if(kol[i]<minimalna){
			lpos=i;
			minimalna=kol[i];
		}
	}
	
	//Oblicz
	lpos=0;
	
	while(lpos!=lo){
		wynik+=kol[min[lpos]] * (min[lpos] - lpos);
		lpos=min[lpos];
	}
	
	cout<<wynik<<endl;
}
