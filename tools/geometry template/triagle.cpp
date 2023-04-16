#include<bits/stdc++.h>
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
bool on_seg(Point p,Point q,Point r){											//判断r是否在线段 pq 上 
	if(((p-r).CrossPro(q-r))==0 && (p-r).DotPro(q-r)<=0)						//包括端点 
	return 1;
	return 0;
}
Point ll_intersect(Point p1,Point p2,Point q1,Point q2){						//判断直线 p1p2 & q1q2 的交点（不一定在其线段上） 
	return p1+(p2-p1)*( (q2-q1).CrossPro(q1-p1)/(q2-q1).CrossPro(p2-p1));		//要求 p1p2 & q1q2 不相交  
}
bool ll_para(Point p1,Point p2,Point q1,Point q2){								//判断直线 p1p2 & q1q2 是否平行 
	if( (p2-p1).CrossPro(q2-q1)==0 )return 1;									//
	else return 0;
}
double area_triangle(Point a,Point b,Point c){
	return (b-a).CrossPro(c-a)/2;
}
int main(){
	Point a,b,c;
	cin>>a.x>>a.y>>b.x>>b.y>>c.x>>c.y;
	printf("%.2f\n",area_triangle(a,b,c));
	return 0;
}
