#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<string>
#include<fstream>
#include<vector>
#include<set>
#include<map>
#include<cstdlib>
#include<cstring>
#include<stack>
#include<queue>
#include<bitset>
#include<utility>
#include<iomanip>
using namespace std;
const double eps=1e-10;
double add(double a,double b){
    if(abs(a+b)<eps*(abs(a)+abs(b)))  return 0;
    return a+b;
}
struct Point{
	double x,y;
	Point(){}
	Point(double x,double y):x(x),y(y){}
	Point operator+(Point p){
		return Point(add(x,p.x),add(y,p.y));
	}
	Point operator-(Point p){
		return Point(add(x,-p.x),add(y,-p.y));
	}
	Point operator*(double d){
		return(Point(d*x,d*y));
	}
	double DotPro(Point p){
		return add(x*p.x,y*p.y);
	}
	double CrossPro(Point p){
		return add(x*p.y,-y*p.x);
	} 
};
bool on_seg(Point p,Point q,Point r){
	if(((p-r).CrossPro(q-r))==0 && (p-r).DotPro(q-r)<=0)
	return 1;
	return 0;
}
Point ll_intersect(Point p1,Point p2,Point q1,Point q2){
	return p1+(p2-p1)*( (q2-q1).CrossPro(q1-p1)/(q2-q1).CrossPro(p2-p1));
}
bool ll_para(Point p1,Point p2,Point q1,Point q2){
	if( (p2-p1).CrossPro(q2-q1)==0 )return 1;
	else return 0;
}
const int maxN=15,maxM=10010;
int n,m;
Point p[maxN],q[maxN];
bool g[maxN][maxN]; 
int A[maxM],B[maxM];
void solve(){
	memset(g,0,sizeof(g));
	for(int i=0;i<n;i++){
		g[i][i]=1;
		for(int j=0;j<i;j++){
			if( ll_para(p[i],q[i],p[j],q[j]) ){
				g[i][j]=g[j][i]=on_seg(p[i],q[i],p[j])
					||on_seg(p[i],q[i],q[j])
					||on_seg(p[j],q[j],p[i])
					||on_seg(p[j],q[j],q[i]);
			}else{
				Point tp=ll_intersect(p[i],q[i],p[j],q[j]);
				g[i][j]=g[j][i]=on_seg(p[i],q[i],tp)&&on_seg(p[j],q[j],tp);
			}
		}
	}
	for(int k=0;k<n;k++)for(int i=0;i<n;i++)for(int j=0;j<n;j++)
		g[i][j] |= g[i][k]&&g[k][j];
}
void output(bool K=0){
	if(K)printf("CONNECTED\n");
	else printf("NOT CONNECTED\n");
}
int main(){
	int a,b;
	while(~scanf("%d",&n)&&n){
		for(int i=0;i<n;i++)
			scanf("%lf%lf%lf%lf",&p[i].x,&p[i].y,&q[i].x,&q[i].y);		
		solve();
		int tmp1,tmp2,count=0;
		while(~scanf("%d%d",&tmp1,&tmp2) && tmp1 && tmp2){
			A[count]=tmp1;	
			B[count]=tmp2;
			count++;
		}
		m=count;
		for(int i=0;i<m;i++){
			if(g[A[i]-1][B[i]-1])output(1);
			else output();
		}
	}
	return 0;
} 



