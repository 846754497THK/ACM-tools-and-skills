#include<bits/stdc++.h>
using namespace std;
const int INF=100000000;			//检验生日攻击的密度概率 
typedef long long ll;
bool k[INF+5];
int main(){
	ll T,c,s;
	scanf("%d",&T);
	srand(int(time(0)));
	freopen("output1.txt","w",stdout);
	while(T--){
		int C=0;
		memset(k,0,sizeof(k));
		while(1){
			int a=rand()%30000,b=rand()%30000,c=rand()%30000;
			s=a*b+c;
			s%=INF;
			C++;
			if(k[s])break;
			k[s]=1;
		}
		printf("%d    ",C);
	}
	return 0;
}

