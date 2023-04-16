#include<bits/stdc++.h>
using namespace std;
const double ESP=1e-10;
double add(double a,double b){						
	if( abs(a+b)<ESP*(abs(a)+abs(b)) )return 0;
	return a+b;
}
double minus(double a,double b){							//
	if( abs(a)-abs(b)<ESP )return 0;
	return a-b;
}
struct point{
	double x,y;
	point(){}
	point(double xx,double yy):x(xx),y(yy){}
	point operator + (point p){
		return point( add(x,p.x),add(y,p.y) );
	}
	point operator - (point p){								//可表示从p到p0 
		return point( add(x,-p.x),add(y,-p.y) );
	}
	point operator * (double d){
		return point( x*d,y*d );
	}
	double dotpro(point p){									//dot product
		return add( x*p.x,y*p.y );
	}
	double crosspro(point p){								//mag of the cross product bw q,q0
		return add( x*p.y,-y*p.x );
	}
	double mag(){
		if( abs(x)+abs(y)<ESP )return 0;
		return sqrt(x*x+y*y);
	}
};


