#include<iostream>
using namespace std;

int male_litery[26], duze_litery[26];

void przypisz(char c){
    if(c>='A' && c<='Z')duze_litery[c-'A']++;
    if(c>='a' && c<='z')male_litery[c-'a']++;
}

int main(){
    ios_base::sync_with_stdio(0);
    
    int wiersze;
    cin>>wiersze;
    cin.ignore(10,'\n');//bugfix
    
    char linia[210];
    
    while(wiersze--){
        cin.getline(linia, 210);
        for(int i=0; linia[i]; ++i)przypisz(linia[i]);
    }
    //Wyniki
    for(int i=0; i<26; ++i)
        if(male_litery[i])cout<<char('a'+i)<<" "<<male_litery[i]<<"\n";
    for(int i=0; i<26; ++i)
        if(duze_litery[i])cout<<char('A'+i)<<" "<<duze_litery[i]<<"\n";
}
