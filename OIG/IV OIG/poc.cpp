#include<stdio.h>
#include<stack>
using namespace std;

int aktmiasto=1, /*liczba*/okrazen=0, liczbamiast;
stack<int> pociag;
int surowce[1000009]; //Surowce (numer i), ktorych potrzebuja miasta o numerze surowce[i]

int main()
{
    //Wczytanie danych:
    scanf("%d", &liczbamiast);
    int tmp;

    for(int i=0; i<liczbamiast; ++i){
        scanf("%d", &tmp);
        pociag.push(tmp);
    }

    for(int i=0; i<liczbamiast; ++i){
        scanf("%d", &tmp);
        surowce[tmp]=i+1;
    }
    
    //Obliczenia:
    while(!pociag.empty()){
        if((aktmiasto==1 && surowce[pociag.top()]>1) || (surowce[pociag.top()]!=1 && (aktmiasto>surowce[pociag.top()])))++okrazen;
        aktmiasto=surowce[pociag.top()];
        pociag.pop();
    }
    
    //Wypisanie wyniku:
    printf("%d\n", okrazen);
    return 0;
}
