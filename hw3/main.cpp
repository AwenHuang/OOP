#include "hw3.h"
#include <iostream>
#include <cmath>
using namespace std;

bool isfinite(double arg); // 判斷是否超過範圍
void printline(double m,double b);

int main(){
	double slope,y_inter,shift,radius,set_x,set_y;
	int comd_1,comd_2;
	while(1){
			cout << "1.Line\n2.Line2\n3.Circle\n4.Circle2\n5.Exit\nPlease enter command: ";
			cin >> comd_1;
			if(comd_1 == 1){
					cout << "Enter a line (4 doubles): ";
    				Line x;
    				cin >> x;
    				cout << "Input line is:" << x <<endl;
    		
    				slope = x.slope();
    				y_inter = x.y_intercept();
    			
    				printline(slope,y_inter);
    				while(1){
    						cout << "1.slope\n2.y_intercept\n3.vshift\n4.back\nPlease enter command: ";
    						cin >> comd_2;
    						if(comd_2 == 1){
									if(isinf(slope) == true)//no slope
											cout << "slope does not exit!" << endl << endl;
									
									else
											cout << "slope of line is: " << slope << endl << endl;
							}
							else if(comd_2 == 2){
									y_inter = x.y_intercept(); // 因為呼叫vshit後可能會改變y截距,所以再呼叫一次
									if(y_inter == (-1))
											cout << "y_intercept does not exit!" << endl << endl;
									else
											cout << "y_intercept of line is: " << y_inter << endl << endl;
							}
							else if(comd_2 == 3){
									cout << "Enter a number you want to shift(double): ";
									cin >> shift;
									x.vshift(shift);
							}
							else if(comd_2 == 4)
									break;
							continue;
					}
			}
			else if(comd_1 == 2){
					cout << "Enter a line2 (4 doubles): ";
					Line2 y;
					cin >> y;
					cout << "Input line2 is: " << y << endl;
					y.printline2();
					while(1){
							cout << "1.normal\n2.back\nPlease enter a command: ";
							cin >> comd_2;
					
							if(comd_2 == 1){
									cout << "Normal line of line2 is: ";
									y.normal();
							}
							else if(comd_2 == 2)
									break;
							continue;
					}
			}
			else if(comd_1 == 3){
					cout << "Enter a circle (3 doubles): ";
					Circle p;
					cin >> p;
					cout << "Input circle is: " << p << endl;
					while(1){
							cout << "1.radius\n2.set_center\n3.is_inside\n4.back\nPlease enter a command: ";
							cin >> comd_2;

							if(comd_2 == 1){
									cout << "radius of circle is: ";
									radius = p.radius();
									cout << radius << endl;
							}
							else if(comd_2 == 2){
									cout << "Enter a new center (2 doubles): ";
									cin >> set_x >> set_y;
									p.set_center(set_x,set_y);
									cout << "Input circle is: " << p << endl;
							}
							else if(comd_2 == 3){
									cout << "Enter a point (2 doubles): ";
									cin >> set_x >> set_y;
									p.is_inside(set_x,set_y);
							}
							else if(comd_2 == 4)
									break;
							continue;
					}
			}
			else if(comd_1 == 4){

					cout << "Enter a circle (4 doubles): ";
					Circle2 q;
					cin >> q;
					cout << "Inpur circle is: " << q << endl;
					while(1){
							cout << "1.is_inside\n2.back\nPlease enter a command: ";
							cin >> comd_2;
							if(comd_2 == 1){
									cout << "Enter a point (2 doubles): ";
									cin >> set_x >> set_y;
									q.is_inside(set_x,set_y);
							}
							else if(comd_2 == 2)
									break;
							continue;
					}

			}
			else if(comd_1 == 5)
					exit(1);
	}
    
}
void printline(double m,double b){
		if(isinf(m) == false && m!=0 && b!=0) // has slope
			cout << "y = " << m << "x + " << b << endl;
		else if(b == 0)
			cout << "y = " << m << "x" << endl;
}


