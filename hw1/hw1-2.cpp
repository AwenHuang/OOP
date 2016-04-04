#include <iostream>
using namespace std;

int main()
{
		char opt;
		int number;     // The number of scores read.
		int sum;        // The summation of all the scores read.
		int grade;      // Holds each individual score as it is read from the keyboard.
		float average;  // Holds the computed average

		while(number >= 0) {
				number = 0;
				sum = 0;
				cout << "Please input a number set." << endl;
				while(1)
				{
						cout << "Input a number(0~100)?(y/n),if not,program will print the average." << endl;
						cin >> opt;
						if(opt == 'y')
						{
								cout << "Please input a number:";
								cin >> grade;
								if(grade < (0) || grade > (100)) // if wrong number,input again
								{
										cout << "Please input a number again!(0~100)" << endl;
										cout << "Please input a number:";
										cin >> grade;
										continue;
								}
								sum = sum + grade;     // Add new score into sum
								number = number + 1;   // and count one more grade
						}
						else if(opt == 'n')
						{
								if(number == 0) // no number
								{
										cout << "There has no number to calculated,please input again." << endl << endl;
										break;
								}
								cout << "The average is ";
								average = (float)sum/number;
								cout << average << endl << endl;
								break;
						}
						else
						{
								cout << "Error!You can just input y or n!Program will restart!" << endl;
								break;
						}
				}
		}

		// When done reading scores, compute average and display.
		// When done,exit the program.
		return 0;
}
