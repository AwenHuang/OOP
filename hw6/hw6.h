#include <iostream>
#include <string>
#define pi 3.14159

using namespace std;

class Shape{
		private:
			string color;
		public:
            // constructor
			Shape(const string &p){
					color = p;
			}
			// virtual function
			virtual void print(){
					if(color == "red")
							cout << "\033[1;31mred\033[0m";
					if(color == "yellow")
							cout << "\033[1;33myellow\033[0m";
					if(color == "blue")
							cout << "\033[1;34mblue\033[0m";
					if(color == "green")
							cout << "\033[1;32mgreen\033[0m";
					if(color == "purple")
							cout << "\033[1;35mpurple\033[0m";
					if(color == "white")
							cout << "\033[1;37mwhite\033[0m";
			}
			// pure virtual function
			virtual double get_area() = 0;
};

class Circle : public Shape{
		public:
			int radius;
		public:
			// constructor color pass by Shape class
			Circle(string &p,int r) : Shape(p), radius(r){
			}
			void print(){
					this->Shape::print(); // print color
					cout << " circle, radius " << radius << ", area " << get_area();
			}
			double get_area(){
					double a;
					a = (double)pi*radius*radius;
					return a;
			}
};

class Rectangle : public Shape{
		private:
			int height;
			int width;
		public:
			Rectangle(string &p,int h,int w) : Shape(p),height(h),width(w){
			}
			void print(){
					this->Shape::print();
					cout << " rectangle, height " << height << ", width " << width << ", area " << get_area();
			}
			double get_area(){
					double a;
					a = (double)height*width;
					return a;
			}
};

class Triangle : public Shape{
		private:
			int height;
			int base;
		public:
			Triangle(string &p,int h,int b) : Shape(p),height(h),base(b){
			}
			void print(){
					this->Shape::print();
					cout << " triangle, height " << height << ", base " << base << ", area " << get_area();
			}
			double get_area(){
					double a;
					a = (double)(base*height)/2;
					return a;
			}
};
