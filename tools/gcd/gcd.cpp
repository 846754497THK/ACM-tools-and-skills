#include <iostream>
using namespace std;
int gcd(int m,int n){
	int temp;
	while(n!=0){m=m%n;temp=n;n=m;m=temp;}
	return m;
}
int main(){
	int  m,n;
	cin>>m>>n;
	cout<<gcd(m,n)<<endl;
	return 0;
}
