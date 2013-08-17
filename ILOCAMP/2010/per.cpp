#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long int n, l;
vector<long long int> v;

int main()
{
    ios_base::sync_with_stdio(0);
    cin>>n;
    
    for(long long int i=0; i<n; ++i){
		cin>>l; 
		v.push_back(l);
	}
	
    sort(v.begin(), v.end());
    
    for(long long int i=1; i<=n; ++i){
        if(v[i-1]!=i){
			cout<<"NIE"<<endl; 
			return 0;
		}
    }

    cout<<"TAK"<<endl;
    return 0;
}
