#include<algorithm>
#include<cmath>
#include<string>
#include<fstream>
#include<cstdlib>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
int main(){
	
	ifstream cin("input1.txt");
	ofstream cout("output1.txt");
	freopen("input1.txt","r",stdin);
	freopen("output1.txt","w",stdout);
    for(int i=0;i<100;i++)printf("%d ",rand());
}
