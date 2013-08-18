#include<iostream>
#include<math.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	double x, y, r;
	int dzieci, wynik=0;
	
	cin>>dzieci>>r>>x>>y;
	
	while(dzieci){
		double xp, yp;
		cin>>xp>>yp;
		
		if( ((xp-x)*(xp-x)) + ((yp-y)*(yp-y)) > r*r)
			++wynik;
		
		--dzieci;
	}
	
	cout<<wynik<<endl;
	return 0;
}
