#include <iostream>
using namespace std;

int main(){
    long long int k, w, m;
    cin>>k>>w>>m;

    w-=k;
    if(w%m){
        w-=w%m;
        w+=m;
    }
    w/=m;

    cout<<w<<endl;
    return 0;
}
