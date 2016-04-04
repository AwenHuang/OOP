#include <iostream>
#include <vector>
#include "hw6.h"
using namespace std;

int main(){
		// STL vector of pointer
		vector<Shape *> object;
		// string type color array
		string color_type[] = {"red","yellow","blue","purple","green","white"};

		Circle *c_1 = new Circle(color_type[0], 5);
		object.push_back(c_1);
		
		Rectangle *r_1 = new Rectangle(color_type[1], 7, 9);
		object.push_back(r_1);
		
		Triangle *t_1 = new Triangle(color_type[2], 10 , 12);
		object.push_back(t_1);

		Circle *c_2 = new Circle(color_type[3], 6);
		object.push_back(c_2);

		Rectangle *r_2 = new Rectangle(color_type[4], 11, 13);
		object.push_back(r_2);

		Triangle *t_2 = new Triangle(color_type[5], 14, 16);
		object.push_back(t_2);

		cout << "Printing all shapes...\n" << endl;
		for(vector<Shape *>::iterator it = object.begin(); it != object.end(); it++){
				(*it)->print();
				cout << endl;
		}
		cout << endl;

		cout << "Printing only circles...\n" << endl;
		for(vector<Shape *>::iterator it = object.begin(); it != object.end(); it++){
				if(Circle *C = dynamic_cast<Circle *>(*it)){
						C->print();
						cout << endl;
				}
		}
		
		// delete each object
		for(vector<Shape *>::iterator it = object.begin(); it != object.end(); it++)
				delete *it;
		object.clear();
		return 0;
}
