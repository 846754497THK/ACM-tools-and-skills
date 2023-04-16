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
	void operator=(Point p){
		x=p.x;
		y=p.y;
	}
	double DotPro(Point p){
		return add(x*p.x,y*p.y);
	}
	double CrossPro(Point p){
		return add(x*p.y,-y*p.x);
	} 
	void PrintPoint(){
		printf("(%.3lf,%.3lf)",x,y);
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
double dis_lp(Point p1,Point p2,Point p){										//��p��ֱ��p1p2��������� 
	if(fabs(mag(p1-p2))<=100){													//������ӷ�ĸ����߾��� 
		p2=p2*10000-p1*9999;													//Ҫ�����г����ɾ�˿���doge 
	}
	return (p2-p1).CrossPro(p-p1)/(mag(p2-p1)); 
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
	Circle(Point P,double r):center(P),R(r){}									//Բ��+�뾶 
	Circle(double x,double y,double r):R(r){									//Բ�ģ�ֱ�����룩+�뾶 
		center.x=x;
		center.y=y;
	}
	Circle(Point p1,Point p2,Point p3){											//����ʽ��Ҫ�󲻹��ߣ� 
		double aa1,aa2,bb1,bb2,cc1,cc2,temp,x,y;								//������ ll_para �ж� 
		aa1=p1.x-p2.x; 
		bb1=p1.y-p2.y;
		cc1=(pow(p1.x,2)-pow(p2.x,2)+pow(p1.y,2)-pow(p2.y,2))/2;
		aa2=p3.x-p2.x;
		bb2=p3.y-p2.y;
		cc2=(pow(p3.x,2)-pow(p2.x,2)+pow(p3.y,2)-pow(p2.y,2))/2;
		temp=aa1*bb2-aa2*bb1;
		if(temp==0){
    		x=p1.x;
    		y=p1.y;
		}else{
			x=(cc1*bb2-cc2*bb1)/temp;
			y=(aa1*cc2-aa2*cc1)/temp;
		}
		center.x=x;
		center.y=y;
		R=mag(center,p1);
	}
	
	bool On_cir(Point p){														//��Բ�� 
		if(abs(mag(p,center)-R)<=eps)return 1;
		return 0;
	}
	bool In_cir(Point p){														//��Բ�ڣ�����boundry�� 
		if(mag(p,center)-R<=eps)return 1;
		return 0;
	}
	double area(){																//Բ��� 
		return PI*R*R;
	}
};
void build_cir_1(Point p1,Point p2,double R,Circle *C1,Circle *C2){				//����뾶��Բ,������C1,C2 
	C1->R=R;	C2->R=R;														//�����ʽ(p1,p2,r,&c1,&c2) 
    double c1=(p2.x*p2.x - p1.x*p1.x + p2.y*p2.y - p1.y*p1.y) / (2 *(p2.x - p1.x));  
    double c2=(p2.y - p1.y) / (p2.x - p1.x);
    double A=(c2*c2 + 1);  
    double B=(2 * p1.x*c2 - 2 * c1*c2 - 2 * p1.y);  
    double C=p1.x*p1.x - 2 * p1.x*c1 + c1*c1 + p1.y*p1.y - R*R;  
    C1->center.y=(-B+sqrt(B*B - 4 * A*C)) / (2 * A);
    C1->center.x=c1-c2*C1->center.y;
    C2->center.y=(-B-sqrt(B*B-4*A*C))/(2*A);
    C2->center.x=c1-c2 *C2->center.y;											//ע��C1=C2����� 
}
void cl_intersect(Circle C,Point p1,Point p2,Point *I1,Point *I2){				//ֱ�߽�Բ(ǰ�᣺�ཻ)��I1 & I2 ���潻�� 
	double temp1=sqrt( C.R*C.R-fabs(dis_lp(p1,p2,C.center))*fabs(dis_lp(p1,p2,C.center)) );
	Point e1( (p2-p1).x/mag(p2-p1) , (p2-p1).y/mag(p2-p1) );
	Point Base( e1.x*temp1 , e1.y*temp1 );
	double temp2=(p2-p1).DotPro(C.center-p1) / mag(p2-p1);
	Point e2( (p2-p1).x/mag(p2-p1) , (p2-p1).y/mag(p2-p1) );
	Point APR( e2.x*temp2 , e2.y*temp2 );
	Point pr( add(p1.x,APR.x) , add(p1.y,APR.y) );
	*I1=Point( add(Base.x,pr.x) , add(Base.y,pr.y)  );
	*I2=Point( add(pr.x,-Base.x), add(pr.y,-Base.y) );
	return;
}

