#include<cstdio>
#include<vector>
#include<utility>
using namespace std;

vector<int> G[1005];
vector< pair<int,int> > E;
int n;

int DFS(int v, int p)
{
	int ret=1;

	for(int i=0; i<G[v].size(); ++i)
		if(G[v][i] != p)
			ret+= DFS(G[v][i], v);
	
	return ret;
}

int main()
{
	scanf("%d", &n);
	
	for(int i=1; i<n; ++i){
		int a,b;
		scanf("%d%d", &a, &b);
		G[a].push_back(b);
		G[b].push_back(a);
		
		E.push_back( make_pair(a,b) );
	}
	
	int maxw=0;
	for(int i=0; i<E.size(); ++i){
		int a = DFS(E[i].first, E[i].second);
		int b = DFS(E[i].second, E[i].first);
		
		if(a*b > maxw)
			maxw=a*b;
	}
	
	printf("%d\n", maxw);
}
