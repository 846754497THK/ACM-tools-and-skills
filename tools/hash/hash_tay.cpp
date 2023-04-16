#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const ull B=100000007;
char s[500];
int main(){
	cin>>s;
	int l=strlen(s);
	ull h=0,b=1;
	for(int i=l-1;i>=0;i--){
		h+=s[i]*b;
		b*=B;	
	}
	printf("%llu\n",h);
	return 0;
}
