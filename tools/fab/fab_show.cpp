#include<iostream>
#include<fstream>
#include<algorithm>
#include<cmath>
#include<iomanip>
using namespace std;
long scale_i=90;	//max=91
long long scale_n=8000000000000000000; 	//max=8000000000000000000
long long a[1000]={1,1,2};
long i=3,j;
int main(){
	ifstream cin("input1.txt");
	ofstream cout("output1.txt");
	freopen("input1.txt","r",stdin);
	freopen("output1.txt","w",stdout);
	for(;i<scale_i && a[i]<scale_n;i++)a[i]=a[i-1]+a[i-2];	
	for(j=1;j<10;j++)cout<<setw(2)<<j<<" "<<setw(25)<<a[j-1]<<" \n";
	for(j=1;j<10;j++)cout<<setw(2)<<j*10<<" "<<setw(25)<<a[j*10-1]<<" \n";
	return 0;
}
