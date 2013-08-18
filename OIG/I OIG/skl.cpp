#include<cstdio>
#include<algorithm>
using namespace std;

int n;

struct raport{
    int numer, produkt, ilosc;
} tab[1000009], outtab[1000009];

bool produktcmp(const raport& r1,const raport &r2){
    return r1.produkt<r2.produkt;
}

bool idcmp(const raport& r1, const raport& r2){
    return r1.numer<r2.numer;
}

int main(){
    scanf("%d", &n);
    
    for(int i=0; i<n; ++i){
        scanf("%d%d", &tab[i].produkt, &tab[i].ilosc);
        tab[i].numer = i;
    }
    
    //Posortowanie wg. produktow
    sort(tab, tab+n, produktcmp);
    
    //Zabezpieczenie sortowania po id
    for(int i=0; i<=n; ++i)outtab[i].numer=n+5;
    
    //Zliczenie produktow
    int outitr = 0, lastprod = tab[0].produkt;
    for(int i=0; i<n; ++i){
        if(lastprod != tab[i].produkt)++outitr, lastprod = tab[i].produkt;
        
        outtab[outitr].produkt=lastprod;
        outtab[outitr].numer=min(outtab[outitr].numer, tab[i].numer);
        outtab[outitr].ilosc+=tab[i].ilosc;
    }
    
    //Posortowanie wg. id
    sort(outtab, outtab+outitr+1, idcmp);
    
    //Wypisanie wynikow
    printf("%d\n", outitr+1);
    for(int i=0; i<=outitr; ++i)printf("%d %d\n", outtab[i].produkt, outtab[i].ilosc);
}
