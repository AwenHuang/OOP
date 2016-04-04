#include <iostream>
using namespace std;

class Line{
		private:
        		double x0,y0,x1,y1;
    	public:
        		Line(); // constructor
        		Line(double,double,double,double);
        		const double get_x0(void) const;
        		const double get_x1(void) const;
        		const double get_y0(void) const;
        		const double get_y1(void) const;
        		double slope();
        		void vshift(double);
        		double y_intercept();
        		friend std::istream &operator >>(std::istream &is,Line &l);
        		friend std::ostream &operator <<(std::ostream &os,const Line &l);
};
class Line2{
		private:
				double x,y,dx,dy;
		public:
				Line2();
				Line2(double,double,double,double);
				void normal();
				void printline2();
				friend std::istream &operator >>(std::istream &is,Line2 &l2);
				friend std::ostream &operator <<(std::ostream &os,const Line2 &l2);
};
class Circle{
		private:
				double cx,cy,r; // center of circle
		
		public:
				Circle();
				Circle(double,double,double);
				const double radius() const;
				void set_center(double,double);
				void is_inside(double,double) const;
				friend std::istream &operator >>(std::istream &is,Circle &C);
				friend std::ostream &operator <<(std::ostream &os,const Circle &C);
};
class Circle2{
		private:
				double x0,y0,x1,y1;
		public:
				Circle2();
				Circle2(double,double,double,double);
				void is_inside(double,double) const;
				friend std::istream &operator >>(std::istream &is,Circle2 &C2);
				friend std::ostream &operator <<(std::ostream &os,const Circle2 &C2);

};
