#include <iostream>
#include <cmath>
#include "hw3.h"
using namespace std;
bool isfinite(double arg);

Line::Line(){
		x0=0.0,y0=0.0,x1=1.0,y1=0.0;
}
Line::Line(double a,double b,double c,double d){
		x0=a, y0=b, x1=c, y1=d;
}
const double Line::get_x0(void) const{
		return x0;
}
const double Line::get_x1(void) const{
		return x1;
}
const double Line::get_y0(void) const{
		return y0;
}
const double Line::get_y1(void) const{
		return y1;
}
double Line::slope(){
		if((x1-x0) == 0)
				cout << "x = " << x0 << endl;
		else if((y1-y0) == 0)
				cout << "y = " << y0 << endl;
		return (y1-y0)/(x1-x0);
}
double Line::y_intercept(){
		double inter;
		inter = y0 - (((y1-y0)/(x1-x0))*x0);
		if(inter < 0)
				inter*(-1);
		if(isinf((y1-y0)/(x1-x0)) == true)
				return -1;

		return inter;
}
void Line::vshift(double move){
		y0 = y0 + move;
		y1 = y1 + move;
}
std::istream &operator>>(std::istream &is,Line &l){
		double a,b,c,d;
		is >> a >> b >> c >> d;
		l = Line(a,b,c,d);
		return is;
}
std::ostream &operator<<(std::ostream &os,const Line &l){
		os << "(" << l.get_x0() << "," << l.get_y0() << ")";
		os << "(" << l.get_x1() << "," << l.get_y1() << ")";
		return os;
}
/*	Line2	*/
Line2::Line2(){
		x=0.0,y=1.0,dx=1.0,dy=1.0;
}
Line2::Line2(double a,double b,double c,double d){
		x=a, y=b, dx=c, dy=d;
}
std::istream &operator >>(std::istream &is,Line2 &l2){
		double a,b,c,d;
		is >> a >> b >> c >> d;
		l2 = Line2(a,b,c,d);
		return is;
}
std::ostream &operator <<(std::ostream &os,const Line2 &l2){
		os << "(" << l2.x << "," << l2.y << ")";
		os << "(" << l2.dx << "," << l2.dy << ")";
		return os;
}
void Line2::printline2(){
		double m,b;
		m = dy/dx;
		b = y - m*x;
		if(isinf(m) == true)
				cout << "x = " << x << endl;
		else if(m == 0)
				cout << "y = " << y << endl;
		else if(isinf(m) == false && b!=0)
				cout << "y = " << m << "x + " << b << endl;
		else if(b == 0)
				cout << "y = " << m << "x" << endl;
}
void Line2::normal(){
		double m,b;
		m = (dx/dy)*(-1); // 法線斜率和切線斜率(dy/dx)垂直
		b = y - m*x;
		if(isinf(m) == true) // normal line 為x軸垂直線
				cout << "x = " << x << endl << endl;
		else if(m == 0)
				cout << "y = " << y << endl << endl;
		else if(isinf(m) == false)
				cout << "y = " << m << "x + " << b << endl << endl;
		else if(b == 0)
				cout << "y = " << m << "x" << endl << endl;
}

/*	Circle	*/

Circle::Circle(){
		cx=0.0, cy=0.0, r=1.0;
}
Circle::Circle(double a,double b,double c){
		cx=a, cy=b, r=c;
}
std::istream &operator >>(std::istream &is,Circle &C){
		double a,b,c;
		is >> a >> b >> c;
		C = Circle(a,b,c);
		return is;
}
std::ostream &operator <<(std::ostream &os,const Circle &C){

		if(C.cx > 0)
				os << "(x - " << C.cx << ")^2";
		else if(C.cx < 0)
				os << "(x + " << C.cx*(-1) << ")^2";
		else if(C.cx == 0)
				os << "x^2";
		if(C.cy > 0)
				os << " + (y - " << C.cy << ")^2";
		else if(C.cy < 0)
				os << " + (y + " << C.cy*(-1) << ")^2";
		else if(C.cy == 0)
				os << " + y^2";

		os << " = " << pow(C.r,2) << endl;
		return os;
}
const double Circle::radius() const{
		return r;
}
void Circle::set_center(double x,double y){
		cx = x;
		cy = y;
}
void Circle::is_inside(double x,double y) const{
		double ds;
		ds = sqrt(pow((x-cx),2)+pow((y-cy),2)); // 點和圓心的距離
		if(ds > r) // 距離>半徑 在圓外
				cout << "no" << endl << endl;
		else if(ds <= r) // 距離<=半徑 在圓內或圓上
				cout << "yes" << endl << endl;
}

/*	Circle2	*/

Circle2::Circle2(){
		x0=0.0, y0=0.0, x1=1.0, y1=1.0;
}
Circle2::Circle2(double a,double b,double c,double d){
		x0=a, y0=b, x1=c, y1=d;
}
std::istream &operator >>(std::istream &is,Circle2 &C2){
		double a,b,c,d;
		is >> a >> b >> c >> d;
		C2 = Circle2(a,b,c,d);
		return is;
}
std::ostream &operator <<(std::ostream &os,const Circle2 &C2){
		double c_x,c_y,R;
		// 將圓上兩點取中點即為圓心
		c_x = (C2.x0 + C2.x1)/2;
		c_y = (C2.y0 + C2.y1)/2;

		R = sqrt(pow((C2.x1-c_x),2)+pow((C2.y1-c_y),2));
		if(c_x > 0)
				os << "(x - " << c_x << ")^2";
		else if(c_x < 0)
				os << "(x + " << c_x*(-1) << ")^2";
		else if(c_x == 0)
				os << "x^2";
		if(c_y > 0)
				os << " + (y - " << c_y << ")^2";
		else if(c_y < 0)
				os << " + (y + " << c_y*(-1) << ")^2";
		else if(c_y == 0)
				os << " + y^2";

		os << " = " << pow(R,2) << endl;
}
void Circle2::is_inside(double x,double y) const{
		double c_x,c_y,ds,R;
		// 將圓上兩點取中點即為圓心
		c_x = (x0 + x1)/2;
		c_y = (y0 + y1)/2;
		R = sqrt(pow((x1-x0),2)+pow((y1-y0),2));
		ds = sqrt(pow((x-c_x),2)+pow((y-c_y),2)); // 點和圓心的距離
		if(ds > R) // 距離>半徑 在圓外
				cout << "no" << endl << endl;
		else if(ds <= R) // 距離<=半徑 在圓內或圓上
				cout << "yes" << endl << endl;
}




