#include<cstdio>

const int MAX_LICZBA_GOSCI = 30005;
bool vis[MAX_LICZBA_GOSCI];
int sasiad[MAX_LICZBA_GOSCI];

int n;

void bfs(int v){
    vis[v]=1;
    int av = sasiad[v];
    
    while(av!=v)vis[av]=1, av=sasiad[av];
}

int main(){
    scanf("%d", &n);
    
    for(int i=1; i<=n; ++i)scanf("%d", sasiad+i);
    
    int wynik=0;
    
    for(int i=1; i<=n; ++i)
        if(!vis[i])bfs(i), ++wynik;
    
    printf("%d\n", wynik);
}
