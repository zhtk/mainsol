// http://main.edu.pl/pl/user.phtml?op=showtask&task=i&con=PA2002
#include<cstdio>
#include<string>
using namespace std;

bool isZero(string& s)
{
	if(s.size()==0)
		return true;
		
	return (s.size()==1) && (s[0]=='0');
}

void shr(string& s)
{
	int p=0;
	for(int i=0; i<s.size(); ++i){
		p += s[i]-'0';
		s[i] = (p/2)+'0';
		p%=2;
		p*=10;
	}
	
	// Usuwamy zero wiodace
	if((!isZero(s)) && (s[0]=='0'))
		s.erase(0,1);
}

int main()
{
	int n,k;
	scanf("%d%d", &k, &n);
	
	string num="0";
	char tmp[500];
	
	while(n--){
		scanf("%s", tmp);
		string s = tmp;
		
		if(s.size()>num.size())
			num=s;
		else if(s.size() == num.size() && s>num)
			num = s;
	}
	
	while(!isZero(num)){
		--k;
		shr(num);
	}
	
	printf("%d\n", k);
}
