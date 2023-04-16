#include<bits/stdc++.h>
using namespace std;
stack<int> n;
int main(){
	freopen("input1.txt","r",stdin);
	freopen("output1.txt","w",stdout);
	char s[100];
	int a,b;
	for(;cin>>s;){
		if(s[0]=='+'){
			a=n.top();	n.pop();
			b=n.top();	n.pop();
			n.push(a+b);
		}
		else if(s[0]=='-'){
			a=n.top();	n.pop();
			b=n.top();	n.pop();
			n.push(a-b);			
		}
		else if(s[0]=='*'){
			a=n.top();	n.pop();
			b=n.top();	n.pop();
			n.push(a*b);			
		}
		else if(s[0]=='/'){
			a=n.top();	n.pop();
			b=n.top();	n.pop();
			n.push(a/b);			
		}
		else n.push(atoi(s));
	}
	a=n.top();
	n.pop();
	if(n.empty())printf("Legal\n");
	printf("%d\n",a);
	return 0;
} 
