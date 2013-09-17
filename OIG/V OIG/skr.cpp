#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

typedef long long int LL;

vector<LL> liczby;

bool isPrime(LL num)
{
	if(num<2)
		return false;
	
	for(LL i=2; i*i<=num; ++i)
		if(num%i==0)
			return false;
	
	return true;
}

void generate()
{
	queue<LL> q;
	
	q.push(2);
	q.push(3);
	q.push(5);
	q.push(7);
	
	while(!q.empty()){
		LL tmp = q.front();
		q.pop();
		
		if(!isPrime(tmp))
			continue;
		
		liczby.push_back(tmp);
		q.push(tmp*10 + 1);
		q.push(tmp*10 + 3);
		q.push(tmp*10 + 7);
		q.push(tmp*10 + 9);
	}
}

int main()
{
	LL a,b;
	scanf("%lld%lld", &a, &b);
	
	generate();
	
	int wynik=0;
	for(int i=0; i<liczby.size(); ++i)
		if(liczby[i]>=a && liczby[i]<=b)
			++wynik;
	
	printf("%d\n", wynik);
}
