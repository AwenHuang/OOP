import java.io.*;
import java.util.Scanner;
public class Avg {
		public static void main(String args[]) {
				String amtStr;
				int number;
				
				double num,tot;
				float average;
				java.util.Scanner sc = new java.util.Scanner(System.in); // 存取各種類型的輸入
				do
				{
						tot = 0;
						number = 0;

						System.out.println("Plese enter the number set.");
						do
						{
								System.out.println("Enter a number?(0~100)(y/n),if not,program will print the average");
								char opt = (char) sc.next().charAt(0); 
								if(opt == 'y')
								{
										System.out.print("Please enter a number:");
										amtStr = sc.next();
									    // try to convert amt String to double for calculation
										try {
												num = new Double(amtStr).doubleValue();
										}
										catch (NumberFormatException e) {
												System.out.println("Bad numeric input; 1st num set to 100");
												num = 100; }
										if(num < (0) || num > (100))
										{
												System.out.println("Error!Please enter again(0~100)");
												System.out.print("Please enter a number:");
												amtStr = sc.next();
												try{
														num = new Double(amtStr).doubleValue();
												}
												catch(NumberFormatException e) {
														System.out.println("Bad numeric input; 1st num set to 100");
														num = 100; }
												continue;
										}
										tot = tot + num;
										number = number + 1;
								}
								else if(opt == 'n')
								{
										if(number > 0)
										{
												average = (float)tot/number;
												System.out.println("The average is:" +average);
										}
										else if (number == 0)
										{
												System.out.println("There has no number to calculated,please input again.");
										}
										break;
								}
								else 
								{
										System.out.println("You can just enter y or n!Program will restart!");
										break;
								}

						}while(number>=0);
				}while(tot>=0);

		} // end main
} // end of class Add
