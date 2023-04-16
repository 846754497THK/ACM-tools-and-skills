#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a<b;
}
int n,m,a[2009],b[2000];
int BS(int k){
	int left=0,right=n,mid;
	while(left<=right){
		mid=(left+right)/2;
		if(k==a[mid])return 1;
		if(k>a[mid])left=mid+1;
		if(k<a[mid])right=mid-1;
	}
	return 0;
}
int main(){
	freopen("input1.txt","r",stdin);
	freopen("output1.txt","w",stdout);
	int s=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",&a[i]);
	scanf("%d",&m);
	for(int i=0;i<m;i++)scanf("%d",&b[i]);
	sort(a,a+n,cmp);
	for(int i=0;i<m;i++){
		if(BS(b[i])==1)s++;
	}
	cout<<s<<endl;
	return 0;
}
