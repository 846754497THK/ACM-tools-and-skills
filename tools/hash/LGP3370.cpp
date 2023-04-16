#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const ull B=100000007;
struct hstr{
	char s[1600];
	int len;
	ull h;
}a[10050];
bool cmp(hstr x,hstr y){
	return x.len<y.len;
}
int main(){
	int T;	scanf("%d%*c",&T);
	for(int i=0;i<T;i++){
		scanf("%s",a[i].s);
		a[i].len=strlen(a[i].s);
		ull b=1;
		a[i].h=0;
		for(int j=a[i].len-1;j>=0;j--){
			a[i].h+=a[i].s[j]*b;
			b*=B;
		}
	}
	sort(a,a+T,cmp);
	int ans=0;
	for(int i=0;i<T;i++){
		bool add=1;
		for(int j=i+1;j<T;j++){
			if(a[j].len>a[i].len)break;
			if(a[j].h==a[i].h){
				add=0;
				break;
			}
		}
		if(add)ans++;
	}
	printf("%d\n",ans);
	return 0;
}
