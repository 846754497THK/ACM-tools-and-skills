#include<bits/stdc++.h>
using namespace std;
queue <pair <string,int> > s;
int main(){
	pair<string,int> a,b;
	int n;
	a.first="thk";
	a.second=1902;
	s.push(a); 
	a.first="ttk";
	s.push(a);
	b=s.front();	cout<<b.first<<endl;
	n=s.size();		cout<<n<<endl;
	s.pop();
	s.pop();
	if(s.empty())cout<<"9s\n";
	return 0;
}
