#include<bits/stdc++.h>
using namespace std;
const double eps=1e-10;
double add(double a,double b){
    if(abs(a+b)<eps*(abs(a)+abs(b)))  return 0;
    return a+b;
}
struct Point{
	double x,y;
	Point():x(0),y(0){}
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
double area_triangle(Point a,Point b,Point c){		
	return (b-a).CrossPro(c-a)/2;
}
Point p[110];
int n;
double sum=0;
int main(){
	while(~scanf("%d",&n) && n){
		sum=0;
		for(int i=0;i<n;i++)scanf("%lf%lf",&p[i].x,&p[i].y);
		for(int i=1;i<n;i++)
			sum+=area_triangle(Point(),p[i],p[i-1]);
		sum+=area_triangle(Point(),p[0],p[n-1]);
		printf("%.1lf\n",abs(sum));
	}
	return 0;
}
