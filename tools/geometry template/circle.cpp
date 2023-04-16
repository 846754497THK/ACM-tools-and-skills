#include<bits/stdc++.h>
using namespace std;
const double eps=1e-10;
const double PI=3.1415926535898;
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
double area_triangle(Point a,Point b,Point c){									//三角形的有向面积 
	return (b-a).CrossPro(c-a)/2;
}
double mag(Point a,Point b=Point()){											//两点距离或向量模长 
	Point t=a-b;
	return sqrt(t.x*t.x + t.y*t.y);
}
struct Point_polar{																//极坐标，loc绝对坐标，reloc相对 
	Point loc;										
	Point reloc;
	double ang,r;																//ang是与x+的夹角，用弧度保存 
};																				//ang=atan2(y,x) 
bool cmp(Point_polar a,Point_polar b){											//极角比较器 
	return a.ang<b.ang;
}
struct Circle{
	Point center;
	double R;
	Circle(){}
	Circle(Point P,double r):center(P),R(r){}
	Circle(double x,double y,double r):R(r){
		center.x=x;
		center.y=y;
	}
	double area(){
		return PI*R*R;
	}
};
int main(){
	double a,b,r;
	while(1){
		scanf("%lf%lf%lf",&a,&b,&r);
		Circle c(a,b,r);
		printf("%.4lf\n",c.area());
	}
	return 0;
}
