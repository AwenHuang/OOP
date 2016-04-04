#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#define PI 3.1415926535897931
using namespace std;

class Point{
		public:
		 	double x;
		 	double y;
			Point():x(0),y(0) {};
			Point(double ix, double iy):x(ix),y(iy){};
			Point(const Point &p):x(p.x), y(p.y){};
			bool operator == (const Point &p) const{
					return (x == p.x) && (y == p.y);
			}
			bool operator != (const Point &p) const{
					return !(*this == p);
			}
			Point & operator = (const Point &a);
};
class Line{
		public:
			double a;
			double b;
			double c;
			Line() : a(0), b(0), c(0) {};
			Line(double ia, double ib, double ic): a(ia), b(ib), c(ic) {};
			Line(const Line & p) : a(p.a), b(p.b), c(p.c) {};
			bool operator == (const Line & p){
					return(a == p.a) && (b == p.b) && (c == p.c);
			}
};
class Convexhull{
		private:
			Line FindLine(const Point &p, const Point &q);
			bool isOnRight(const Point &p, const Point &q, const Point &r);
			Point FindLowestPoint(const vector<Point> &input);
			double ComputeAngle(const Point &p, const Point &q, const Point &r);
		public:
			void FindConvexHull_bf(const vector<Point> &input, vector<Point>& output);
			void FindConvexHull_jm(const vector<Point> &input, vector<Point>& output);
			vector<Point> FindInternalPoint(const vector<Point> &input, vector<Point>& result);
};

bool compare(const Point a, const Point b);
bool up_compare(const Point &a, const Point &b);
bool low_compare(const Point &a, const Point &b);
bool inter_compare(const Point &a, const Point &b);
Point FindStartPoint(vector<Point> &point);


