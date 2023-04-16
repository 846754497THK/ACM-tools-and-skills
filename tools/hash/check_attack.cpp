#include<bits/stdc++.h>
using namespace std;
const int INF=100000000;
double a,ave;
int main(){
	int c=0;
	freopen("check.txt","r",stdin);
	freopen("result.txt","w",stdout);
	while(~scanf("%lf",&a)){
		ave+=a;
		c++;
	}
	ave/=c;
	printf("%.04lf\n",ave/sqrt(INF));
	return 0;
}
