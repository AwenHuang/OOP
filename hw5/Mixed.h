#include <iostream>
using namespace std;
class Mixed{
		public:
			Mixed(int,int,int);
			Mixed(int);
			double Evaluate();
			void ToFraction();
			void Simplify();
			const int get_x()const;
			const int get_y()const;
			const int get_z()const;
			const int get_com()const;

			bool operator>(Mixed&);
			bool operator<(Mixed&);

			bool operator>=(Mixed&);
			bool operator<=(Mixed&);
			
			bool operator==(Mixed&);
			bool operator!=(Mixed&);

			Mixed operator+(Mixed&);
			Mixed operator-(Mixed&);
			Mixed operator*(Mixed&);
			Mixed operator/(Mixed&);

			Mixed operator++(int);
			Mixed operator--(int);

			Mixed & operator++();
			Mixed & operator--();

			friend istream &operator>>(istream &is, Mixed &l);
			friend ostream &operator<<(ostream &os, const Mixed &l);

			private:
				int a;
				int b;
				int c;
				int com;
};
