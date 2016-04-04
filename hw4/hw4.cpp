#include "hw4.h"


const long long int INFINITE = 1000000000;

Point & Point::operator = (const Point &a){
		if (this != &a){
				x = a.x;
				y = a.y;
		}
		return *this;
}
Line Convexhull::FindLine(const Point &p, const Point &q){
		Line k;
		if(p.x == q.x)
				k = Line(1, 0, -p.x);
		else if(p.y == q.y)
				k = Line(0, 1, -p.y);
		else{
				double a = -(p.y - q.y);
				double b = p.x - q.x;
				double c = -a*(p.x) - b*(p.y);
				k = Line(a, b, c);
		}
		return k;
}
bool Convexhull::isOnRight(const Point &p, const Point &q, const Point &r){
		Line l = FindLine(p,q);
		if(l.b == 0){
				if(r.x > -l.c)
						return true;
				else
						return false;
		}
		else if(l.a == 0){
				if(-l.c < r.y)
						return true;
				else
						return false;
		}
		else{
				if(l.a*r.x + l.b*r.y + l.c > 0)
						return true;
				else
						return false;
		}
}
void Convexhull::FindConvexHull_bf(const vector<Point> &input, vector<Point>& output){
		bool u[100] = {false};
		int i,j,k;
		for(i=0; i<input.size()-1; i++){
				for(j=i+1; j<input.size(); j++){
						bool fail = false;
						int side = 0;
						for(k = 0; k < input.size(); k++){
								if(k == i || k == j)
										continue;
								if(isOnRight(input[i], input[j], input[k])){
										if(side == -1){
												fail = true;
												break;
											}
											else
													side = 1;
								}
								if(!isOnRight(input[i], input[j], input[k])){
										if(side == 1){
												fail = true;
												break;
										}
										else
												side = -1;
								}
						}
						if(fail == false){
								if(u[i] == false)
										output.push_back(input[i]);
								if(u[j] == false)
										output.push_back(input[j]);
								u[i] = true;
								u[j] = true;
						}
				}
		}
}
void Convexhull::FindConvexHull_jm(const vector<Point> &input, vector<Point> &output){
		Point p,q,r,s;
		int i,max,n;
		double angle,maxangle = 0;
		max = 0;
		q = FindLowestPoint(input);
		s = q;
		p = Point(-INFINITE, q.y);
		n = input.size();
		for(i=0; i<n; i++){
				if(input[i] == q)
						continue;
				angle = ComputeAngle(p, q, input[i]);
				if(angle > maxangle){
						max = i;
						maxangle = angle;
				}
		}
		output.push_back(s);
		p = q;
		q = input[max];
		while(q != s){
				max = 0;
				maxangle = 0;
				output.push_back(q);
				for(i=0; i<n; i++){
						if(input[i] == p||input[i] == q)
								continue;
						angle = ComputeAngle(p,q,input[i]);
						if(angle > maxangle){
								max = i;
								maxangle = angle;
						}
				}
				p = q;
				q = input[max];
		}
}
Point Convexhull::FindLowestPoint(const vector<Point> &input){
		int i,n,lowest_index;
		n = input.size();
		lowest_index = 0;
		for(i=1; i<n; i++){
				if(input[i].y < input[lowest_index].y)
						lowest_index = i;
				else if(input[i].y == input[lowest_index].y)
						if(input[i].x < input[lowest_index].x)
								lowest_index = i;
		}
		return input[lowest_index];
}
double Convexhull::ComputeAngle(const Point& p, const Point &q, const Point &r){
		double dot,distant_a,distant_b,angle;
		dot = (p.x-q.x) * (r.x-q.x) + (p.y-q.y)*(r.y-q.y);
		distant_a = sqrt((p.x-q.x)*(p.x-q.x) + (p.y-q.y)*(p.y-q.y));
		distant_b = sqrt((r.x-q.x)*(r.x-q.x) + (r.y-q.y)*(r.y-q.y));
		angle = (acos(double(dot)/double(distant_a*distant_b)));
		return angle;
}
vector<Point> Convexhull::FindInternalPoint(const vector<Point> &input, vector<Point>& result){
		int i,j,r_size,i_size;
		r_size = result.size();
		i_size = input.size();
		vector<Point> internal;
		for(i=0; i<i_size; i++){
				bool find = false;
				for(j=0; j<r_size; j++){
						if(input[i] == result[j]){
								find = true;
								break;
						}
				}
				if(find == false)
						internal.push_back(input[i]);
		}
		return internal;
}
bool compare(const Point a, const Point b){
		if(a.x == b.x)
				return a.y < b.y;
		else
				return a.x > b.x;
}
bool up_compare(const Point &a, const Point &b){
		return a.x > b.x;
}
bool low_compare(const Point &a, const Point &b){
		return a.x < b.x;
}
bool inter_compare(const Point &a, const Point &b){
		if(a.x == b.x)
				return a.y > b.y;
		else 
				return a.x > b.x;
}
Point FindStartPoint(vector<Point> &point){
		int i,vsize;
		double rightest = -1000000000;
		vsize = point.size();
		Point ans;
		for(i=0; i<vsize; i++){
				if(point[i].x > rightest){
						ans = point[i];
						rightest = point[i].x;
				}
				else if(point[i].x == rightest)
						if(point[i].y < ans.y)
								ans = point[i];
		}
		return ans;
}




