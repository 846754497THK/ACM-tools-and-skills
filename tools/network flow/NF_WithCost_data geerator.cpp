// network flow with cost data generator
#include<bits/stdc++.h>
using namespace std;					
const int scale = 20;					// number of the node
const int Mlength = 100;					// the scale of the edge
const int Mprice = 50;					// the scale of the price of the edge
const int CONN = 99;						// 连通性：1 ~ 100（表达其边的密度） 
int n,m,p[scale+4][scale+4],e[scale+4][scale+4];
bool c[scale+4][scale+4];
int main(){
	freopen("network flow_input6.txt","w",stdout);
	memset(p,-1,sizeof(p));
	memset(c,0,sizeof(c));
	srand(int(time(0)));
	n=rand()%scale;
	if(n<=2)n=3;
	for(int i=0;i<n;i++){
		c[i][i]=1;	p[i][i]=0;			// node ic connected with itself
	} 
	m=floor( (double)( (n-1)*n/2 )*( (double)CONN/100 ) );

	int mid=rand()%(n-2);				// 生成首尾的连接 
	if(m<mid)m=mid;
	int rem=mid,midnode[scale]={},nownode=0,lastnode=0;
	bool ifmidpoint[scale];
	memset(ifmidpoint,0,sizeof(ifmidpoint));
	ifmidpoint[0]=1,ifmidpoint[n-1]=1;
	while(rem>0){
		while(ifmidpoint[nownode]==1 || nownode==lastnode){
			nownode=rand()%n;
		}
		c[lastnode][nownode]=1,c[nownode][lastnode]=1;
		p[lastnode][nownode]=rand()%Mlength + 1;
		e[lastnode][nownode]=rand()%Mprice;
		ifmidpoint[nownode]=1;
		rem--;
		lastnode=nownode;
	}
	c[lastnode][n-1]=1,c[n-1][lastnode]=1;
	p[lastnode][n-1]=rand()%Mlength + 1;
	e[lastnode][n-1]=rand()%Mprice;
	m++;
	
	rem=m-mid-1;
	while(rem>0){
		int head=1,tail=1;
		while(c[head][tail]==1 || tail==0 || head==n-1){
			head=rand()%n;
			tail=rand()%n;
		}
		c[head][tail]=1;
		c[tail][head]=1;
		p[head][tail]=rand()%Mlength + 1;
		e[head][tail]=rand()%Mprice;
		rem--;
	}
	printf("%d %d %d %d\n",n,m,1,n);	//number of the node,edge,origin,ulternation
	for(int i=0;i<n;i++)for(int j=0;j<n;j++)if( i!=j && c[i][j]==1 && p[i][j]!=-1)
		printf("%d %d %d %d\n",i+1,j+1,p[i][j],e[i][j]);
	return 0;
}

