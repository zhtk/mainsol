#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class s:public string{
    public:
    string str;

    bool operator<(const s &s2){
        if(str.size() > s2.str.size()) return false;
        if(str.size() < s2.str.size()) return true;

        return str<s2.str;
    }
};

int main(){
    vector<s> v;
    long long int n;
    cin>>n;
    while(n){
        s st;
        cin>>st.str;
        v.push_back(st);
        --n;
    }

    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());

    while(v.size()){
        cout<<v.back().str<<endl;
        v.pop_back();
    }
    return 0;
}
