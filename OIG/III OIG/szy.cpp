#include <stdio.h>
char s[2000000];
long long int n=1000000;
char c;

inline int zlicz(int n)
{
    long long int t[26];
    for(int i=0; i<26; ++i) t[i]=0;
    for(int i=0; i<n; ++i) ++t[ s[i]-int('A') ];

    int max= -1;
    int wynik=0;
    for(int i=0; i<26; ++i)
    {
        if(t[i]>max)
        {
            max=t[i];
            wynik=i;
        }
    }
    return wynik;
}

inline void deszyfruj(int n, int p)
{
    for(int i=0; i<n; ++i)
    {
        s[i]=(int)s[i]+p;

        if(int(s[i])>int('Z'))
        {
            s[i]=(int)s[i]-(int)'Z';
            s[i]=(int)s[i]+(int)'A';
            --s[i];
        }

        if(int(s[i])<(int)'A')
        {
            s[i]-=int('A');
            s[i]+=int('Z');
            ++s[i];
        }
    }
}

int main()
{
    scanf("%d %c",&n, &c);
    c=c-(int)'A';
    scanf("%s", &s);
    int p=zlicz(n);
    p=c-p;
    deszyfruj(n, p);
    printf("%s", s);
    return 0;
}
