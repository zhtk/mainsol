// http://main.edu.pl/pl/archive/oig/5/tor
#include <cstdio>
#include <algorithm>

const int MAX_PRT_CNT = 2e5 + 10;

int a, b, n;
long long int k;
int odstx[MAX_PRT_CNT], odsty[MAX_PRT_CNT];

void computeParts()
{
	int px[n+5], py[n+5];
	px[0]=py[0]=0;
	
	for(int i=1; i<=n; ++i)
		scanf("%d", &px[i]);
		
	for(int i=1; i<=n; ++i)
		scanf("%d", &py[i]);
		
	px[n+1] = a;
	py[n+1] = b;
	
	++n;
	
	for(int i=0; i<n; ++i){
		odstx[i] = px[i+1] - px[i];
		odsty[i] = py[i+1] - py[i];
	}
}

// Liczba kawałków mniejszych od p (pole)
long long int countParts(long long int p)
{
	long long int wynik = 0;
	int x=n-1, y=0;
	
	while(y<n && x>=0){
		if((long long int)odstx[x]*odsty[y] < p)
			wynik+=x+1, ++y;
		else --x;
	}
	
	return wynik;
}

long long int search()
{
	long long int p=0, e=(long long int)a*b;
	
	// Konwersja k na numer od najmniejszego
	k = (long long int)n*n-k+1;

	// Wyszukiwanie binarne
	while(p!=e){
		long long int avg = (p+e)/2;
		
		// Zapobiegamy zapętleniu
		if(p+1==e)
			break;
		
		if(countParts(avg)<k)
			p=avg;
		else
			e=avg;
	}
		
	return p;
}

int main()
{
	scanf("%d%d%d%lld", &a, &b, &n, &k);
	computeParts();
	
	std::sort(odstx, odstx+n);
	std::sort(odsty, odsty+n);
	
	printf("%lld\n", search());
}
