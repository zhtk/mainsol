#include<cstdio>
#include<stack>
#include<algorithm>
using namespace std;

stack<char> nawiasy;
int maxz = 0;

int main(){
	int len;
	scanf("%d", &len);
	
	char str[len+5];
	scanf("%s", str);
	
	for(int i=0; i<len; ++i){
		if(str[i]=='(' || str[i]=='{' || str[i]=='[')nawiasy.push(str[i]);
		else if(nawiasy.size() == 0){printf("NIE\n"); return 0;}
		else if(str[i] == '}' && nawiasy.top() == '{')maxz = max(maxz, (int)nawiasy.size()), nawiasy.pop();
		else if(str[i] == ']' && nawiasy.top() == '[')maxz = max(maxz, (int)nawiasy.size()), nawiasy.pop();
		else if(str[i] == ')' && nawiasy.top() == '(')maxz = max(maxz, (int)nawiasy.size()), nawiasy.pop();
		else {
			printf("NIE\n");
			return 0;
		}
	}
	
	if(nawiasy.size() == 0)printf("%d\n", maxz);
	else printf("NIE\n");
	
	return 0;
}
