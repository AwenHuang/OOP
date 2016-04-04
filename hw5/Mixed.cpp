#include <iostream>
#include "Mixed.h"
using namespace std;
int sim(int,int);

Mixed::Mixed(int x,int y,int z){
		a = x;
		b = y;
		c = z;
		com = 0;
}
Mixed::Mixed(int x){
		a = x;
		b = 0;
		c = 1;
		com = 0;
}
const int Mixed::get_x()const{
		return a;
}
const int Mixed::get_y()const{
		return b;
}
const int Mixed::get_z()const{
		return c;
}
const int Mixed::get_com()const{
		return com;
}
bool Mixed::operator >(Mixed &p){
		p.ToFraction();
		int y = p.get_y(), z = p.get_z();
		return ((((b*z) > (y*c)))?1:0);
}
bool Mixed::operator <(Mixed &p){
		p.ToFraction();
		int y = p.get_y(), z = p.get_z();
		return ((((b*z) < (y*c)))?1:0);
}
bool Mixed::operator >=(Mixed &p){
		p.ToFraction();
		int y = p.get_y(),z = p.get_z();
		return ((((b*z) >= (y*c)))?1:0);
}
bool Mixed::operator <=(Mixed &p){
		p.ToFraction();
		int y = p.get_y(), z = p.get_z();
		return ((((b*z) <= (y*c)))?1:0);
}
bool Mixed::operator ==(Mixed &p){
		p.ToFraction();
		int y = p.get_y(), z = p.get_z();
		return ((((b*z) == (y*c)))?1:0);
}
bool Mixed::operator !=(Mixed &p){
		p.ToFraction();
		int y = p.get_y(), z = p.get_z();
		return ((((b*z) != (y*c)))?1:0);
}
Mixed Mixed::operator +(Mixed &p){
		p.ToFraction();
		Mixed tmp(0, (b*p.c) + (p.b*c),c*p.c);
		tmp.Simplify();
		return tmp;
}
Mixed Mixed::operator -(Mixed &p){
		p.ToFraction();
		Mixed tmp(0, (b*p.c) - (p.b*c),c*p.c);
		tmp.Simplify();
}
Mixed Mixed::operator *(Mixed &p){
		p.ToFraction();
		Mixed tmp(0, b*p.c,c*p.c);
		tmp.Simplify();
		return tmp;
}
Mixed Mixed::operator /(Mixed &p){
		p.ToFraction();
		Mixed tmp(0, b*p.c,c*p.b);
		tmp.Simplify();
		return tmp;
}
Mixed Mixed::operator ++(int){
		(*this).ToFraction();
		Mixed tmp(0,b,c);
		b = b + c;
		(*this).Simplify();
		tmp.Simplify();
		return tmp;
}
Mixed Mixed::operator --(int){
		(*this).ToFraction();
		Mixed tmp(0,b,c);
		b = b - c;
		(*this).Simplify();
		return tmp;
}
Mixed& Mixed::operator ++(){
		(*this).ToFraction();
		b = b + c;
		(*this).Simplify();
		return *this;
}
Mixed& Mixed::operator --(){
		(*this).ToFraction();
		b = b - c;
		(*this).Simplify();
		return *this;
}
double Mixed::Evaluate(){
		if(a == 0&&b == 0&&c == 0)
				return 0;
		else if(a >= 0)
				return (a*c + b)/(double)c;
		else if(a < 0)
				return (-1*a*c + b)*(-1)/(double)c;
}
void Mixed::Simplify(){
		com = 1;
		if(c == 0 || b == 0)
				return;
	int d = sim(b,c);
	b = b/d;
	c = c/d;
}
void Mixed::ToFraction(){
		com = 2;
		if(c == 0)
				return;
		if(a >= 0){
				b = b + a*c;
				a = 0;
				int d = sim(b,c);
				b = b/d;
				c = c/d;
		}
		else if(a < 0){
				b = (-1)*(a*(-1)*c + b);
				a = 0;
				int d = sim(b,c);
				b = b/d;
				c = c/d;
		}
}
istream &operator >>(istream &is, Mixed &l){
		char c[15] = {'\0'};
		int x,y,z;
		int i;
		char *ptr = c;
		cin.getline(c ,15);
		while((*ptr)!= '/' && (ptr)!='\0'){
				ptr++;
		}
		(*ptr) = ' ';
		if(sscanf(c,"%d%d%d",&x,&y,&z) == 3){
				if(((x!=0) && (y<0||z<0))||(z == 0))
						l = Mixed(0);
				else if(x == 0 && y<0 && z<0)
						l = Mixed(0);
				else
						l = Mixed(x,y,z);
		}
		else if(sscanf(c,"%d",&x) == 1)
				l = Mixed(x);
		return is;
}
		

ostream &operator <<(ostream &os,const Mixed &l){
		if(l.get_x() == 0 && l.get_y() == 0 && l.get_z() == 1)
				os << '0' << endl;
		else if(l.get_com() == 0){
				int a = l.get_x(),b = l.get_y(),c = l.get_z();
				os << a << ' ' << b << '/' << c << endl;
		}
		else if(l.get_com() == 1){
				int a = l.get_x(),b = l.get_y(),c = l.get_z();
				if((b < c)&&(b*-1) < c){
						if(b != 0){
								if(a == 0)
										os << b << '/' << c << endl;
								
								else
										os << a << ' ' << b << '/' << c << endl;
						}
				}
				else if((b >= c)||((b*(-1)) >= c)){
						if(a == 0){
								if(c == 1)
										os << b/c << endl;
								else if(b < 0)
										os << b/c << ' ' << (b-c*(b/c))*(-1) << '/' << c << endl;
								else if(b > 0)
										os << b/c << ' ' << (b-c*(b/c)) << '/' << c << endl;
						}
						else{
								if(a > 0){
										if(c == 1)
												os << a+(b/c) << endl;
										else
												os << a+(b/c) << ' ' << (b-c*(b/c)) << '/' << c << endl;
								}
								else if(a < 0){
										if(c == 1)
												os << ((a*-1) + (b/c))*(-1) << endl;
										else 
												os << (a*(-1) + (b/c))*(-1) << ' ' << (b-c*(b/c)) << '/' << c << endl;
								}
						}
				}
		}
		else if(l.get_com() == 2){
				int b = l.get_y(),c = l.get_z();
				os << b << '/' << c << endl;
		}
		return os;
}
int sim(int a,int b){
		if(b < 0)
				b = b*-1;
		if(!b)
				return(a);
		return sim(b,a%b);
}
