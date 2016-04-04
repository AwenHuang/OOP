#include "hw4.h"
#include <sys/time.h>
#include <fstream>

bool up_compare(const Point &a, const Point &b);
bool low_compare(const Point &a, const Point &b);
Point FindStartPoint(vector<Point> &point);

int main(){
		Convexhull h;
		vector<Point> point;
		vector<Point> result;
		vector<Point> internal;

		while(1){
				int i,option,n;
				cout << "Please choose method: (1)brute force (2)Jarvis's march (3)exit" <<endl;
				cin >> option;
				
				ifstream finput("Input.txt");
			
				internal.clear();
				point.clear();
				result.clear();
				
				finput >> n; // 讀了幾個字元
				for(i=0; i<n; i++){
						double x,y;
						finput >> x >> y;
						Point a = Point(x,y);
						point.push_back(a);
				}
				struct timeval tv, tv2;
				unsigned long long int start_utime, end_utime;
				if(option == 1){
						gettimeofday(&tv, NULL);
						h.FindConvexHull_bf(point, result);
						gettimeofday(&tv2, NULL);
						start_utime = tv.tv_sec*1000000 + tv.tv_usec;
						end_utime = tv2.tv_sec*1000000 + tv2.tv_usec;
				}
				else if(option == 2){
						gettimeofday(&tv, NULL);
						h.FindConvexHull_jm(point, result);
						gettimeofday(&tv2, NULL);
						start_utime = tv.tv_sec*1000000 + tv.tv_usec;
						end_utime = tv2.tv_sec*1000000 + tv2.tv_usec;
				}
				else
						break;
				cout << "cost time: " << end_utime - start_utime << " us" <<endl;
				internal = h.FindInternalPoint(point,result);
				
				ofstream foutput("Output.txt");
				foutput << internal.size() << endl;
				
				vector<Point> upper;
				vector<Point> lower;
				upper.clear();
				lower.clear();
				for(i=0; i<internal.size(); i++){
						if(internal[i].y >= 0)
								upper.push_back(internal[i]);
						else
								lower.push_back(internal[i]);
				}
				sort(upper.begin(), upper.end(), up_compare);
				sort(lower.begin(), lower.end(), low_compare);
		
				for(i=0; i<upper.size(); i++)
						foutput << upper[i].x << " " << upper[i].y << endl;
				for(i=0; i<lower.size(); i++)
						foutput << lower[i].x << " " << lower[i].y << endl;
				foutput << endl;

				foutput << result.size() << endl;

				Point start_p = FindStartPoint(result);
				upper.clear();
				lower.clear();
				for(i=0; i<result.size(); i++){
						if(result[i] == start_p)
								continue;
						if(result[i].y > start_p.y)
								upper.push_back(result[i]);
						else
								lower.push_back(result[i]);
				}
				sort(upper.begin(), upper.end(), up_compare);
				sort(lower.begin(), lower.end(), low_compare);
				foutput << start_p.x << " " << start_p.y << endl;
				for(i=0; i<upper.size(); i++)
						foutput << upper[i].x << " " << upper[i].y << endl;
				for(i=0; i<lower.size(); i++)
						foutput << lower[i].x << " " << lower[i].y << endl;
		}

		return 0;
}
