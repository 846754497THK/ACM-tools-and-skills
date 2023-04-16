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
bool on_seg(Point p,Point q,Point r){											//�ж�r�Ƿ����߶� pq �� 
	if(((p-r).CrossPro(q-r))==0 && (p-r).DotPro(q-r)<=0)						//�����˵� 
	return 1;
	return 0;
}
Point ll_intersect(Point p1,Point p2,Point q1,Point q2){						//�ж�ֱ�� p1p2 & q1q2 �Ľ��㣨��һ�������߶��ϣ� 
	return p1+(p2-p1)*( (q2-q1).CrossPro(q1-p1)/(q2-q1).CrossPro(p2-p1));		//Ҫ�� p1p2 & q1q2 ���ཻ  
}
bool ll_para(Point p1,Point p2,Point q1,Point q2){								//�ж�ֱ�� p1p2 & q1q2 �Ƿ�ƽ�� 
	if( (p2-p1).CrossPro(q2-q1)==0 )return 1;									//
	else return 0;
}
double area_triangle(Point a,Point b,Point c){									//�����ε�������� 
	return (b-a).CrossPro(c-a)/2;
}
double mag(Point a,Point b=Point()){											//������������ģ�� 
	Point t=a-b;
	return sqrt(t.x*t.x + t.y*t.y);
}
struct Point_polar{																//�����꣬loc�������꣬reloc��� 
	Point loc;										
	Point reloc;
	double ang,r;																//ang����x+�ļнǣ��û��ȱ��� 
};																				//ang=atan2(y,x) 
bool cmp(Point_polar a,Point_polar b){											//���ǱȽ��� 
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
