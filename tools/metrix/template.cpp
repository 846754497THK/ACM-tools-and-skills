#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxR=10,maxC=10;
template<class TT>
TT ABS(TT x){
	return (x>0)?x:-x;
}
struct Metrix{
	int R,C;
	Metrix *Up_Triangle;
	double a[maxR][maxC];
	Metrix(){}
	void Init(){
		R=C=0;
		memset(a,0,sizeof(a));
	}
	void Make_Up_Triangle(){
		Up_Triangle->C=C;
		Up_Triangle->R=R;
		for(int i=0;i<R;i++)for(int j=0;j<C;j++)
			Up_Triangle->a[i][j]=a[i][j];
	}
	void Output(){
		printf("R=%d  C=%d  \n",R,C);
		for(int i=0;i<R;i++){
			for(int j=0;j<C;j++)printf("%d\t",a[i][j]);
			printf("\n");
		}
	}
	
	
	double Determinant(){
		if(R!=C){
			printf("Not a Square matrix\n");
			return 0;
		}
		vector<int>order;
		order.clear();
		
	}
}A;

int main(){
//	freopen("input1.txt","r",stdin);
//	freopen("output1.txt","w",stdout);
	int r,c;
	A.Init();
	double tmp;
	scanf("%d%d",&A.R,&A.C);
	for(int i=0;i<A.R;i++){
		for(int j=0;j<A.C;j++){
			scanf("%ld",&A.a[i][j]);
		}
	}
	
	A.Make_Up_Triangle();
	Metrix *B=A.Up_Triangle();
	return 0;
}
