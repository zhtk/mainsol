#include <iostream>
using namespace std;

int main(){
    long long int n, tmp;
    cin>>n;
    for(tmp=1;n%tmp==0;++tmp);
    cout<<tmp<<" ";
    for(tmp=n;n%tmp==0;--tmp);
    cout<<tmp<<"\n";
    return 0;
}
