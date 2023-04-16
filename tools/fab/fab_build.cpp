#include<iostream>
#include<fstream>
using namespace std;
long scale_i=90;	//max=91
long long scale_n=8000000000000000000; 	//max=8000000000000000000
long long a[1000]={1,1,2};
long i=3;
int main(){
	ifstream cin("input1.txt");
	ofstream cout("output1.txt");
	freopen("input1.txt","r",stdin);
	freopen("output1.txt","w",stdout);
	for(;i<scale_i && a[i]<scale_n;i++)a[i]=a[i-1]+a[i-2];
	for(i=0;i<scale_i;i++)cout<<a[i]<<" ";
	return 0;
}
