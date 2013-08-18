#include<cstdio>
#include<algorithm>
using namespace std;

const int MAX_EDGES = 300003;

struct edge{
    int pocz, kon, w, nr;
    bool odp;
} kraw[MAX_EDGES];

int n,m;

bool wcmp(const edge& e1, const edge& e2){
    return e1.w<e2.w;
}

bool idcmp(const edge& e1,const edge& e2){
    return e1.nr < e2.nr;
}

//Find && Union
int findtab[7009];

void fau_init(){
    for(int i=0; i<7009; ++i)findtab[i]=i;
}

int find(int x){
    if(findtab[x]==x)return x;
    return findtab[x]=find(findtab[x]);
}

void uni(int a, int b){
    findtab[find(a)]=find(b);
}
//MST
void build_mst(){
    sort(kraw, kraw+m, wcmp);
    
    int lastw = kraw[0].w;
    int last = 0;
    
    for(int i=0; i<m; ++i){
        if(kraw[i].w != lastw){
            while(last < i){
                uni(find(kraw[last].pocz), find(kraw[last].kon));
                ++last;
            }
            
            lastw = kraw[i].w;
        }
        
        if(find(kraw[i].pocz) != find(kraw[i].kon))
            kraw[i].odp=1;
    }
}

int main(){
    scanf("%d%d", &n, &m);
    fau_init();
    
    for(int i=0; i<m; ++i)scanf("%d%d%d",&kraw[i].pocz, &kraw[i].kon, &kraw[i].w), kraw[i].nr=i;
    
    build_mst();
    //odpowiadamy na zapytania
    sort(kraw, kraw+m, idcmp);
    
    for(int i=0; i<m; ++i){
        if(kraw[i].odp)printf("TAK\n");
        else printf("NIE\n");
    }
    
    return 0;
}
