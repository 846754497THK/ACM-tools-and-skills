#include<bits/stdc++.h>
using namespace std;
int main(){
	int c=1;
	double b=1;
	while(b>0.5){
		b*=double(365-c)/365;
		c++;
	}
	printf("%d\n",c);
	return 0;
}
