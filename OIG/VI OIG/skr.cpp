#include <cstdio>
#include <vector>
using namespace std;

const int MAXN = 1000005;

int n, m, time_ = 0;
int avcounter = 0;
bool available[MAXN];
vector<int> unvis;

void init()
{
	avcounter = 1;
	available[1] = true;
	
	unvis.reserve(n);
	for(int i=2; i<=n; ++i)
		unvis.push_back(i);
}

bool canMove(vector<int> &obs)
{
	int obscounter = 0;
	
	for(int i=0; i<obs.size(); ++i)
		if(available[ obs[i] ])
			++obscounter;
	
	return avcounter > obscounter;
}

void diff(vector<int> &obs)
{
	int i = 0, j = 0;
	vector<int> newunvis;
	
	while(i<obs.size() && j<unvis.size())
		// Pole nie jest obserwowane
		if(unvis[j] < obs[i]){
			++avcounter;
			available[ unvis[j] ] = true;
			++j;
		}
		// Pole obserwowane
		else {
			if(unvis[j] == obs[i])
				newunvis.push_back( unvis[j] ), ++j;
			++i;
		}
	
	// ZostaĹ‚y same pola ktĂłre przestaĹ‚y byc obserwowane
	while(j < unvis.size())
	{
		++avcounter;
		available[ unvis[j] ] = true;
		++j;
	}
	
	newunvis.swap(unvis);
}

void update()
{
	vector<int> obs;
	
	// Wczytanie linii
	int tmp, tmp2;
	scanf("%d", &tmp);
	for(int i=0; i<tmp; ++i){
		scanf("%d", &tmp2);
		obs.push_back(tmp2);
	}
	
	// Sprawdzamy czy jest moĹĽliwoĹ›Ä‡ wykonaÄ‡ ruch
	if(!canMove(obs))
		return;
	
	// Aktualizujemy tablicÄ™ available
	diff(obs);
}

int main() {
	scanf("%d%d", &n, &m);
	init();

	// Symulacja
	while(time_ < m){
		update();
		
		if(available[n])
			break;
		
		++time_;
	}
	
	printf("%d\n", time_);
	
	return 0;
}
